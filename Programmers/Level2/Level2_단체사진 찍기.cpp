#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    string str = "ACFJMNRT";

    do
    {
        bool flag = true;

        for (int i = 0; i < data.size(); i++)
        {
            char fc = data[i][0];
            char tc = data[i][2];
            char comp = data[i][3];
            int n = data[i][4] - '0';
            int dist = str.find(fc) - str.find(tc);
            dist = abs(dist) - 1;

            switch (comp)
            {
            case '=':
                if (dist != n) flag = false;
                break;
            case '>':
                if (dist <= n) flag = false;
                break;
            case '<':
                if (dist >= n) flag = false;
                break;
            }
            if (!flag) break;
        }
        if (flag) answer++;

    } while (next_permutation(str.begin(), str.end()));

    return answer;
}