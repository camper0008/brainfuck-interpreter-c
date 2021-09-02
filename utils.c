#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

BracketPair getBracketPair(BracketPair array[MEMORY_LIMIT], int value) {
    int i = 0;
    while (i < MEMORY_LIMIT)
    {
        if (array[i].start == value || array[i].end == value)
             return array[i];
        i++;
    }
    printf("Unable to find bracket pair.");
}

int putChar(unsigned char ptr) 
{
    printf("%c", ptr);
    return 0;    
}

char getChar() 
{
    char c[4];
    fgets(c, 4, stdin);
    return c[0];
}

int makeBracketPair(char* code, int start, BracketPair array[MEMORY_LIMIT], size_t arrayIndex) {
    int i = start;
    int nested = 0;
    while (code[i] != '\0') {
        if (code[i] == '[') nested++;
        if (code[i] == ']') {
            if (--nested == 0) {
                BracketPair newPair;
                newPair.start = start;
                newPair.end = i;
                array[arrayIndex] = newPair;
                break;
            }            
        }
        i++;
    }
    if (nested > 0) {
        printf("Unclosed loop at character [%d]\n", start);
        exit(1);
        return 1;
    }
    return 0;
}

int fillPairArray(char* code, BracketPair array[MEMORY_LIMIT]) 
{
    size_t arrayIndex = 0;
    int i = 0;
    while (code[i] != '\0') {
        if (code[i] == '[')
            makeBracketPair(code, i, array, arrayIndex++);
        i++;
    }
    return 0;
}
