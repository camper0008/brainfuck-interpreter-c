#ifndef CMD_H
#define CMD_H

#define MEMORY_LIMIT 30000

typedef struct {
    int start;
    int end;
} BracketPair;

BracketPair getBracketPair(BracketPair array[MEMORY_LIMIT], int value);

int putChar(unsigned char ptr);
char getChar();

int fillPairArray(char* code, BracketPair array[MEMORY_LIMIT]);

#endif
