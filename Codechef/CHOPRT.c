#include <stdio.h>
#include <stdlib.h>

int main()
{
  int test ;
  scanf("%d" , &test) ;
  while(test--)
  {
      int a, b ;
      scanf("%d %d" , &a, &b) ;
        if (a>b)
            printf("> \n") ;
        if (a<b)
            printf("< \n") ;
        if (a==b)
            printf("= \n") ;
  }
    return 0;
}
