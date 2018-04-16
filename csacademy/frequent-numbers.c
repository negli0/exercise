#include <stdio.h>


int N, K;
int answer = 0;

struct num_freq {
	int freq;
};
struct num_freq num_freq_array[1001] = {0,0};

void check_freq(int num)
{
	if (num_freq_array[num].freq >= K) {
		return;
	} else {
		if (++(num_freq_array[num].freq) >= K) {
			answer++;
			return;
		}
	}
	return;
}

int main(void)
{
	scanf("%d%d", &N, &K);


	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		check_freq(num);
	}
	printf("%d", answer);
	return 0;
}
