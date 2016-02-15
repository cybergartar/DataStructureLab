#include<stdio.h>

void buy(int indx, int target, int goods[], int sack[]) {
	if (!target) {
		for (int i = 0; i < 8; i++)
			if (sack[i])
				printf("%d ", goods[i]);
		printf("\n");
		return;
	}
	for (indx; indx < 8; indx++) {
		if (!sack[indx] && target - goods[indx] >= 0) {
			sack[indx] = 1;
			buy(indx + 1, target - goods[indx], goods, sack);
			sack[indx] = 0;
		}
	}
	return;
}

int main() {
	int goods[8] = { 20, 10, 5, 5, 3, 2, 20, 10 }, sack[8] = {0};
	int k = 30;
	buy(0, k, goods, sack);
	return 0;
}