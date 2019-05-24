#include <stdio.h>

int main() {
    int num_array[101] = {0};
    int N;
    int num;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &num);
        num_array[i] = num;
    }

    int answer = 0;
    int last = 0;
    int last_count = 0;

    for (int i = 1; i <= N; i++) {
        if (num_array[i] == last) {
            answer += last_count;
            continue;
        }

        last_count = 0;

        for (int j = i + 1; j <= N; j++) {
            if ((num_array[i] + num_array[j]) % 2 != 0) {
                answer++;
                last_count++;
            }
        }
        last = num_array[i];
    }
    printf("%d", answer);
    return 0;
}
