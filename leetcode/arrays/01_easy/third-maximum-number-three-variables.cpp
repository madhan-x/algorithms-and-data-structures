class Solution
{
public:
    int thirdMax(vector<int>& nums)
    {
        // Store the first, second, and third distinct maximum values
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for(int num : nums)
        {
            // Skip duplicate values
            if(num == first || num == second || num == third)
            {
                continue;
            }

            // Update first, second, and third maximums
            if(num > first)
            {
                third = second;
                second = first;
                first = num;
            }
            else if(num > second)
            {
                third = second;
                second = num;
            }
            else if(num > third)
            {
                third = num;
            }
        }

        // If there are fewer than three distinct numbers,
        // return the maximum element
        if(third == LLONG_MIN)
        {
            return first;
        }

        return third;
    }
};
