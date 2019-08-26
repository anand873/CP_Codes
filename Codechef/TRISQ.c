#include <stdio.h>
int main()
{
    int t,n,m;
    scanf("%d",&t);
    for (n=0;n<t;n++)
    {
        scanf("%d",&m);
        if (m%2 == 0)
        {
            printf("%d\n",m*(m-2)/8) ;
        }
        else {printf("%d\n",(m-1)*(m-3)/8);}
    }
    return 0;

}
