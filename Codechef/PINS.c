#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int q;
        q=n/2;
        printf("1 1");
        while(q--) printf("0");
        printf("\n");
    }
}
