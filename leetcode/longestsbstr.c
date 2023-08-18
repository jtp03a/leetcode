#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char*);

int main() {
    char str[] = "abccb";
    // char str[] = "bbbbb";
    // char str[] = "pwwkew";

    int result = lengthOfLongestSubstring(str);

    printf("%d\n", result);
    
    return 0;
}

int lengthOfLongestSubstring(char* s){

    if (strlen(s) == 1) {
        return 1;
    }

    int longest = 1;
    
    while (*s != '\0') {
        int len = 0;
        char* cursor = s;
        
        do  {
            cursor++;
            len++;
        } while (*cursor != *s && *cursor != '\0');
        *cursor = '\0';

        lengthOfLongestSubstring(s + 1);

        // if (len > longest) {
        //     longest = len;
        // }
        s++;
    }

    return strlen(s);
}