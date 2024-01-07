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
        return std::max(total - globalMin,globalMax);
    }
}
int main()
{
    std::vector<int> nums{ 5, -3, 5 };
    std::cout << maxSubarraySumCircular(nums);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
