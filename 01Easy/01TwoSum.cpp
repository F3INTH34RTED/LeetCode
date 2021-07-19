#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using namespace std::chrono;

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> indices;
    unordered_map<int, int> indicesMap;
    for (int i = 0; i < nums.size(); ++i)
    {
        unordered_map<int, int>::const_iterator iter = indicesMap.find(target - nums[i]);
        if (iter != indicesMap.end())
        {
            indices.push_back(iter->second); // iter->second means the key whereas first implies the value
            indices.push_back(i);
            return indices;
        }
        indicesMap[nums[i]] = i;
    }
    return indices;
}

int main()
{
    vector<int> nums = {15, 11, 7, 2};
    
    auto start = high_resolution_clock::now();
    vector<int> output = twoSum(nums, 26);
    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(end - start);
    
    if (output.empty()) cout << "No indices found!\n";
    else for (int x : output) cout << x << '\n';

    cout << "Time taken: " << duration.count() << "ms" << endl;
    return 0;
}

/*
LOGIC:
Let array be {15, 11, 7, 2}
Hash map {(0,0)}
-------------------------------
1. i = 0   nums[i] = 15
    iter = find(9 - 15 = -6)    -6 doesnt exist in hash map and hence iter = end;
    if (end != end) false
    hash map[15] = 0        HM: {(15,0)}
2. i = 11
    iter = find(9 - 11 = -2)    -2 doesnt exist in hash map and hence iter = end;
    if (end != end) false
    hash map[11] = 1        HM {(15,0), (11,1)}
3. i = 7
    iter = find(9 - 7 = 2)    2 doesnt exist in hash map and hence iter = end;
    if (end != end) false
    hash map[7] = 2        HM {(15,0), (11,1), (7,2)}
3. i = 2
    iter = find(9 - 2 = 7)    7 exists in the hash map at hash map[index = 3] and hence iter = 7
    if (7 != end) true
    indices = {2, 3}
    return indices
*/
