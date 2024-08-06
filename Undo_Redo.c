#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Define a structure for the stack node
typedef struct StackNode {
    char* action;
    struct StackNode* next;
} StackNode;
// Define a structure for the stack
typedef struct Stack {
    StackNode* top;
} Stack;
// Function to create an empty stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}
// Function to push an action onto the stack
void push(Stack* stack, char* action) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->action = strdup(action);
    newNode->next = stack->top;
    stack->top = newNode;
}
// Function to pop an action from the stack
char* pop(Stack* stack) {
    if (stack->top == NULL) {
        return NULL; // Stack is empty
    }
    StackNode* popped = stack->top;
    stack->top = popped->next;
    char* action = popped->action;
    free(popped);
    return action;
}
// Function to free the memory used by the stack
void freeStack(Stack* stack) {
    while (stack->top != NULL) {
        char* action = pop(stack);
        free(action);
    }
    free(stack);
}
int main() {
    Stack* undoStack = createStack();
    Stack* redoStack = createStack();
    char command[50];
    char* action;
    clock_t start, end;
    double cpu_time_used;
    while (1) {
        printf("Enter a command ('perform action', 'undo', 'redo', or 'exit'): ");
        fgets(command, sizeof(command), stdin);
        if (strcmp(command, "exit\n") == 0) {
            break;
        } else if (strcmp(command, "perform action\n") == 0) {
            printf("Enter the action to perform: ");
            fgets(command, sizeof(command), stdin);
            action = strdup(command);
            start = clock(); // Start timing
            push(undoStack, action);
            end = clock(); // Stop timing
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Time taken for 'perform action': %f seconds\n", cpu_time_used);
            printf("Action '%s' performed and added to undo stack.\n", action);
        } else if (strcmp(command, "undo\n") == 0) {
            start = clock(); // Start timing
            action = pop(undoStack);
            end = clock(); // Stop timing
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            if (action != NULL) {
                push(redoStack, action);
                printf("Undone action: %s\n", action);
                printf("Time taken for 'undo': %f seconds\n", cpu_time_used);
            } else {
                printf("Nothing to undo.\n");
            }
        } else if (strcmp(command, "redo\n") == 0) {
            start = clock(); // Start timing
            action = pop(redoStack);
            end = clock(); // Stop timing
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            if (action != NULL) {
                push(undoStack, action);
                printf("Redone action: %s\n", action);
                printf("Time taken for 'redo': %f seconds\n", cpu_time_used);
            } else {
                printf("Nothing to redo.\n");
            }
        } else {
            printf("Invalid command. Please enter 'perform action', 'undo', 'redo', or 'exit'.\n");
        }
    }
    // Free memory used by stacks
    freeStack(undoStack);
    freeStack(redoStack);
    return 0;
}