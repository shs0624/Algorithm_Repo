#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

vector<string> split(string s, string div)
{
    vector<string> str;
    char* c = strtok((char*)s.c_str(), div.c_str());
    while (c)
    {
        str.push_back(c);
        c = strtok(NULL, div.c_str());
    }
    return str;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> str;
    map<string, string> m;

    for (int i = 0; i < record.size(); i++)
    {
        str.clear();
        str = split(record[i], " ");
        if (str[0] != "Leave")
        {
            m[str[1]] = str[2];
        }
    }

    for (int i = 0; i < record.size(); i++)
    {
        str.clear();
        str = split(record[i], " ");
        if (str[0] == "Enter")
        {
            answer.push_back(m[str[1]] + "님이 들어왔습니다.");
        }
        else if (str[0] == "Leave")
        {
            answer.push_back(m[str[1]] + "님이 나갔습니다.");
        }
    }

    return answer;
}