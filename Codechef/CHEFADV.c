#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,x,y;
        scanf("%d %d %d %d",&n,&m,&x,&y);
        if(((n-1)%x==0&&(m-1)%y==0&&(n-1)>=0&&(m-1)>=0)||((n-2)%x==0&&(m-2)%y==0)&&(n-2)>=0&&(m-2)>=0) printf("Chefirnemo\n");
        else printf("Pofik\n");
    }
    return 0;
}
