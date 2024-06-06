#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = s.length();

    for (int i = 1; i <= s.length() / 2; i++)
    {
        int count = 1;
        string f = s.substr(0, i);
        string cmp, tmp;

        for (int j = i; j < s.length(); j += i)
        {
            cmp = s.substr(j, i);

            if (!(f.compare(cmp)))
                count++;
            else
            {
                if (count == 1)
                {
                    tmp += f;
                    f = cmp;
                }
                else
                {
                    tmp = tmp + to_string(count) + f;
                    f = cmp;
                    count = 1;
                }
            }

            if (j + i >= s.length())
            {
                if (count != 1)
                {
                    tmp = tmp + to_string(count) + f;
                    break;
                }
                else
                {
                    tmp = tmp + s.substr(j);
                    break;
                }
            }
        }
        answer = (answer > tmp.length()) ? tmp.length() : answer;
    }
    return answer;
}