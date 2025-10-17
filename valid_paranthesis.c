#include <stdio.h>
#include <string.h>

int isValid(char *s) {
    char stack[100];
    int top = -1;

    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1) return 0;
            char topChar = stack[top--];
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '['))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    char s[100];
    printf("Enter parentheses string: ");
    scanf("%s", s);

    if (isValid(s))
        printf("Valid\n");
    else
        printf("Invalid\n");
    return 0;
}
