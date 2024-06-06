#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 수정했지만, 38ms , 16.7MB
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = -1;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
            else
            {
                ans = nums[i];
                break;
            }
        }

        return ans;
    }
};

// 38ms, 17MB -> 내 코드 에바
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size(); i += 2)
//        {
//            if (i + 1 >= nums.size())
//            {
//                return nums[i];
//            }
//            
//            if (nums[i] == nums[i + 1])
//            {
//                continue;
//            }
//            else
//            {
//                return nums[i];
//            }
//        }
//        return 0;
//    }
//};

// ^연산자 사용하기 -> 12ms, 3.6MB
// A ^ 0 = A , A ^ A = 0
// A ^ B ^ A = A ^ A ^ B = 0 ^ B = B -> 교환법칙 성립
// https://beccacatcheserrors.tistory.com/11 이해가 힘들어서 찾아봄
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int ans = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            ans ^= nums[i];
//        }
//        return ans;
//    }
//};

int main()
{
    Solution s;
    vector<int> nums = { 4,1,2,1,2 };
    int n = s.singleNumber(nums);
    cout << n << endl;
}