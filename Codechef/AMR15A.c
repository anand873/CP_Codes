#include <stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int e=0,o=0;
    for(i=0;i<n;i++)
        {
            if(a[i]%2==0) e++;
            else o++;
        }
        if(e>o) printf("READY FOR BATTLE\n");
        else printf("NOT READY\n");
        return 0;
}
