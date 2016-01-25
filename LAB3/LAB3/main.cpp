#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

struct node {
	int data;
	node* next;
};

int opt[1000][2];

node* getNode(int data, node* nextPtr) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = data;
	tmp->next = nextPtr;
	return tmp;
}

node *head, *tail;

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

void bottomUp(int *currentStage, int percent) {
	percent = percent / 10;
	node *h1, *h2, *t1, *t2;
	h1 = head;
	t2 = tail;
	t1 = travelWithAmount(percent, h1);
	h2 = t1->next;
	t2->next = h1;
	t1->next = NULL;
	//printf("%d\n",t1->data);
	opt[*currentStage][0] = 1;
	opt[*currentStage][1] = percent;
	(*currentStage)++;
	//printf("!!!!%d\n", *currentStage);
	head = h2;
	tail = t1;
	return;
}

void riffle(int *currentStage, int percent) {
	percent /= 10;
	node *h1, *t1, *h2, *t2;
	h1 = head;
	t2 = tail;
	t1 = travelWithAmount(percent, h1);
	h2 = t1->next;
	t1->next = NULL;
	node *now[2], *tmp[2];
	now[0] = h1, now[1] = h2;
	tmp[0] = h1->next, tmp[1] = h2->next;
	int side = 0;
	while (1) {
		if (tmp[side] == NULL) {
			now[side]->next = now[(side + 1) % 2];
			break;
		}
		now[side]->next = now[(side + 1) % 2];
		now[side] = tmp[side];
		tmp[side] = tmp[side]->next;
		side = (side + 1) % 2;
	}
	head = h1;
	tail = (t1 == NULL ? t1 : t2);

	return;
}

void undo() {
	/*if (!currentStage) {
		printf("Can't undo anymore!");
		return;
	}*/
	//if(currentStage)
}

int main() {
	// freopen("inp.in", "r", stdin);
	// freopen("opt.out", "w", stdout);
	int currentStage = 0;
	tail = head = getNode(1, NULL);
	for (int i = 2; i <= 10; i++) {
		tail->next = getNode(i, NULL);
		tail = tail->next;
	}
	print(head);
	while (1) {
		int choice, percent;
		printf("1: Bottom Up\n2: Riffle\n3: De(Bottom Up/Riffle)\n0: Exit\n");
		scanf("%d", &choice);
		if (!choice)
			return 0;
		switch (choice) {
		case 1: percent = getPercent(); bottomUp(&currentStage, percent); print(head);  break;
		case 2: percent = getPercent(); riffle(&currentStage, percent); print(head); break;
			case 3: undo(); break;
		}

	}

	return 0;
}