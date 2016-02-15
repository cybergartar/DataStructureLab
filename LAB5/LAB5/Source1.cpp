/*#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct node {
	int data;
	node *next;
};

void printNDownI(int n) {
	printf("Iterative: ");
	while (n >= 1)
		printf("%d ", n--);
	printf("\n");
}

void printNDownR(int n) {
	if (n == 0) {
		printf(":Recursive \n");
		return;
	}
	printf("%d ", n);
	printNDownR(n - 1);
	return;
}

void printToNI(int n) {
	printf("Iterative: ");
	int i;
	for (i = 1; i <= n; i++) {
		printf("%d ", i);
	}
	printf("\n");
}

void printToNR(int n, int stage) {
	if (stage == n+1) {
		printf(":Recursive \n");
		return;
	}
	printf("%d ", stage);
	printToNR(n, stage+1);
	return;
}

void initArr(int a[], int n) {
	if (n == SIZE)
		return;
	a[n] = n;
	initArr(a, n + 1);
	return;
}

void printArrI(int a[]) {
	int i;
	printf("PrintArr Iterative: ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void printArrR(int a[], int stage) {
	if (stage == SIZE) {
		printf(":PrintArr Recursive\n");
		return;
	}
	printf("%d ", a[stage]);
	printArrR(a, stage + 1);
	return;
}

node* createList(int n) {
	if (n == 0)
		return NULL;
	node *h, *t;
	h = t = (node*)malloc(sizeof(int));
	h->data = 1;
	h->next = NULL;
	if (n == 1)
		return h;
	for (int i = 2; i <= n; i++) {
		t->next = (node*)malloc(sizeof(int));
		t = t->next;
		t->data = i;
	}t
		->next = NULL;
	return h;
}

void print(node *now) {
	if (now == NULL)
		return;
	printf("%d ", now->data);
	print(now->next);
}

void printRev(node *now) {
	if (now->next == NULL) {
		printf("%d ", now->data);
		return;
	}
	else {
		printRev(now->next);
		printf("%d ", now->data);
	}
	return;
}

node* createR(int stage, int n) {
	if (stage == n + 1) {
		return NULL;
	}
	node *tmp = (node*)malloc(sizeof(node));
	tmp->data = stage;
	tmp->next = createR(stage + 1, n);
	return tmp;
}

int main() {
	int n, a[SIZE];
	scanf("%d", &n);
	printNDownI(n);
	printNDownR(n);
	initArr(a, 0);
	printArrI(a);
	printArrR(a, 0);

	node *h = createList(5);
	print(h);	printf("\n");
	printRev(h);	printf("\n");
	node *h2 = createR(1,5);
	print(h2);	printf("\n");
	printRev(h2);	printf("\n");
	return 0;
}*/