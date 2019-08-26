#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,j,i;
        scanf("%d",&n);
        int m=n;
        int A[n];
        int count=0;
        while(n--)
        {


            for(j=2;j<=(int)sqrt(n);)
            {
                if(n%j!=0)
                {
                  j++;
                }
                else break;

            }

            if(j==(int)sqrt(n)+1&&(n%j!=0))
            {
                if(n!=1)
                 {A[count]=n;
                 ++count;}
            }

        }
        //for(j=0;j<count;j++)printf("%d ",A[j]);
        for(j=0;j<count;j++)
        {
            for(i=0;i<count;i++)
            {

                if(A[i]+A[j]==m)
                {
                    printf("%d %d\n",A[i],A[j]); goto end;

                }
            }
        }
        end:;
    }

}

