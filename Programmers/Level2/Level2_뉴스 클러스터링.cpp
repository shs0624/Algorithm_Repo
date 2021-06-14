#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0, sum = 0;
    float inter = 0;
    vector<string> v1;
    vector<string> v2;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.size() - 1; i++)
    {
        if (str1[i] >= 'a' && str1[i] <= 'z' && str1[i + 1] >= 'a' && str1[i + 1] <= 'z')
            v1.push_back(str1.substr(i, 2));
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        if (str2[i] >= 'a' && str2[i] <= 'z' && str2[i + 1] >= 'a' && str2[i + 1] <= 'z')
            v2.push_back(str2.substr(i, 2));
    }

    if (v1.size() == 0 && v2.size() == 0) return 65536;
    sum = v1.size() + v2.size();
    for (int i = 0; i < v1.size(); i++)
    {
        auto iter = find(v2.begin(), v2.end(), v1[i]);
        if (iter != v2.end())
        {
            v2.erase(iter);
            inter++;
        }
    }

    answer = (inter / (sum - inter)) * 65536;

    return answer;
}