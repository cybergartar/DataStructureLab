#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	char data[20];
	node* next;
};

int opt[1000][2];

node* getNode(char *data, node* nextPtr) {
	node* tmp = (node*)malloc(sizeof(node));
	strcpy(tmp->data, data);
	tmp->next = nextPtr;
	return tmp;
}

void print(node* ptr) {
	printf("\nYOUR STING IS NOW: ");
	for (ptr; ptr->next != NULL; ptr = ptr->next)
		printf("%s ", ptr->data);
	printf("%s\n", ptr->data);
}

int getPercentToIndex(int countWord) {
	double tmp, doubleCountWord = countWord;
	do
	{
		printf("\nPLEASE INPUT PERCENT:");
		scanf("%lf", &tmp);
		if (tmp < 0 || tmp>100)
			printf("INVALID PERCENT!!! PLEASE INPUT AGAIN\n");
	} while (tmp < 0 || tmp > 100);
	tmp = (tmp / 100)*doubleCountWord;
	return (int)tmp;
}

node* travelWithAmount(int count, node *head) {
	for (int cnt = 1; cnt != count; cnt++)
		head = head->next;
	return head;
}

void setOperationStack(int mode, int value, int *currentStage) {
	opt[*currentStage][0] = mode;
	opt[*currentStage][1] = value;
	(*currentStage)++;
}

void bottomUp(int *currentStage, int percent, node **head, node **tail, int countWord) {
	if (percent == 0 || percent == countWord) {
		setOperationStack(1, -1, currentStage);
		return;
	}
	node *hNew, *tNew;
	tNew = travelWithAmount(percent, *head);
	hNew = tNew->next;
	(*tail)->next = *head;
	tNew->next = NULL;
	setOperationStack(1, percent, currentStage);
	(*head) = hNew;
	(*tail) = tNew;
	return;
}

void riffle(int *currentStage, int percent, node **head, node **tail, int countWord) {
	if (percent == 0 || percent == countWord) {
		setOperationStack(2, -1, currentStage);
		return;
	}
	node *t1, *h2, *t2, *now[2], *tmp[2];
	t2 = *tail;
	t1 = travelWithAmount(percent, *head);
	h2 = t1->next;
	t1->next = NULL;
	now[0] = *head, now[1] = h2;
	tmp[0] = (*head)->next, tmp[1] = h2->next;
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
	*tail = (t1 == NULL ? t1 : t2);
	setOperationStack(2, percent, currentStage);
	return;
}

void undo(int *currentStage, node **head, node **tail, int countWord) {
	if (!(*currentStage)) {
		printf("\nCAN'T UNDO ANYMORE!\n");
		return;
	}
	(*currentStage)--;
	if (opt[*currentStage][0] == 1 && opt[*currentStage][1] != -1) {
		bottomUp(currentStage, (countWord-opt[*currentStage][1]), head, tail, countWord);
		(*currentStage)--;
	}
	else if(opt[*currentStage][1] != -1){
		int count = 0, limit;
		node *h2 = (*head)->next, *t1 = *head, *t2 = h2;
		if (opt[*currentStage][1] > 5)
			limit = 10 - opt[*currentStage][1] - 1;
		else
			limit = opt[*currentStage][1] - 1;
		while (count < limit) {
			t1->next = t2->next;
			t1 = t1->next;
			t2->next = t1->next;
			t2 = t2->next;
			count++;
		}
		if (opt[*currentStage][1]>5) {
			t1->next = t2->next;
			while (t1->next != NULL)
				t1 = t1->next;
		}
		else
			while (t2->next != NULL)
				t2 = t2->next;
		t2->next = NULL;
		t1->next = h2;
		*tail = t2;
	}
	print(*head);
}

int main() {
	node *head, *tail;
	int currentStage = 0, countWord = 0;
	char inpString[5000], *parsePtr;
	printf("PLEASE INPUT LETTER STRING: ");
	gets_s(inpString);
	parsePtr = strtok(inpString, " ");
	tail = head = getNode(parsePtr, NULL);
	countWord++;
	parsePtr = strtok(NULL, " ");
	while (parsePtr != NULL) {
		tail->next = getNode(parsePtr, NULL);
		tail = tail->next;
		countWord++;
		parsePtr = strtok(NULL, " ");
	}
	print(head);
	while (1) {
		int choice, percent;
		printf("\n1: Bottom Up\n2: Riffle\n3: De(Bottom Up/Riffle)\n0: Exit\n\nPLEASE SELECT CHOICE: ");
		scanf("%d", &choice);
		if (!choice)
			return 0;
		switch (choice) {
			case 1: percent = getPercentToIndex(countWord); bottomUp(&currentStage, percent, &head, &tail, countWord); print(head);  break;
			case 2: percent = getPercentToIndex(countWord); riffle(&currentStage, percent, &head, &tail, countWord); print(head); break;
			case 3: undo(&currentStage, &head, &tail, countWord); break;
			default: printf("\nINVALID CHOICE!!! PLEASE INPUT AGAIN: ");
		}
		if (choice >= 1 && choice <= 3)
			printf("\nYOU HAVE DONE %d ACTION(S)\n", currentStage);
	}

	return 0;
}