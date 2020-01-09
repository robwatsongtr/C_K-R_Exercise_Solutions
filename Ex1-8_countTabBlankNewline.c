#include <stdio.h>

int main () {
    
    int c, nc, nl, tab, blank;
    
    nc = nl = tab = blank = 0;
    
    while ((c = getchar()) != EOF) {
        
        ++nc;
        
        if(c == '\n')
            ++nl;
        else if (c == '\t')
            ++tab;
        else if (c == ' ')
            ++blank;
        
    }

    printf("\ncharacters: %d, newlines: %d, tabs: %d, blank spaces: %d \n", nc, nl, tab, blank);
    
}
