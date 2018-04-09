#include <stdio.h>

int main(void)
{
	int N;
	int answer = 0;
	int num[100000];
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (((num[i] + num[j]) % 3) == 0) {
				answer++;
			}
		}
	}

	printf("%d", answer);
	return 0;
}
