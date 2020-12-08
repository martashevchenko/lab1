#include <iostream>
using namespace std;

float number()
{
    int res = 0;
    for (;;)
    {
        char c = cin.get();
        if (c >= '0' && c <= '9')
            res = res * 10 + c - '0';
        else
        {
            cin.putback(c);
            return res;
        }
    }
}

float expr();

float duzhky()
{
    char c = cin.get();
    if (c == '(')
    {
        float x = expr();
        cin.get();
        return x;
    }
    else
    {
        cin.putback(c);
        return number();
    }
}

float factor()
{
    float x = duzhky();
    for (;;)
    {
        char c = cin.get();
        switch (c)
        {
            case '*':
                x *= duzhky();
                break;
            case '/':
                x /= duzhky();
                break;
            default:
                cin.putback(c);
                return x;
        }
    }
}

float expr()
{
    float x = factor();
    for (;;)
    {
        char c = cin.get();
        switch (c)
        {
            case '+':
                x += factor();
                break;
            case '-':
                x -= factor();
                break;
            default:
                cin.putback(c);
                return x;
        }
    }
}


int main()
{
    cout << "Enter a vyraz";
    float res = expr();
    cout << "Result: " << res << endl;
}