#include <stdio.h>

void print_array(char *str, int *array, int num);

int main() {
    int odd_array[51] = {0};
    int even_array[51] = {0};
    int N;
    int max = 0;
    int min = 100;
    int num;
    scanf("%d", &N);
    int num_count = 0;
	
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        if (num % 2 == 0) {
            even_array[num / 2] = 1;
        } else {
            odd_array[num / 2] = 1;
        }
    }

    int answer = 0;

    for (int i = min; i <= max; i++) {
        if (i % 2 == 0) {
            for (int j = i / 2 + 1; j < 50; j++) {
                if (odd_array[j] == 1) {
                   answer++; 
                }
            }
        } else {
            for (int j = i / 2 + 2; j <= 50; j++) {
                if (even_array[j] == 1) {
                   answer++; 
                }
            }
        }
    }

    print_array("odd", odd_array, 50);
	print_array("even", even_array, 50);   
    printf("%d", answer);

    return 0;

}



void print_array(char *str, int *array, int num)
{
    for (int i = 0; i < num; i++) {
        printf("%s_array[%d] = %d\n", str, i, array[i]);
    }
}
