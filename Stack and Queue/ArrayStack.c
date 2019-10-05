#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 5

struct Stack {
    int top;
    int data[MAXLEN];
    int size;
};

typedef struct Stack stack;

stack* createStack() {
    stack *S = (stack*)malloc(sizeof(stack));
    S->top = -1;
    return S;
}

int isFull(stack *S) {
    return S->top == MAXLEN - 1;
}

int isEmpty(stack *S) {
    return S->top == -1;
}

void push(stack *S, int item) {
    if(isFull(S)) {
        perror("STACK FULL");
        exit(EXIT_SUCCESS);
    }
    S->data[++S->top] = item;
}

int pop(stack *S) {
    if(isEmpty(S))
        return;
    return S->data[S->top--];
}

void display(stack *S) {
    if(isEmpty(S))
        return;
    int top = 0;
    while(top != MAXLEN) {
        printf("%d\n", S->data[top]);
        top++;
    }
}

int main() {
    int a,b;
    stack *S = createStack();
    push(S, 10);
    push(S, 20);
    push(S, 30);
    push(S, 40);
    push(S, 50);
    push(S, 60);
    display(S);
}
