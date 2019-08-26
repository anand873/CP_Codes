#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,suma=0,sumb=0,maxa=0,maxb=0;
        scanf("%d",&n);
        int a[n],b[n];
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            suma+=a[i];
            if(a[i]>maxa) {maxa=a[i];}
        }
        suma-=maxa;
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            sumb+=b[i];
            if(b[i]>maxb) {maxb=b[i];}
        }
        sumb-=maxb;
        if(suma>sumb) {printf("Bob\n");}
        if(suma==sumb) {printf("Draw\n");}
        if(suma<sumb) {printf("Alice\n");}
    }
    return 0;
}
