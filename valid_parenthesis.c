#include <stdbool.h>

bool isValid(char *s) {
    char stack[10000];
    int top = -1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack[++top] = s[i];
        else if ((s[i] == ')' && (top == -1 || stack[top--] != '(')) ||
                 (s[i] == ']' && (top == -1 || stack[top--] != '[')) ||
                 (s[i] == '}' && (top == -1 || stack[top--] != '{')))
            return false;
    }
    return top == -1;
}
