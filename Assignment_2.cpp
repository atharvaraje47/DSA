#include <iostream>
#include <string>
using namespace std;
// Node structure for Singly Linked List Stack
struct Node {
   char data;
   Node *next;
};
// Stack ADT implemented using Singly Linked List
class Stack {
private:
   Node *top;
public:
   Stack() { top = NULL; }
   bool isEmpty() { return (top == NULL); }
   // Push character onto top of stack
   void push(char val) {
       Node *newNode = new Node;
       newNode->data = val;
       newNode->next = top;
       top = newNode;
   }
   // Pop character from top of stack
   char pop() {
       if (isEmpty()) return '\0';
       Node *temp = top;
       char poppedVal = temp->data;
       top = top->next;
       delete temp;
       return poppedVal;
   }
   // Return top element of stack without removing it
   char peek() {
       if (isEmpty()) return '\0';
       return top->data;
   }

};
// Check if character is an operand (alphabet or digit)
bool isOperand(char c) {
   if (c >= 'a' && c <= 'z') return true;
   if (c >= 'A' && c <= 'Z') return true;
   if (c >= '0' && c <= '9') return true;
   return false;
}
// Return precedence of arithmetic operators
int precedence(char op) {
   if (op == '^') return 3;
   if (op == '*' || op == '/') return 2;
   if (op == '+' || op == '-') return 1;
   return -1;
}
// Convert Infix expression to Postfix using Stack ADT
string infixToPostfix(string infix) {
   Stack st;
   string postfix = "";
   for (int i = 0; i < infix.length(); i++) {
       char c = infix[i];
       if (isOperand(c)) postfix += c;
       else if (c == '(') st.push(c);
       else if (c == ')') {
           while (!st.isEmpty() && st.peek() != '(')
               postfix += st.pop();
           st.pop();
       }
       else {
           while (!st.isEmpty() && precedence(st.peek()) >= 
precedence(c)) {
               postfix += st.pop();
           }
           st.push(c);
       }
   }
   while (!st.isEmpty()) {
       postfix += st.pop();

   }
   return postfix;
}
// Helper function to reverse a string
string reverseString(string str) {
   string rev = "";
   for (int i = str.length() - 1; i >= 0; i--) {
       rev += str[i];
   }
   return rev;
}
// Convert Infix expression to Prefix using Stack ADT
string infixToPrefix(string infix) {
   string revInfix = reverseString(infix);
   for (int i = 0; i < revInfix.length(); i++) {
       if (revInfix[i] == '(') revInfix[i] = ')';
       else if (revInfix[i] == ')') revInfix[i] = '(';
   }
   string postfix = infixToPostfix(revInfix);
   string prefix = reverseString(postfix);
   return prefix;
}
int main() {
   string exp1 = "(A+B)*(C-D)";
   cout << "Expression 1:" << endl;
   cout << "Infix   : " << exp1 << endl;
   cout << "Postfix : " << infixToPostfix(exp1) << endl;
   cout << "Prefix  : " << infixToPrefix(exp1) << endl;
   string exp2 = "A+B*C-D/E";
   cout << "\nExpression 2:" << endl;
   cout << "Infix   : " << exp2 << endl;
   cout << "Postfix : " << infixToPostfix(exp2) << endl;
   cout << "Prefix  : " << infixToPrefix(exp2) << endl;
   return 0;
}
