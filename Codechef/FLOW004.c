#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      int integer,ld,fd=0;
      scanf("%d",&integer);
      ld = integer%10;
      while(integer>0)
      {
          fd = integer%10;
          integer = integer/10;
      }
      printf("%d\n",ld+fd);
    }
    return 0;
}

