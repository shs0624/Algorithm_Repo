#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 75ms, 0.03MB - 다른 사람 코드.
//class Solution {
//public:
//    bool containsDuplicate(vector<int>& nums) {
//        ios_base::sync_with_stdio(false);
//        cin.tie(NULL);
//        cout.tie(NULL);
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size() - 1; i++) {
//            if (nums[i] == nums[i + 1])
//                return true;
//        }
//        return false;
//    }
//};

// 116ms (faster than 63.24%), 46.7MB (less than 77.11%) - 내 코드
// 굳이 temp에 저장할 필요가 없는듯
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int temp;

        if (nums.size() <= 1) return false;

        sort(nums.begin(), nums.end());
        temp = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (temp == nums[i]) return true;
            temp = nums[i];
        }

        return false;
    }
};

int main()
{
    Solution s;
    std::cout << "Hello World!\n";
}
