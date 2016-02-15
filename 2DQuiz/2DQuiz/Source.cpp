#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	node *next;
};

void printList(node *h) {
	if (h == NULL) {
		printf("NULL\n");
		return;
	}
	while (h != NULL) {
		printf("%d ", h->data);
		h = h->next;
	}
	printf("\n");
	return;
}

void printListWithAddress(node *h) {
	if (h) {
		while (h) {
			printf("%d-%p ", h->data, h);
			h = h->next;
		}
		printf("\n");
	}
	else printf("NULL");
}

node* getNode(int data, node *next) {
	node *tmp = (node*)malloc(sizeof(node));
	tmp->data = data;
	tmp->next = next;
	return tmp;
}

void insertOrder(int data, node **h) {
	if (*h == NULL) {
		*h = getNode(data, NULL);
		return;
	}
	node *tmp = (*h);
	if (tmp->data >= data) {
		node *tmp2 = getNode(data, tmp);
		(*h) = tmp2;
		return;
	}
	while (tmp->next != NULL) {
		if (tmp->next->data >= data) {
			node *tmp2 = getNode(data, tmp->next);
			tmp->next = tmp2;
			break;
		}
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		tmp->next = getNode(data, NULL);
	return;
}

void insertBefore(int data, node **h, int searchVal) {
	node *tmp;
	if ((*h)->data == searchVal) {
		tmp = getNode(data, (*h));
		(*h) = tmp;
		return;
	}
	tmp = (*h);
	while (tmp->next && tmp->next->data != searchVal) 
		if (tmp->next)
			tmp = tmp->next;
		else
			break;

	if (tmp->next == NULL)
		tmp->next = getNode(data, NULL);
	else {
		node *tmp2 = getNode(data, tmp->next);
		tmp->next = tmp2;
	}
	return;
}

void deleteSum(int searchVal, node **h) {
	int tmpSum = searchVal;
	node *itte, *befDel, *sttDel, *endDel;
	itte = befDel = sttDel = endDel = *h;
	while (itte) {
		tmpSum -= itte->data;
		//printf("B++ %p * %d\n", itte, tmpSum);
		if (!tmpSum) {
			tmpSum = searchVal;
			if ((*h) == sttDel) { //@FROM_HEAD
				//printf("!!!!!(%d * %p)", itte->data, itte);
 				befDel = sttDel = (*h) = itte->next;
				//printf("--- %p\n", (*h));
			}
			else {//@MIDDLE
				befDel->next = endDel->next;
			}
		}
		else if (tmpSum < 0) {
			befDel = itte;
			sttDel = itte->next;
			tmpSum = searchVal;
		}
			endDel = itte = itte->next;
			//printf("AFTER\n BEFDEL:%p STTDEL:%p ITTE:%p HEAD:%p\n", befDel, sttDel, itte,(*h));
			//printListWithAddress(*h);
			//getchar();
	}
	return;
}

int main() {
	//----------------1----------------
	node *h = NULL; printList(h);
	insertOrder(4, &h); printList(h);
	insertOrder(3, &h); printList(h);

	insertOrder(6, &h); printList(h);
	insertOrder(3, &h); printList(h);
	insertOrder(9, &h); printList(h);
	insertOrder(5, &h); printList(h);

	//----------------2----------------
	printListWithAddress(h);
	insertBefore(2, &h, 3); printListWithAddress(h);
	insertBefore(1, &h, 10); printListWithAddress(h);
	insertBefore(2, &h, 9); printListWithAddress(h);
	printList(h);

	//----------------3----------------
	deleteSum(5, &h); printListWithAddress(h);
	deleteSum(10, &h); printListWithAddress(h);
	deleteSum(6, &h); printListWithAddress(h);
	printList(h);
}