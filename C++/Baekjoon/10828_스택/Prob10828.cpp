#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    public:
    void push(int n)
    {
        arr[cnt++] = n;
    }

    void top()
    {
        if(cnt != 0)
        {
            cout << arr[cnt - 1] <<"\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    
    void size()
    {
        cout << cnt << "\n";
    }

    void empty()
    {
        if(cnt != 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
    }

    void pop()
    {
        if(cnt != 0)
        {
            this->top();
            cnt--;
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    private:
    int arr[10001];
    int cnt = 0;
};

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    Stack stack;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> str;
        if(str == "push")
        {
            int num;
            cin >> num;
            stack.push(num);
        }
        if(str == "pop")
        {
            stack.pop();
        }
        if(str == "size")
        {
            stack.size();
        }
        if(str == "top")
        {
            stack.top();
        }
        if(str == "empty")
        {
            stack.empty();
        }
    }
}