#include <stdio.h>
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        int count=0;
        char str[9];
        scanf("%s",str);
        for(i=0;i<8;i++)
        {
            if (str[i]!=str[(i+1)%8]) count++;
        }
        if (count<=2) printf("uniform\n");
        else printf("non-uniform\n");
    }
    return 0;
}

