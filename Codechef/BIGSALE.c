#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j;
        scanf("%d",&n);
        int sale[n][3];
        double loss=0.0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
            {
                scanf("%d",&sale[i][j]);
            }
            loss+= (double)sale[i][1]*(double)sale[i][0]*(((double)sale[i][2]*(double)sale[i][2])/10000.0);
        }
        printf("%lf\n",loss);
    }
    return 0;
}
