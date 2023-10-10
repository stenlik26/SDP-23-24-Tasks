#include <iostream>
#include <stack>
#include <string>
using namespace std;

char get_opened(char closed)
{
    if (closed == '}')
        return '{';
    if (closed == ')')
        return '(';
    if (closed == ']')
        return '[';
}

bool is_balanced(string input)
{
    stack<char> brackets;

    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{') 
        {
            brackets.push(input[i]);
            continue;
        }

        if (brackets.empty())
            return false;

        if (brackets.top() == get_opened(input[i]))
            brackets.pop();
        else
            return false;
    }
    return true;
}

int main()
{
    string input;

    cin >> input;

    cout << (is_balanced(input) ? "Yes" : "No") << std::endl;
}
