/*#include<stdio.h>
#define SIZE 6

typedef int T;
typedef struct stack {
	T item[SIZE];
	int top;
} stack;

void init(stack *s) {
	s->top = 0;
	return;
}

int isFull(stack s) {
	return (s.top == SIZE ? 1 : 0);
}

void push(stack *s, T data) {
	s->item[s->top] = data;
	s->top++;
}

void print(stack s) {
	printf("S: ");
	for (T i = s.top-1; i >= 0; i--) {
		printf("%d ", s.item[i]);
	}
	printf("\n");
}

int isEmpty(stack s) {
	return (s.top == 0 ? 1 : 0);
}

int top(stack s) {
	return s.item[s.top - 1];
}

int pop(stack *s) {
	int popedData = s->item[--s->top];
	return popedData;
}
int main() {
	stack s;
	init(&s);
	for (T d = 1; d < 8; d++) {
		if (isFull(s))
			printf("stack full, cannot push %d\n", d);
		else push(&s, d);
	}

	print(s);

	for (int i = 1; i<7; i++)
		if (isEmpty(s))
			printf("stack empty, cannot pop\n");
		else {
			printf("top is %d ", top(s));
			printf("pop %d \n", pop(&s));
		}
	return 0;
}*/