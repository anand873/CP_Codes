#include <stdio.h>

int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    int i;
    int x;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x>=r) printf("Good boi\n");
        else printf("Bad boi\n");
    }
    return 0;
}
