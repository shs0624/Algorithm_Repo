#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//https://yabmoons.tistory.com/132 풀이 봄
int N, answer, cnt;
int alpha[26];
int arr[11];
vector<string> v;
vector<char> chars;

bool cmp(int a, int b)
{
    if (a > b) return true;
    return false;
}

void Solution()
{
    for (int i = 0; i < N; i++)
    {
        string s = v[i];
        int l = s.length();
        int dec = 1;

        for (int j = l - 1; j >= 0; j--)
        {
            int num = s[j] - 'A';
            alpha[num] = alpha[num] + dec;
            dec *= 10;
        }
    }
    sort(alpha, alpha + 26, cmp);

    answer = 0;
    cnt = 9;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] == 0) break;
        answer += alpha[i] * cnt;
        cnt--;
    }

    cout << answer << endl;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    Solution();
}
