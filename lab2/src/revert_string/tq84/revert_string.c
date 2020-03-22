#include "revert_string.h"
#include <string.h>
#include "swap.h"
#include <stdio.h>
char* RevertString(char *str)
{
    int i;
    for (i=0; i<strlen(str)/2;i++)
    {
        str = Swap(str ,i,strlen(str)-i-1);
    }
    return str;
}

void __attribute__ ((constructor)) initLibrary(void) {
 //
 // Function that is called when the library is loaded
 //
    printf("Library is initialized\n"); 
}
void __attribute__ ((destructor)) cleanUpLibrary(void) {
 //
 // Function that is called when the library is »closed«.
 //
    printf("Library is exited\n"); 
}


