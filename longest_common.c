// Modify this file

#include "longest_common.h"

/*
Arguments:
    filename: name of the input file
    first_line: temporary space to store what is read from the first line of the file
    second_line: temporary space to store what is read from the second line of the file
    size: size of line
Return:
    length of the longest common substring between two strings
*/
int longest_common(char* filename, char* first_line, char* second_line, int size)
{
    // EDIT THIS FUNCTION
    // You may follow the steps and use the codes given, but you may also ignore and make your own moves as well.

    // Step 1: Open the file
    //         Don't forget to handle failures
    FILE* file = fopen(filename, "r");
    if (file == NULL){
        return -1;
    }


    // Step 2: Read two lines from the file
    //         Save the first line at first_line and second line at second_line
    //         Don't forget to handle the failures
    // First Line
    if (fgets(first_line, size, file) == NULL) {
        fclose(file);
        return -1;
    }
    // Second line
    if (fgets(second_line, size, file) == NULL) {
        fclose(file);
        return -1;  // Failed to read second line
    }

    // Step 3: Remove each line's newline character
    first_line[strcspn(first_line, "\r\n")]  = '\0';
    second_line[strcspn(second_line, "\r\n")] = '\0';

    // Step 4: Find the longest common substring between the two strings
    //         Probably, you would have to loops (that are nested)
    int max_length = 0;         // Maximum length of common substring that was found
     for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            
            if (first_line[i] == second_line[j]) {
                int length = 0;
                int k = 0;
                
                while ((i + k) < len1 && (j + k) < len2 && 
                       first_line[i + k] == second_line[j + k]) {
                    length++;
                    k++;
                }
                
                //upddate
                if (length > max_length) {
                    max_length = length;
                }
            }
        }
    }


    fclose(file);

    // Step 5 :Return the maximum length of common substrings
    return max_length;
}
