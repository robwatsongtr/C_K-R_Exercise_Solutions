
// MAXLINE 10 is a constant I chose for now, it can be whatever
// which is the point of the program

#include <stdio.h>
#define MAXLINE 10 

int myGetLine(char line[], int maxline);
void copyFunc(char to[], char from[]);

// main func prints longest input line
int main(void) {
    
    int len; // current line length
    int max;  // maximum length seen so far
    char line[MAXLINE+1]; // current input line
    char longest[MAXLINE+1];  // longest line saved here
    
    max = 0;
   
    while( (len = myGetLine(line, MAXLINE)) > 0) {  // myGetline gets a line, returns length into len
        if (len > max) {
            copyFunc(longest, line); // longest line is copied into line[]
            max = len;
        }
    }
    if (max > 0) // there was a line, error check
        printf("\n\n%s\n",longest);
    
}


int myGetLine(char line[], int maxline) {
    int c, i;
    c = 0;
    i = 0;
    
    while ( (c = getchar()) != EOF && c != '\n') {
        if (i < maxline ) {
            line[i] = c;
        }
        if (i >= maxline)
            break;
        ++i;
    }
    if(c == '\n') {
        line[i] = c;
        ++i;
    }
    
    line[i] = '\0';
    return i;
    
}

void copyFunc(char to[], char from[]){
    int i;
    i = 0;
    
    // loop contents from FROM index to TO, index by index ("as true") unitl \0
    while( (to[i] = from[i]) != '\0') {
        ++i;
    }
   // printf("RMD i is %d\n", i);
}


