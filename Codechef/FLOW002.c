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
      int rem ;
      rem = a%b ;
      printf("%d \n" , rem) ;
  }
    return 0;
}
