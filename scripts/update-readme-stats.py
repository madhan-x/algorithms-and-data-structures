#!/usr/bin/env python3
"""Regenerate the dynamic sections of README.md from the repo filesystem.

Run this manually after adding files, or let the pre-commit hook run it for
you. It rewrites only the fenced blocks delimited by
`<!-- AUTO-STATS:START -->` / `<!-- AUTO-STATS:END -->` and
`<!-- AUTO-LEETCODE:START -->` / `<!-- AUTO-LEETCODE:END -->`.

Sections that are hand-curated (Topics Covered bullet list, Patterns table,
Roadmap) are left untouched.
"""

from __future__ import annotations

import re
import sys
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
README = ROOT / "README.md"
LEETCODE = ROOT / "leetcode"

TOPIC_DIRS = [
    "arrays", "linked-list", "trees", "stack", "queue",
    "recursion", "two-pointers", "basics", "sorting", "maths",
]

DIFFICULTY_MAP = {
    "01_easy": ("Easy", "easy"),
    "02_medium": ("Medium", "medium"),
    "03_hard": ("Hard", "hard"),
}


def count_files() -> dict:
    """Return totals and per-topic file counts.

    Excludes build artifacts, .git, and anything in practice/archive so the
    numbers reflect what a visitor actually sees in the topic folders.
    """
    skip_dirs = {".git", "practice", "archive", "scripts", ".github", ".vscode", "node_modules"}
    cpp_total = 0
    c_total = 0
    per_topic: dict[str, int] = {t: 0 for t in TOPIC_DIRS}

    for path in ROOT.rglob("*"):
        if not path.is_file():
            continue
        if any(part in skip_dirs for part in path.relative_to(ROOT).parts):
            continue
        if path.suffix == ".cpp":
            cpp_total += 1
        elif path.suffix == ".c":
            c_total += 1

    for topic in TOPIC_DIRS:
        per_topic[topic] = sum(
            1 for _ in (ROOT / topic).rglob("*.cpp")
        ) + sum(
            1 for _ in (ROOT / topic).rglob("*.c")
        )

    return {
        "cpp": cpp_total,
        "c": c_total,
        "total": cpp_total + c_total,
        "per_topic": per_topic,
    }


def count_leetcode() -> dict:
    """Walk leetcode/<topic>/<difficulty>/ and group by subtopic + difficulty."""
    easy = medium = hard = 0
    by_subtopic: dict[str, dict[str, list[str]]] = {}

    if not LEETCODE.exists():
        return {"total": 0, "easy": 0, "medium": 0, "hard": 0, "by_subtopic": {}}

    for topic_dir in sorted(p for p in LEETCODE.iterdir() if p.is_dir()):
        for diff_dir in topic_dir.iterdir():
            if not diff_dir.is_dir():
                continue
            key = DIFFICULTY_MAP.get(diff_dir.name)
            if not key:
                continue
            label, slug = key
            files = sorted(p.name for p in diff_dir.glob("*.cpp"))
            if not files:
                continue
            by_subtopic.setdefault(topic_dir.name, {}).setdefault(slug, []).extend(
                f"`{f}`" for f in files
            )
            if slug == "easy":
                easy += len(files)
            elif slug == "medium":
                medium += len(files)
            else:
                hard += len(files)

    return {
        "total": easy + medium + hard,
        "easy": easy,
        "medium": medium,
        "hard": hard,
        "by_subtopic": by_subtopic,
    }


def render_stats(stats: dict, lc: dict) -> str:
    lines = [
        "| Metric              |  Count |",
        "|---------------------|-------:|",
        f"| Total solutions     | {stats['total']:>5} |",
        f"| C++ implementations | {stats['cpp']:>5} |",
        f"| C implementations   | {stats['c']:>5} |",
        "",
        "**Solutions by topic**",
        "",
        "| Topic          | Files |",
        "|----------------|------:|",
    ]
    for topic in TOPIC_DIRS:
        display = topic.replace("-", " ").title()
        lines.append(f"| {display:<14} | {stats['per_topic'][topic]:>5} |")

    lines.extend([
        "",
        f"**LeetCode by difficulty** ({lc['total']} solved on "
        f"[LeetCode profile](https://leetcode.com/u/madhan-x))",
        "",
        "| Difficulty | Count |",
        "|------------|------:|",
        f"| Easy       | {lc['easy']:>5} |",
        f"| Medium     | {lc['medium']:>5} |",
        f"| Hard       | {lc['hard']:>5} |",
    ])
    return "\n".join(lines)


def render_leetcode(lc: dict) -> str:
    if not lc["by_subtopic"]:
        return "_No LeetCode solutions yet._"

    out = []
    subtopic_titles = {
        "arrays": "Arrays",
        "linked-list": "Linked List",
        "maths": "Maths",
        "stack": "Stack",
        "strings": "Strings",
    }

    for subtopic, by_diff in lc["by_subtopic"].items():
        title = subtopic_titles.get(subtopic, subtopic.title())
        out.append(f"### {title}")
        out.append("")
        for slug in ("easy", "medium", "hard"):
            files = by_diff.get(slug, [])
            if not files:
                continue
            label = {"easy": "Easy", "medium": "Medium", "hard": "Hard"}[slug]
            out.append(f"**{label} ({len(files)})**")
            out.append("- " + " · ".join(files))
            out.append("")

    return "\n".join(out).rstrip()


def replace_block(content: str, marker: str, new_body: str) -> str:
    pattern = re.compile(
        rf"<!-- {marker}:START -->\n.*?<!-- {marker}:END -->",
        re.DOTALL,
    )
    replacement = f"<!-- {marker}:START -->\n{new_body}\n<!-- {marker}:END -->"
    if not pattern.search(content):
        sys.exit(f"ERROR: marker <!-- {marker}:START --> not found in README.md")
    return pattern.sub(replacement, content, count=1)


def ensure_hooks_path() -> None:
    """Best-effort: point git at .githooks/ on first run.

    We use ``git config --local`` so this only affects this repo, never the
    user's global git config. If git isn't available we silently skip — the
    user can run ``git config core.hooksPath .githooks`` themselves.
    """
    try:
        result = subprocess.run(
            ["git", "config", "--local", "core.hooksPath", ".githooks"],
            cwd=ROOT,
            capture_output=True,
            text=True,
            check=False,
        )
        if result.returncode != 0:
            print(
                "Note: couldn't auto-configure git hooksPath.\n"
                "      Run: git config core.hooksPath .githooks",
                file=sys.stderr,
            )
    except FileNotFoundError:
        pass  # git not on PATH; user will set it manually


def main() -> int:
    ensure_hooks_path()
    content = README.read_text(encoding="utf-8")
    stats = count_files()
    lc = count_leetcode()

    content = replace_block(content, "AUTO-STATS", render_stats(stats, lc))
    content = replace_block(content, "AUTO-LEETCODE", render_leetcode(lc))

    README.write_text(content, encoding="utf-8")
    print(
        f"Updated README.md — "
        f"{stats['total']} total solutions, {lc['total']} LeetCode."
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
