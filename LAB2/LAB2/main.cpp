#include<stdio.h>
#include<stdlib.h>

typedef int dataType;

struct node {
	dataType data;
	node* next;
};
typedef struct node node;

void print(node *ptr) {
	/*printf("%d ", ptr->data);
	if (ptr->next != NULL)
		print(ptr->next);
	else
		printf("\n");*/
	printf("%d ", ptr->data);
	while (ptr->next!= NULL) {
		ptr = ptr->next;
		printf("%d ", ptr->data);
	}
	printf("\n");
	return;
}

node* getNode(dataType inpDat, node* nextPtr) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = inpDat;
	tmp->next = nextPtr;
	return tmp;
}

void insertAfter(dataType data, node* afterPtr) {
	node* tmp = getNode(data, afterPtr->next);
	afterPtr->next = tmp;
	return;
}

void deleteAfter(node* afterPtr) {
	node* delThis = afterPtr->next;
	afterPtr->next = delThis->next;
	free(delThis);
	return;
}

void insertEnd(dataType data, node** tailPtr) {
	if ((*tailPtr)) {
		(*tailPtr)->next = getNode(data, NULL);
		(*tailPtr) = (*tailPtr)->next;
	}
	return;
}

void insertFirst(dataType data, node** headPtr) {
	node* tmp = getNode(data, *headPtr);
	*headPtr = tmp;
	return;
}

bool isEmpty(node* headPtr) {
	if (headPtr->next == NULL)
		return false;
	return true;
}

bool isLast(node* tailPtr) {
	if (tailPtr->next == NULL)
		return true;
	return false;
}

node* makeEmpty(node* ptr) {
	if (ptr->next != NULL) {
		free(makeEmpty(ptr->next));
	}
	else
		return ptr;
}

node* find(dataType data, node* ptr) {
	if (ptr->data == data)
		return ptr;
	else if (ptr->next != NULL)
		return find(data, ptr->next);
	else
		return NULL;
}

void deleteFind(dataType data, node** ptr, node** tailPtr) {
	if ((*ptr)->data == data) {
		node* tmp = *ptr;
		(*ptr) = (*ptr)->next;
		free(tmp);
		return;
	}
	if ((*ptr)->next != NULL && (*ptr)->next->data == data)
		if ((*ptr)->next->next == NULL) {
			(*tailPtr) = (*ptr);
			(*tailPtr)->next = NULL;
			free((*ptr)->next);
		}
		else {
			node* tmp = (*ptr)->next;
			(*ptr)->next = tmp->next;
			free(tmp);
		}
	else if((*ptr)->next)
		deleteFind(data, &(*ptr)->next, &(*tailPtr));
	return;
}

node* findPrevious(int data, node* ptr) {
	if (ptr->data == data)
		return getNode(NULL, NULL);
	if (ptr->next) {
		if (ptr->next->data == data)
			return ptr;
		else if (ptr->next)
			return findPrevious(data, ptr->next);
		else
			return NULL;
	}
}

int main() {
	//----------------EXP1
	/*int i = 3;
	int j = 5;
	int *p = &i;
	*p = 7;
	p = &j;
	*p = 9;*/
	
	//----------------EXP2
	/*int i = 8;
	int *p = &i;
	int *q = (int*)malloc(sizeof(int));
	//---------------------------------
	int *r = q;
	*q = 5;
	printf("*p=%d *q=%d *r=%d\n", *p, *q, *r);
	q = &i;
	printf("*p=%d *q=%d *r=%d\n", *p, *q, *r);
	free(r);
	printf("*p=%d *q=%d *r=%d\n", *p, *q, *r);*/
	
	//----------------EXP3
	/*node *h = (node*)malloc(sizeof(node));
	h->data = 'A';
	node *t = h;
	node *q = (node*)malloc(sizeof(node));
	q->data = 'B';
	t->next = q;	t = q;
	node *r = (node*)malloc(sizeof(node));
	r->data = 'C';
	t->next = r;	t = r;	t->next = NULL;
	print(h);*/

	//----------------EXP4
	/*node *h = getNode('A', NULL);
	node *t = h;
	for (char d = 'B'; d < 'F'; d++) { 
		t->next = getNode(d, NULL);
		t = t->next;
	}
	print(h);*/

	//-----------------EXP5
	node *h = getNode(1, NULL);
	node *t = h;
	for (int d = 2; d < 4; d++) {
		t->next = getNode(d, NULL);
		t = t->next;
	}
	print(h);
	printf("--------- 6 ---------\n");
	//-----------------EXP6
	insertAfter(4, h);	print(h);
	insertAfter(5, h->next);	print(h);
	deleteAfter(h);	print(h);
	deleteAfter(h->next);	print(h);
	//-----------------EXP7
	printf("--------- 7 ----------\n");
	insertEnd(6, &t);	print(h);
	print(t);
	print(h);
	//----------------EXP10
	printf("--------- 8 ----------\n");
	insertFirst(7, &h); print(h);
	return 0;
}