#include <stdio.h>
#include <string.h>

/**
 * @brief Remove all indexes of a substring from a string
 * 
 * @param string - the string
 * @param substring - the substring
 */
void rmsubstr(char *string, char *substring)
{
    // index
    int i = 0;

    // string and substring length
    int string_length = strlen(string);
    int substr_length = strlen(substring);

    // loop
    while (i < string_length)
    {
        // if the string contains the substring
        if (strstr(&string[i], substring) == &string[i])
        {
            // remove the substring's length from the string
            string_length -= substr_length;
            for (int j = i; j < string_length; j++)
                string[j] = string[j + substr_length];
        }
        
        // else continue
        else i++;
    }
    
    // remove character
    string[i] = '\0';
}