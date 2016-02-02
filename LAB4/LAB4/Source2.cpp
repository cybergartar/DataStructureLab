#include<stdio.h>
#define SIZE 4

struct stack
{
	int item[SIZE], top;
};

void init(stack *s) {
	s->top = 0;
	return;
}

int isEmpty(stack s) {
	return (s.top == 0 ? 1 : 0);
}


void printSoi(stack s) {
	printf("Print Soi = ");
	for (int i = s.top - 1; i >= 0; i--) {
		printf("%d ", s.item[i]);
	}
	printf("\n");
}

int pop(stack *s) {
	int popedData = s->item[--s->top];
	return popedData;
}

void push(stack *s, int data) {
	s->item[s->top] = data;
	s->top++;
}

void depart(stack *s, int numCar) {
	if (s->top == 0) {
		printf("Car %d cannot depart: soi empty\n", numCar);
		return;
	}
	stack tmp;
	init(&tmp);
	while (!isEmpty(*s)) {
		if (s->item[s->top-1] == numCar) {
			printf("Car %d depart, space left %d\n", numCar, SIZE - (s->top-1));
			pop(s);
			break;
		}
		push(&tmp, pop(s));
	}
	if(!(s->top))
		printf("Car %d cannot depart: No car %d\n", numCar, numCar);
	while (!isEmpty(tmp)) {
		push(s, pop(&tmp));
	}
	return;
}

void arrive(stack *s, int carNum) {
	if (s->top == SIZE) {
		printf("Car %d cannot arrive: SOI FULL\n", carNum);
		return;
	}
	push(s, carNum);
	printf("Car %d arrive, space left %d\n", carNum, SIZE - (s->top));
	return;
}

int main() {
	stack soi;
	init(&soi);
	for (int i = 1; i <= 5; i++)
		arrive(&soi, i);
	printSoi(soi);
	depart(&soi, 7);
	depart(&soi, 2);
	printSoi(soi);
	return 0;
}