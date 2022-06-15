// 13. Roman to Integer
#include <iostream>
#include <vector>
using namespace std;

// 48ms, 9.6MB.. 효율 안좋음 내코드
/*
class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> vec;
        int n;

        if (x < 0) return false;

        while (x > 0)
        {
            vec.push_back(x % 10);
            x /= 10;
        }

        int size = vec.size();
        for (int i = 0; i < size / 2; i++)
        {
            if (vec[i] != vec[(size - 1) - i])
            {
                return false;
            }
        }

        return true;
    }
};
*/

// 35ms, 4.9MB 원래 더 빠르다고 나오는데 컴퓨터문제인지 모르겠음. 남의 코드
/*
class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        long rem, rev = 0;
        while (x > 0) {
            rem = x % 10;
            rev = rev * 10 + rem;
            x /= 10;
        }
        if (num == rev)
            return true;
        else
            return false;

    }
};
*/

//15ms, 5.9MB 위 코드 보고 따라한 코드
class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        long rev = 0, back;
        if (x < 0) return false;

        // 수를 거꾸로 만드는 과정
        while (x > 0)
        {
            back = x % 10;
            rev = rev * 10 + back;
            x /= 10;
        }
        
        if (rev == n) return true;
        else return false;
    }
};