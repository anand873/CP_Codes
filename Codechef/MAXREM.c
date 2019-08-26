#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i,max=0,secmax=0,A[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        if(A[i]>max) 
        {
            secmax=max;
            max=A[i];
        }
    }
    printf("%d\n",secmax);
}