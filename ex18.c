#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char* message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR %s\n", message);
	}

	exit(1);
}

typedef int (*compare_cb)(int a, int b);

int* bubble_sort(int* numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int* target = malloc(count * sizeof(int));

	if (!target) die("Memory error.");

	memcpy(target, numbers, count * sizeof(int));

	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count -1; ++j)
		{
			if (cmp(target[j], target[j+1]) > 0) {
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}

	return target;
}

int sorted_order(int a, int b)
{
	return a-b;
}

int reverse_order(int a, int b)
{
	return b-a;
}

int strange_order(int a, int b)
{
	if (!a || !b) {
		return 0;
	} else {
		return a%b;
	}
}

int main(int argc, char const *argv[])
{
	int numbers[] = { 42, 17, 55, 9, 83, 22, 10921, 1 };

	int* sorted = bubble_sort(numbers, sizeof(numbers) / sizeof(int), strange_order);

	for (int i = 0; i < sizeof(numbers) / sizeof(int); ++i)
	{
		printf("%d, ", sorted[i]);
	}

	printf("\n");

	return 0;
}