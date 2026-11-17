#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

class Stack
{
    Node* top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(char x)
    {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (top == NULL)
            return '\0';

        Node* temp = top;
        char x = temp->data;
        top = top->next;
        delete temp;
        return x;
    }

    char peek()
    {
        if (top == NULL)
            return '\0';
        return top->data;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main()
{
    Stack s;
    string infix, prefix = "", temp = "";

    cout << "Enter infix expression: ";
    cin >> infix;

    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            temp += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
                temp += s.pop();

            s.pop();
        }
        else
        {
            while (!s.isEmpty() &&
                   precedence(s.peek()) > precedence(ch))
            {
                temp += s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.isEmpty())
        temp += s.pop();

    reverse(temp.begin(), temp.end());

    prefix = temp;

    cout << "Prefix expression: " << prefix;

    return 0;
}
