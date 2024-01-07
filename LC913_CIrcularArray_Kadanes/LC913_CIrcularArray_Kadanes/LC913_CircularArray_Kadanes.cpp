// LC913_CIrcularArray_Kadanes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int maxSubArrayKadane(std::vector<int>& nums) {
    int globalMax = nums[0];
    int currMax = 0;
    for (int i = 0; i < nums.size(); i++) {
        currMax = std::max(nums[i], currMax + nums[i]);
        globalMax = std::max(globalMax, currMax);
    }
    return globalMax;
}


int maxSubarraySumCircular(std::vector<int>& nums) {
    int globalMin = nums[0];
    int globalMax = nums[0];
    int currMax = 0;
    int currMin = 0;
    int total = 0;
    for (int i = 0; i < nums.size(); i++) {
        total += nums[i];
        currMax = std::max(nums[i], currMax + nums[i]);
        globalMax = std::max(currMax, globalMax);
        currMin = std::min(nums[i], currMin + nums[i]);
        globalMin = std::min(currMin, globalMin);
        std::cout << "currMax: " << currMax << " CurrMin: " << currMin << '\n';
        std::cout << globalMax << " " << globalMin << '\n';
    }
    if (globalMax < 0)
        return globalMax;
    else {
        return std::max(total - globalMin, globalMax);
    }

}

int maxLengthTurbulentSubArray(std::vector<int>& nums) {
    int res = 1;
    std::string prev = "";
    int leftptr = 0;
    int rightptr = 1;
    while (rightptr < nums.size())
    {
        if (nums[rightptr - 1] > nums[rightptr] && prev != ">") {
            res = std::max(res, rightptr - leftptr + 1);
            rightptr++;
            prev = ">";
        }
        else if (nums[rightptr - 1] < nums[rightptr] && prev != "<") {
            res = std::max(res, rightptr - leftptr + 1);
            rightptr++;
            prev = ">";
        }
        else
        {
            if (nums[rightptr] == nums[rightptr - 1])
                rightptr++;
            else
                rightptr = rightptr;
            leftptr = rightptr - 1;
            prev = "";

        }
    }
    return res;
}
int main()
{
    std::vector<int> nums{ 5, -3, 5 };
    std::cout << maxSubarraySumCircular(nums);

}

