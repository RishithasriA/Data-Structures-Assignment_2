#include <stdio.h>
#include <string.h>
#define MAX 100
int main() {
    char expr[MAX], stack[MAX];
    int top = -1, i;
    printf("Enter an expression: ");
    scanf("%s", expr);
    for(i = 0; expr[i] != '\0'; i++) {
        if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            stack[++top] = expr[i];   // push opening bracket
        }
        else if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if(top == -1) {
                printf("Unbalanced Expression\n");
                return 0;
            }

            char ch = stack[top--];   // pop

            if((expr[i] == ')' && ch != '(') ||
               (expr[i] == '}' && ch != '{') ||
               (expr[i] == ']' && ch != '[')) {
                printf("Unbalanced Expression\n");
                return 0;
            }
        }
    }

    if(top == -1)
        printf("Balanced Expression\n");
    else
        printf("Unbalanced Expression\n");

    return 0;
}