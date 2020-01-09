#include <stdio.h>
#include <ctype.h>

#define INWORD 1
#define OUTWORD 0

void printResult(int *wrdlen, int arrSize) {
    printf("\n\n");
    printf(" 1 2 3 4 5 6 7 8+\n");
    for(int i = 0; i < arrSize; ++i)
        printf(" %d", wrdlen[i]);
    printf("\n");
}

void prHorzHist(int *wrdlen, int arrSize) {
    int k = 0;
    printf("\n");
    
    while (k <= arrSize) {
        for (int i = 0; i < wrdlen[k] ; ++i) {
            printf("%c ", '*');
        }
        printf("\n");
        ++k;
    }
    printf("\n");
}

int main() {
    int c, numchar, state;
    int wordlen[8];
    
    for(int i = 0; i < 8; ++i) {
        wordlen[i] = 0;
    }
    
    state = OUTWORD;
    c = numchar = 0;
    
    while((c = getchar()) != EOF) {
       ++numchar;
        if (isspace(c)) {
            state = OUTWORD;
            if(numchar >= 2 && numchar <= 8) ++wordlen[numchar-2];
            else ++wordlen[7]; // eight letters or more
            
            numchar = 0;
        }
        else if (state == OUTWORD) {  // sets initial state to inword
            state = INWORD;
        }
    }
    printResult(wordlen, 8);
    prHorzHist(wordlen, 8);
}
