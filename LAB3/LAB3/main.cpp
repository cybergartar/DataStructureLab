#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	int data;
	node* next;
};

struct stack {
	node *head1, *tail1, *head2, *tail2;
	int mode;
};

stack optStk[1100];

node* getNode(int data, node* nextPtr) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = data;
	tmp->next = nextPtr;
	return tmp;
}

void print(node* ptr) {
	printf("%d ", ptr->data);
	while (ptr->next != NULL) {
		ptr = ptr->next;
		printf("%d ", ptr->data);
	}
	printf("\n");
}

int getPercent() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}

node* travelWithAmount(int count, node *head) {
	int cnt = 1;
	while (cnt != count) {
		head = head->next;
		cnt++;
	}
	return head;
}

void bottomUp() {

}

void riffle() {

}

void undo() {
	/*if (!currentStage) {
		printf("Can't undo anymore!");
		return;
	}*/
	//if(currentStage)
}

int main() {
	node *h, *t;
	t = h = getNode(1, NULL);
	for (int i = 2; i <= 10; i++) {
		t->next = getNode(i, NULL);
		t = t->next;
	}
	print(h);
	while (1) {
		int choice, percent;
		printf("1: Bottom Up\n2: Riffle\n3: De(Bottom Up/Riffle)\n 0: Exit\n");
		scanf("%d", &choice);
		if (!choice)
			return 0;
		switch (choice) {
		case 1: percent = getPercent(); bottomUp(); break;
			case 2: percent = getPercent(); riffle(); break;
			case 3: undo(); break;
		}

	}

	return 0;
}