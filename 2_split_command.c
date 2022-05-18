#include "main.h"
/**
 * split_string_words - splits content into array of words
 * @text: the string of content to be split.
 *
 * Return: pointer to the words array.
 */
char **split_string_words(char *text)
{
	char **word_arr;
	char *copy, *copy1;
	char *token;
	int count = 0, index = 0;

	copy = malloc(sizeof(char) * strlen(text));
	copy1 = malloc(sizeof(char) * strlen(text));
	_strcpy(copy, text);
	_strcpy(copy1, text);
	token = strtok(copy, " ");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	count++;
	word_arr = malloc(sizeof(char *) * count);
	token = strtok(copy1, " ");
	while (token != NULL)
	{
		word_arr[index] = token;
		token = strtok(NULL, " ");
		index++;
	}
	word_arr[index] = NULL;
	free(copy);
	return (word_arr);
}
