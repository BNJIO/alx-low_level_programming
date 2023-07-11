#include <stdlib.h>
#include <string.h>

int count_words(char *str)
{
    int count = 0;
    int i = 0;
    int len = strlen(str);

    while (i < len)
    {
        // Skip leading spaces
        while (i < len && str[i] == ' ')
            i++;

        // Count non-space characters
        if (i < len && str[i] != ' ')
        {
            count++;

            // Skip the word
            while (i < len && str[i] != ' ')
                i++;
        }
    }

    return count;
}

char **strtow(char *str)
{
    if (str == NULL || *str == '\0')
        return NULL;

    int num_words = count_words(str);

    // Allocate memory for the array of strings
    char **words = malloc((num_words + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    int word_index = 0;
    int i = 0;
    int len = strlen(str);

    while (i < len)
    {
        // Skip leading spaces
        while (i < len && str[i] == ' ')
            i++;

        // Store non-space characters as a word
        if (i < len && str[i] != ' ')
        {
            int start = i;
            int word_len = 0;

            // Calculate the length of the word
            while (i < len && str[i] != ' ')
            {
                i++;
                word_len++;
            }

            // Allocate memory for the word
            words[word_index] = malloc((word_len + 1) * sizeof(char));
            if (words[word_index] == NULL)
            {
                // Free memory in case of failure
                for (int j = 0; j < word_index; j++)
                    free(words[j]);
                free(words);
                return NULL;
            }

            // Copy the word to the allocated memory
            strncpy(words[word_index], str + start, word_len);
            words[word_index][word_len] = '\0';

            word_index++;
        }
    }

    words[word_index] = NULL;

    return words;
}
