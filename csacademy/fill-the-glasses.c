#include <stdio.h>

void swap(int *a, int *b) 
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int N, K;
	scanf("%d%d", &N, &K);
	int *min_list = malloc(sizeof(int) * K);
	int largest = 0;
	int largest_index = 0;
	int num;

	for (int i = 0; i < K; i++) {
		scanf("%d", &min_list[i]);
		if (largest < min_list[i]) {
			largest = min_list[i];
			largest_index = i;
		}
	}

	for (int i = K; i < N; i++) {
		scanf("%d", &num);
		if (largest > num) {
			min_list[largest_index] = num;
		}
	}
}
