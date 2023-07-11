#include <stdlib.h>
#include <string.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
    int count = 0;
    int i = 0;
    int len = strlen(str);

    while (i < len)
    {
        while (i < len && str[i] == ' ')
            i++;

        if (i < len && str[i] != ' ')
        {
            count++;
            while (i < len && str[i] != ' ')
                i++;
        }
    }

    return count;
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: Pointer to an array of strings (words), or NULL if failed.
 */
char **strtow(char *str)
{
    if (str == NULL || *str == '\0')
        return NULL;

    int num_words = count_words(str);

    char **words = malloc((num_words + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    int word_index = 0;
    int i = 0;
    int len = strlen(str);

    while (i < len)
    {
        while (i < len && str[i] == ' ')
            i++;

        if (i < len && str[i] != ' ')
        {
            int start = i;
            int word_len = 0;

            while (i < len && str[i] != ' ')
            {
                i++;
                word_len++;
            }

            words[word_index] = malloc((word_len + 1) * sizeof(char));
            if (words[word_index] == NULL)
            {
                for (int j = 0; j < word_index; j++)
                    free(words[j]);
                free(words);
                return NULL;
            }

            strncpy(words[word_index], str + start, word_len);
            words[word_index][word_len] = '\0';

            word_index++;
        }
    }

    words[word_index] = NULL;

    return words;
}
