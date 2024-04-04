#include <string.h>

int main(void)
{
	char *word = mergeAlternately("hello", "different");
}

char * mergeAlternately(char * word1, char * word2)
{
	int len1 = strlen(word1);
	int len2 = strlen(word2);
    char merged[len1+len2+1];

	if (len1 < len2)
	{
		for (int i = 0; i < len2; i++)
		{
			strncat(merged, word1[i], 1);
			strncat(merged, word2[i], 1);
		}
	}
    return merged;
}
