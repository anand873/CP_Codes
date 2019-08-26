#include <stdio.h>
#include <stdlib.h>
int Root()
{

}
int main()
{
  int test, val ;
  scanf("%d" , &test) ;
  while(test--)
  {
      scanf("%d" , &val) ;
      int n=1 ;
    Loop:  if(val/n == n)
      {
          printf("%d \n" , n) ;
      }
      else
      {
      n++ ;
      goto Loop;
      }
  }
    return 0;
}
