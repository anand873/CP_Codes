#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long int i,j,t,n,m;
    scanf("%lld",&t);
    for (m=0;m<t;m++)
    {
       scanf("%lld",&n);
       int array[n][n];
       for (i=0;i<n;i++)
       {
           for (j=0;j<n;j++)
           {
               scanf("%lld",&array[i][j]);
           }
       }
       long long int max[n];
       for(i=0;i<n;i++)
       {
           max[i]=0;
       }
       for(j=0;j<n;j++)
       {
           if (array[n-1][j] > max[n-1])
           {
               max[n-1] = array[n-1][j];
           }
       }
       long long int supermax = max[n-1];
       for(i=n-2;i>=0;i--)
       {
            for (j=0;j<n;j++)
            {
                if ((array[i][j] >= max[i])&&(array[i][j] < max[i+1]))
                {
                    max[i] = array[i][j];
                }
            }
          supermax = supermax + max[i]  ;
        }
       if (max[0]!=0)
        printf("%lld\n",supermax);
        else printf("-1\n");
    }
    return 0;
}
