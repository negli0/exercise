#include <stdio.h>
#define INIT 0
#define L_EXIST 7
#define R_EXIST 13
#define BOTH_EXIST 
struct shoes {
	int rest_of_r;
	int rest_of_l;
};

int main() {
	int N;
	int size;
	char shoe;
	int answer = 0;

	scanf("%d", &N);
	struct shoes shoes_table[101] = {{0, 0}};

	for (int i = 0; i < N; i++) {
		scanf("%d %c", &size, &shoe);
		switch (shoe) {
			case 'R':
				shoes_table[size].rest_of_r++;
				if (shoes_table[size].rest_of_l != 0) {
					shoes_table[size].rest_of_l--;
					shoes_table[size].rest_of_r--;
					answer++;
				}
				break;

			case 'L':
				shoes_table[size].rest_of_l++;
				if (shoes_table[size].rest_of_r != 0) {
					shoes_table[size].rest_of_r--;
					shoes_table[size].rest_of_l--;
					answer++;
				}
				break;
		}
	}
	printf("%d", answer);

	return 0;
}
