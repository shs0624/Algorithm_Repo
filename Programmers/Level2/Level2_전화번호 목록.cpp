#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool solution(vector<string> phone_book)
{
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 1; i < phone_book.size(); i++)
    {
        for (int j = 0; j < phone_book[i - 1].size(); j++)
        {
            if (phone_book[i - 1][j] != phone_book[i][j]) break;
            if (j == phone_book[i - 1].size() - 1) answer = false;
        }

        if (!answer) break;
    }

    return answer;
}