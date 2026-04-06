#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX], stack[MAX], n;
    int top = -1, i, next;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    stack[++top] = 0;   // store index of first element

    for(i = 1; i < n; i++) {
        while(top != -1 && arr[i] > arr[stack[top]]) {
            printf("%d -> %d\n", arr[stack[top]], arr[i]);
            top--;
        }
        stack[++top] = i;
    }

    while(top != -1) {
        printf("%d -> -1\n", arr[stack[top]]);
        top--;
    }

    return 0;
}