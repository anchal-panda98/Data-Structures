// C program to reverse an array using stack
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define size 5

struct Stack
{
	int top;
	int data[size];
};
typedef struct Stack stack;

stack* createStack()
{
	stack *s = (stack*) malloc(sizeof(stack));
	s->top = -1;
	return s;
}

int isFull(stack* s)
{
    return s->top == size - 1;
}

int isEmpty(stack* s)
{
    return s->top == -1;
}

void push(stack* s, int item)
{
	if (isFull(s))
		return;
	s->data[++s->top] = item;
}

int pop(stack* s)
{
	if (isEmpty(s))
		return;
	return s->data[s->top--];
}

void reverse(int list[])
{
	stack* s = createStack();

	int i;
	for (i = 0; i < size; i++)
		push(s, list[i]);

	for (i = 0; i < size; i++)
		list[i] = pop(s);
}

int main()
{
	int list[size];
    int i;
    for(i=0; i<size; i++) {
        scanf("%d", &list[i]);
    }
	reverse(list);
	printf("Reversed list is:");
	for(i=0; i<size; i++) {
        printf("%d\t", list[i]);
	}
	return 0;
}

