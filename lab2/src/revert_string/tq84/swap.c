#include "swap.h"
char* Swap(char*str,int i,int j)
{
	char tmp = str[i];
    str[i] = str[j];
    str[j]=tmp;
    return str;
}
