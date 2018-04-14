#include <stdio.h>

int main(void)
{
	int N;
	long answer = 0;
	int num[3] = {0};
	int tmp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		num[(tmp % 3)]++;
	}

	answer = num[1] * num[2];
	answer += num[0] * (num[0] - 1) / 2;

	printf("%ld", answer);
	return 0;
}
