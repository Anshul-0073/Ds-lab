#include <stdio.h>
#include <string.h>

#define MAX 1000006

char stack[MAX];
int  top = -1;

void push(char c)  { stack[++top] = c; }
char pop()         { return top == -1 ? '\0' : stack[top--]; }
int  isEmpty()     { return top == -1; }

int isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char* s) {
    top = -1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            push(s[i]);
        else {
            if (isEmpty() || !isMatch(pop(), s[i]))
                return 0;
        }
    }
    return isEmpty();
}

int main() {
    char s[MAX];
    printf("Enter bracket string: ");
    scanf("%s", s);
    printf("Output: %s\n", isBalanced(s) ? "true" : "false");
    return 0;
}
