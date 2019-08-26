#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,s,day;
        int j=1,i;
        scanf("%d %d %d",&n,&k,&s);
       for(i=1;i<s+1;i++)
       {
           if(n*j>=k*i) {if ((i+1)%7!=0) j++;}
           else {printf("-1\n");goto end;}
       }
       int ans;
       ans = ((k*s)/n);
       if (ans*n==s*k) printf("%d\n",ans);
       else printf ("%d\n",ans+1);
    end:;
    }
    return 0;
}
