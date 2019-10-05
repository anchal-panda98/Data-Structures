#include<stdio.h>
#include<stdlib.h>
#define size 4

struct Stack {
    int top;
    int data[size];
};

typedef struct Stack stack;

stack* createStack() {
    stack *S = (stack*)malloc(sizeof(stack));
    S->top = -1;
    return S;
}

int isFull(stack *S) {
    return S->top == size - 1;
}

int isEmpty(stack *S) {
    return S->top == -1;
}

void push(stack *S, int item) {
    if(isFull(S))
        LeakyStack(S, item);
    S->data[++S->top] = item;
}

int pop(stack *S) {
    if(isEmpty(S))
        return;
    return S->data[S->top--];
}

void LeakyStack(stack *S, int item) {
    int key, i = 0;
    S->top = 0;
    while(S->top < size-1) {
        key = S->data[S->top+1];
        S->data[i] = key;
        i++;
        S->top++;
    }
    S->top = S->top - 1;
    push(S, 5);
}

void display(stack *S) {
    if(isEmpty(S))
        return;
    int top = 0;
    while(top != size) {
        printf("%d\n", S->data[top]);
        top++;
    }
}

int main() {
    stack *S = createStack();
    push(S, 1);
    push(S, 2);
    push(S, 3);
    push(S, 4);
    push(S, 5);
    display(S);
}
