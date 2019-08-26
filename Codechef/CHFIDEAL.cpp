#include <iostream>
#include <cstdlib>
#include <stdio.h>

int main()
{
    int num;
    num = rand()%3+1;
    printf("%d\n", num);
    fflush (stdout);
    int inp;
    scanf("%d",&inp);
    printf("%d\n",3-(num+inp)%3);
    fflush (stdout);
    return 0;
}
