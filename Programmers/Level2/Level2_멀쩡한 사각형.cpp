#include <iostream>
using namespace std;

long long gcd(int a, int b)
{
    long long c;
    long long tmp = a % b;

    while (tmp > 0)
    {
        a = b;
        b = tmp;
        tmp = a % b;
    }

    return b;
}

long long solution(int w, int h) {
    long long answer = 1;
    long long sum = (long long)w * (long long)h;
    long long g = gcd(w, h);
    g = w + h - g;

    answer = sum - g;

    return answer;
}