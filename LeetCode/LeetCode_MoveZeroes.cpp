#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 양 끝 포인트 이용하는 방식 24ms, 19.2MB로 제일 빠르고 메모리도 적음
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int size = nums.size();
        int start = 0, end = 1;
        while (end < size)
        {
            if (nums[start] == 0)
            {
                //왼쪽이 0이면, 오른쪽으로 가며 0이 아닌 수를 찾아서 위치를 교환.
                while (nums[end] == 0 && end < size - 1)
                {
                    end++;
                }
                int temp = nums[end];
                nums[end] = nums[start];
                nums[start] = temp;
            }
            start++;
            end++;
        }
    }
};

//57ms, 19.4 MB 다른 사람 코드
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums)
//    {
//        int temp = 0;
//
//        if (nums.size() != 1)
//        {
//            // 0의 개수를 확인하고, 0이 아닌 수를 발견된 0 개수만큼 앞으로 땡김
//            for (int i = 0; i < nums.size(); i++)
//            {
//                if (nums[i] == 0)
//                {
//                    temp++;
//                }
//                else
//                {
//                    nums[i - temp] = nums[i];
//                }
//            }
//            // 0의 개수만큼 nums뒤부분을 0으로 바꿈.
//            for (int j = nums.size() - temp; j < nums.size(); j++)
//            {
//                nums[j] = 0;
//            }
//        }
//    }
//};

// 207ms, 19.2 MB 메모리는 적게쓰지만, 속도가 매우느림
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        int size = nums.size();
//        for (int i = 0; i < size; i++)
//        {
//            if (nums[i] == 0)
//            {
//                nums.push_back(nums[i]);
//                nums.erase(nums.begin() + i);
//
//                size--;
//                i--;
//            }
//        }
//    }
//};

int main()
{
    Solution s;
}
