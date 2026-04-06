#include <stdio.h>
#include <string.h>
#define MAX 100
int main() {
    char str[MAX], stack[MAX];
    int top = -1, i;
    printf("Enter a string: ");
    scanf("%s", &str);
    // Push each character in to stack
    for(i = 0; str[i] != '\0'; i++) {
        top++;
        stack[top] = str[i];
    }
    // Pop characters from stack to reverse string
    printf("Reversed string: ");
    while(top != -1) {
        printf("%c", stack[top]);
        top--;
    }
    printf("\n");
    return 0;
}