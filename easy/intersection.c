#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int test1[] = {1, 2, 2, 1};
	int test2[] = {2, 2};
	int* intersection = malloc(2 * sizeof(int));
	int i, j, k, checkFlag;

	k = 0;
	for (i = 0; i < 4; ++i) {
		// check for intersection array
		checkFlag = 0;
		for (j = 0; j < k; ++j) {
			if (test1[i] == intersection[j]) {
				checkFlag = 1;
				break;
			}
		}
		if (checkFlag)
			continue;


		// check for opposed array
		for (j = 0; j < 2; ++j) {
			if (test1[i] == test2[j]) {
				intersection[k++] = test1[i];
				break;
			}
		}
	}

	for (i = 0; i < k; ++i)
		printf("%d ", intersection[i]);
	printf("\n");

	free(intersection);
}
