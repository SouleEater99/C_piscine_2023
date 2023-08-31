#include <stdlib.h>

int is_separator(char c, char *charset) {
    while (*charset) {
        if (c == *charset) {
            return 1;
        }
        charset++;
    }
    return 0;
}

int count_words(char *str, char *charset) {
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (is_separator(*str, charset)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        str++;
    }

    return count;
}

char *strdup_range(char *start, char *end) {
    char *result;
    int length = end - start;

    result = (char *)malloc(length + 1);
    if (!result) {
        return NULL; // Handle memory allocation failure
    }

    for (int i = 0; i < length; i++) {
        result[i] = start[i];
    }

    result[length] = '\0';

    return result;
}

char **ft_split(char *str, char *charset) {
    int word_count = count_words(str, charset);
    char **result = (char **)malloc((word_count + 1) * sizeof(char *));

    if (!result) {
        return NULL; // Handle memory allocation failure
    }

    int in_word = 0;
    char *word_start = NULL;
    int index = 0;

    while (*str) {
        if (is_separator(*str, charset)) {
            if (in_word) {
                result[index] = strdup_range(word_start, str);
                if (!result[index]) {
                    // Handle memory allocation failure
                    for (int i = 0; i < index; i++) {
                        free(result[i]);
                    }
                    free(result);
                    return NULL;
                }
                index++;
                in_word = 0;
            }
        } else if (!in_word) {
            word_start = str;
            in_word = 1;
        }
        str++;
    }

    // Add the NULL terminator to indicate the end of the array
    result[index] = NULL;

    return result;
}

