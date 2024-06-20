#include <iostream>
#include <string>
#include <map>
using namespace std;

float cnt = 0;
map<string, int> m_Map;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while(getline(cin, str))
    {
        cnt++;
        if(m_Map.find(str) != m_Map.end())
        {
            m_Map[str] += 1;
        }
        else
        {
            m_Map.insert({str, 1});
        }
    }

    cout << fixed;
    cout.precision(4);
    for(auto it = m_Map.begin(); it != m_Map.end(); it++)
    {
        float result = ((it->second) / cnt) * 100;
        cout << it->first << " " << result << "\n";
    }
}