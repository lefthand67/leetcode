#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s);


int main(void){

	char* s;
	s = "Hello World ";

	printf("%d\n", lengthOfLastWord(s));
	return 0;
}


int lengthOfLastWord(char* s) {
	int i;  // index of the last char of the string
	int j;  // index of the last letter of the last word
	int len_word;  // length of the last word

	i = j = strlen(s) - 1;
	len_word = 0;

	// find the index of the last letter of the last word
	for (; i >= 0; --i) {
		if (s[i] == ' ') {
			--j;
			continue;
		}
		else
			break;
	}

	// count the len of the last word
	for (; j >= 0; --j){
		if (s[j] != ' ')
			len_word++;
		else
			break;
	}

	return len_word;
}

