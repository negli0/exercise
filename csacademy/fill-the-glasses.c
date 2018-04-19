#include <stdio.h>

#define INSERT_TO_LIST_HEAD(h, p) \
	do {\
		(p)->bp = (h); \
		(p)->fp = (h)->fp; \
		(h)->fp->bp = (p); \
		(h)->fp = (p);	\
   	} while (0)

#define INSERT_TO_LIST_TAIL(h, p) \
	do {\
		(p)->bp = (h)->bp; \
		(p)->fp = (h)->fp->bp; \
		(h)->bp->fp = (p);	\
		(h)->bp = (p); \
   	} while (0)

struct bottle {
	int capacity;
	struct bottle *fp;
	struct bottle *bp;
};

struct bottle bottle_head;
static int num_of_bottles = 0;

void sort_insert(struct bottle *b) 
{
	struct bottle *p;
	if (num_of_bottles == 0) {
		INSERT_TO_LIST_HEAD(&bottle_head, b);
		return;
	}
	for (p = bottle_head.fp; p != &bottle_head; p = p->fp) {
		if (b->capacity < p->capacity) {
			INSERT_TO_LIST_TAIL(p, b);
			break;
		}
		if (p->fp->capacity == 0) {
			INSERT_TO_LIST_TAIL(&bottle_head, b);
			break;
		}
	}
	if (p == &bottle_head) {
		printf("oops!\b");
	}
}

void print_sorted_bottles()
{
	struct bottle *p;
	int i = 0;
	for (p = bottle_head.fp; p != &bottle_head; p = p->fp) {
		printf("bottle[%d]: %d\n", i++, p->capacity);
	}
}

int main(void)
{
	bottle_head.fp = bottle_head.bp = &bottle_head;

	int N, K;
	scanf("%d%d", &N, &K);
	struct bottle bottle_list[100] = {{0, NULL, NULL}};

	for (int i = 0; i < N; i++) {
		scanf("%d", &(bottle_list[i].capacity));
		sort_insert(&bottle_list[i]);
		num_of_bottles++;
	}
	int volume = 0;
	struct bottle *p = bottle_head.fp;
	for (int i = 0; i < K; i++) {
		volume += p->capacity;
		p = p->fp;
	}
	print_sorted_bottles();
	if (volume % 100 > 0) {
		printf("%d", volume / 100 + 1);
	} else {
		printf("%d", volume / 100);
	}
}
