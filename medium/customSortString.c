#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* customSortString(char* order, char* s);

int main(void) {

	char* order = "pjrtyemnwxaiqbvsdulk";
	char s[] = "zrgccnfyyztxonuldsfazsukqjvvpeouccdyxvhmijhbyljugtkrvdbtkvqdjlxhoaladunemghrazltcuxbsskrhryhjkruputrerthicczsutgasxqiuppsroojvqgfzqlhqcgnxkcdglprerojjqiqecsyhcqzfzpsjxzkybvjfnownofoykzvpjouitiyvzferkd";
	char* ordered_s;

	ordered_s = customSortString(order, s);
	printf("%s\n", ordered_s);
}

char* customSortString(char* order, char* s) {

	int i, j, k, check;
	int order_length = strlen(order);
	int s_length = strlen(s);
	char tmp[s_length + 1];

	printf("order length %d\n", order_length);
	printf("s length %d\n", s_length);
	if ((s_length < 1) || (s_length > 200) ||
			(order_length < 1) || (order_length > 26))
		return NULL;

	strcpy(tmp, s);

	k = 0;
	for (i = 0; i < order_length; ++i) {
		for (j = 0; j < s_length; ++j) {
			if (order[i] == tmp[j]) {
				s[k++] = tmp[j];
			}
		}
	}

	if (order_length < s_length) {
		for (i = 0; i < s_length; ++i) {
			check = 0;
			for (j = 0; j < order_length; ++j) {
				if (tmp[i] == order[j]) {
					check = 1;
					break;
				}
			}
			if (check == 0)
				s[k++] = tmp[i];
		}
	}

	return s;
}
