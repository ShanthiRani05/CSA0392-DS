#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    char items[MAX_STACK_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char item) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->items[++(stack->top)] = item;
    } else {
        printf("Stack overflow!\n");
    }
}

char pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->items[(stack->top)--];
    } else {
        return '\0'; 
    }
}

bool isValidStack(char *sequence) {
    Stack stack;
    initialize(&stack);

    int length = strlen(sequence);
    for (int i = 0; i < length; i++) {
        if (sequence[i] == '(') {
            push(&stack, '(');
        } else if (sequence[i] == ')') {
            if (pop(&stack) != '(') {
                return false;
            }
        }
    }

    return stack.top == -1; 
}

int main() {
    char sequence[MAX_STACK_SIZE];
    printf("Enter a sequence of elements: ");
    scanf("%s", sequence);

    if (isValidStack(sequence)) {
        printf("The stack configuration is valid.\n");
    } else {
        printf("The stack configuration is not valid.\n");
    }

    return 0;
}

