#include <stdio.h>

int trap(int a[], int n)
{
    int i = 0, j = n - 1;
    int leftMax = a[0], rightMax = a[n - 1];
    int water = 0;

    while (i < j)
    {
        if (leftMax < rightMax)
        {
            i++;

            if (a[i] > leftMax)
                leftMax = a[i];
            else
                water += leftMax - a[i];
        }
        else
        {
            j--;

            if (a[j] > rightMax)
                rightMax = a[j];
            else
                water += rightMax - a[j];
        }
    }

    return water;
}

int main()
{
    int a[] = {3, 0, 2, 0, 4};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Trapped Water: %d\n", trap(a, n));

    return 0;
}
