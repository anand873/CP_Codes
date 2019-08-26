#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n,k, count = 0 ;
  scanf("%d %d" , &n, &k) ;
  while(n--)
  {
      int a ;
      scanf("%d" , &a) ;
      if ( a%k == 0)
        count++ ;
  }
  printf("%d" , count) ;
    return 0;
}
