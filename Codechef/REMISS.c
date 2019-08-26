#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(a>b) printf("%d %d\n",a,a+b);
        else printf("%d %d\n",b,a+b);
    }
    return 0;
}
