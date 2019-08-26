#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,j;
        char s[2000];
        scanf("%s",&s);
        for(i=0;i<2000;i++)
        {
            if(s[i]=='*') break;
        }

        for(j=0;j<i&&s[j]!='\0';j++)
        {
            printf("%c",s[j]);
        }
        printf("\n");



    }
    return 0;

}
