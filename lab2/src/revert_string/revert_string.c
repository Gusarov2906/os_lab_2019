#include "revert_string.h"
#include <string.h>
#include "swap.h"
void RevertString(char *str)
{
    int i;
    for (i=0; i<strlen(str)/2;i++)
    {
        Swap(str[i],str[strlen(str)-i-1]);
    }
}

