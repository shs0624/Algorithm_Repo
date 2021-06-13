#include <string>
#include <vector>

using namespace std;

string ConvertThree(int n)
{
    int m = n / 3;
    int q = n % 3;

    if (q == 0)
    {
        m -= 1;
        q = 4;
    }

    if (m == 0) return to_string(q);
    else return ConvertThree(m) + to_string(q);
}

string solution(int n) {
    string answer = "";

    answer = ConvertThree(n);

    return answer;
}