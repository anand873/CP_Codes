#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int i;
        int marks[n],A[n],B[n];
        for(i=0;i<n;i++)
        {
            marks[i]=0;
            scanf("%d",&A[i]);
            marks[i]+=(A[i]*20);
            //printf("%d\t",marks[i]);
        }
        //printf("\n");
        int max=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&B[i]);
            marks[i]-=(B[i]*10);
            if(marks[i]<0) marks[i]==0;
            if(marks[i]>max) max=marks[i];
            //printf("%d\t",marks[i]);
        }
        //printf("\n");
        printf("%d\n",max);
    }
    return 0;
}
