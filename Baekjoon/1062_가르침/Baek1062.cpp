#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K, answer = 0;
bool Edu[26];
string strArr[51];
string Essential = "antic";

//a,n,t,i,c는 필수.

void Init()
{
    answer = 0;

    for (int i = 0; i < 5; i++)
    {
        Edu[Essential[i] - 97] = true;
    }

    for (int i = 0; i < N; i++)
    {
        string str = "";
        for (int j = 4; j < strArr[i].size() - 4; j++)
        {
            str += strArr[i][j];
        }
        strArr[i] = str;
    }
}

void Read()
{
    int result = 0;

    for (int i = 0; i < N; i++)
    {
        bool possible = true;
        for (int j = 0; j < strArr[i].size(); j++)
        {
            if (!Edu[strArr[i][j] - 97])
            {
                possible = false;
                break;
            }
        }

        if (possible) result++;
    }

    answer = max(answer, result);
}

void Learning(int idx, int cnt)
{
    if (cnt == K)
    {
        Read();
        return;
    }
    else
    {
        for (int i = idx; i < 26; i++)
        {
            if (!Edu[i])
            {
                Edu[i] = true;
                Learning(i, cnt + 1);
                Edu[i] = false;
            }
        }
    }
}

void Solution()
{
    if (K < 5)
    {
        cout << 0 << endl;
        return;
    }

    K -= 5;

    Init();

    Learning(0, 0);

    cout << answer << endl;
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> strArr[i];
    }
    Solution();
}
