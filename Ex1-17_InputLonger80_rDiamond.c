// Robert Diamond's answer to K&R Exercise 1-17
// "Write a program to print all input lines that are longer than 80 characters.
//
// Elegant solution I must say....

#include <stdio.h>


int main() {
    
    unsigned int lineLen = 0;
    char prebuffer[81];
    int c;
    while ((c = getchar()) != EOF) {
        
        if (c == '\n')  // we've encountered a newline
        {
            // the case for when the line is longer than 80 characters
            if (lineLen > 80) {
                putchar(c);
            }
            lineLen = 0; // linelen reset
            continue;
        }
        if (lineLen == 80) {
            prebuffer[lineLen++] = '\0';
            printf("%s",prebuffer);
        }
        if (lineLen < 80) {
            prebuffer[lineLen++] = c;
        }
        if (lineLen > 80) {
            putchar(c);
        }
    }
}
