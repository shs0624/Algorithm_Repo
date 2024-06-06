#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 19ms, 10.8MB 내 코드
vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> arr;//pair
    vector<int> output(2);
    for (int i = 0; i < nums.size(); i++)
        arr.push_back({ nums[i], i });//arr[i] = { nums[i], i };

    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;

    while (1)
    {
        int sum = arr[left].first + arr[right].first;
        if (sum > target)
        {
            right = right - 1;
        }
        else if (sum < target)
        {
            left = left + 1;
        }
        else
        {
            output[0] = arr[left].second;
            output[1] = arr[right].second;
            return output;
        }
    }
}


// 8ms, 5.63MB 다른 사람 코드
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mapNums;//map은 Key를 기준으로 오름차순 정렬.
        vector<int> result;
        int num2;
        int n = nums.size();
        int i;

        for (i = 0; i < n; i++) {
            mapNums.insert({ nums[i], i });
            num2 = target - nums[i];
            //mapNums에 넣고, 넣은 수를 target에서 뺀 값이 map에 있다면 그 수와 넣은 수가 정답.
            if (!(mapNums.find(num2) == mapNums.end()) && mapNums.at(num2) != i) {
                result.push_back(i);
                result.push_back(mapNums.at(num2));
                break;
            }
        }
        return result;
    }
};
*/