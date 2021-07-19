#include <iostream>
#include <vector>

using std::cout;
using std::vector;

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> indices;

    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                indices.push_back(i);
                indices.push_back(j);
                return indices;
            }
        }
    }

    return indices;
}

int main()
{
    vector<int> nums = {15, 11, 7, 2};
    vector<int> output = twoSum(nums, 9);
    if (output.empty()) cout << "No indices found!\n";
    else for (int x : output) cout << x << '\n';
    
    return 0;
}