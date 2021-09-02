#include <stdio.h>
#include <string.h>
#include "utils.h"

int brainfuck(char* code) {

    BracketPair bracketPairs[MEMORY_LIMIT];
    fillPairArray(code, bracketPairs);

    short memory[MEMORY_LIMIT] = {0};
    int memoryIndex = 0;
    
    int codeIndex = 0;
    while (code[codeIndex] != '\0') {
        switch(code[codeIndex]) {
            case '+':
                if (++memory[memoryIndex] > 255)
                    memory[memoryIndex] = 0;
                break;
            case '-':
                if (--memory[memoryIndex] < 0)
                    memory[memoryIndex] = 255;
                break;
            case '.':
                putChar(memory[memoryIndex]);
                break;
            case ',':
                char input = getChar();
                memory[memoryIndex] = input;
                break;
            case '>':
                if (++memoryIndex > MEMORY_LIMIT)
                    memoryIndex = 0;
                break;
            case '<':
                if (--memoryIndex < 0) 
                    memoryIndex = MEMORY_LIMIT - 1;
                break;
            case '[':
                if (memory[memoryIndex] == 0) {
                    BracketPair bracketPair = getBracketPair(bracketPairs, codeIndex);
                    codeIndex = bracketPair.end;
                }
                break;
            case ']':
                if (memory[memoryIndex] != 0) {
                    BracketPair bracketPair = getBracketPair(bracketPairs, codeIndex);
                    codeIndex = bracketPair.start;
                }
                break;
        }
        codeIndex++;
    }
}

int interpretFile(char* fileName) {
    FILE* fptr = fopen(fileName, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    size_t size = 0;
    char code[64000];
    char c = fgetc(fptr);
    while (c != EOF) 
    {
        code[size++] = c;
        c = fgetc(fptr);
    }

    fclose(fptr);

    brainfuck(code);

    printf("\nProgram finished.\n");

    return 0;
}

int getInput() {
    printf("Enter filename: ");    
    char fileName[64];
    fgets(fileName, 64, stdin);

    fileName[strlen(fileName) - 1] = '\0';

    interpretFile(fileName);
}

int main() {

    while (1)
    {
        getInput();
    }

    return 0;
}
