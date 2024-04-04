#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* customSortString(char* order, char* s);

int main(void) {

	//char* order = "pjrtyemnwxaiqbvsdulk";
	//char s[] = "zrgccnfyyztxonuldsfazsukqjvvpeouccdyxvhmijhbyljugtkrvdbtkvqdjlxhoaladunemghrazltcuxbsskrhryhjkruputrerthicczsutgasxqiuppsroojvqgfzqlhqcgnxkcdglprerojjqiqecsyhcqzfzpsjxzkybvjfnownofoykzvpjouitiyvzferkd";

	//char* order = "cba";
	//char s[] = "abcd";

	//char* order = "bcafg";
	//char s[] = "abcd";

	char* order = "kqep";
	char s[] = "pekeq";

	char* ordered_s;

	ordered_s = customSortString(order, s);
	printf("%s\n", ordered_s);
}

char* customSortString(char* order, char* s) {

	int i, j, found;
	int idx_start, idx_end;

	int len_order = strlen(order);
	int len_s = strlen(s);

	char s_copy[len_s + 1];
	int freq[len_order];

	idx_start = 0;
	idx_end = len_s - 1;

	strcpy(s_copy, s);

	// count frequencies and add not ordered chars
	for (i = 0; i < len_s; ++i) {
		// count frequencies of order chars
		found = 0;
		for (j = 0; j < len_order; ++j) {
			if (i == 0) {
				// set 0's to frequencies
				freq[j] = 0;
			}
			if (s_copy[i] == order[j]) {
				++freq[j];
				found = 1;
			}
		}

		// put not order char to the end of ordered array
		if (found == 0)
			s[idx_end--] = s_copy[i];
	}

	// put order chars to the ordered array
	for (i = 0; i < len_order; ++i)
		for (j = 0; j < freq[i]; ++j) {
			s[idx_start++] = order[i];
		}

	return s;
}
