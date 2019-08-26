#include <stdio.h>
#include <string.h>
#include <math.h>

int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}

int maxm(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int A[26]={0};
        char S[1000000];
        scanf("%s",&S);
        int l;
        l=strlen(S);
        int i;
        for(i=0;i<l;i++)
        {
            A[S[i]-65]++;
        }
        int j;
        for(i=0;i<26;i++)
        {
            for(j=i;j<26;j++)
            {
                if(A[i]<A[j])
                {
                    int temp;
                    temp=A[i];
                    A[i]=A[j];
                    A[j]=temp;
                }
            }
        }
        int ans=l-A[0];
        for(i=1;i<27;i++)
        {
            if(l%i==0)
            {
                int s=0;
                for(j=0;j<i;j++)
                {
                    if(A[j]<l/i) s+=(l/i-A[j]);
                }
                if(s<ans) ans=s;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
