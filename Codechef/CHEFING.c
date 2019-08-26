#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int i;
        int A[26]={0};
        int k=0;
        for(i=0;i<n;i++)
        {
            char S[200];
            scanf("%s",&S);
            int m,j;
            m=strlen(S);
            for(j=0;j<m;j++)
            {
                if(A[S[j]-97]==k) A[S[j]-97]++;
            }
            k++;
        }
        int c=0;
        for(i=0;i<26;i++)
        {
            if(A[i]==n) c++;
        }
        printf("%d\n",c);
    }
    return 0;
}
