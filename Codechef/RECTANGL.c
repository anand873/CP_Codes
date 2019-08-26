#include <stdio.h>
int main()
{
    int t,i,a,b,c,d;
    scanf("%d\n",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if ((a==b&&c==d)||(a==c&&b==d)||(a==d&&b==c))
        {
            printf("YES\n");
        }
        else
            {
                printf("NO\n");
            }
    }
    return 0;
}
