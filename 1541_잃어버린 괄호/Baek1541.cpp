#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> v;
string s,num;

void Solution()
{
    int result = 0;
    num.clear();
    char temp = '+';
    for (int i = 0; i < v.size(); i++)
    {
        if (i == v.size() - 1)
        {
            if (v[i] == '-' || v[i] == '+')
            {
                if (temp == '-')
                    result -= stoi(num);
                else
                    result += stoi(num);
            }
            else
            {
                num += v[i];

                if (temp == '-')
                    result -= stoi(num);
                else
                    result += stoi(num);
            }
        }
        if (v[i] == '-' || v[i] == '+')
        {
            if (temp == '-')
                result -= stoi(num);
            else
                result += stoi(num);

            num.clear();

            if (v[i] == '-') temp = '-';
        }
        else
        {
            num += v[i];
        }
    }
    cout << result << endl;
}

int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s[i]);
    }
    Solution();
}
