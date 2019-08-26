#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[100];
        scanf(" %[^\t\n]s",&s);
        int i=0,j;
        j=strlen(s);
        if(j==3)
            {
                if(s[0]=='n'&&s[1]=='o'&&s[2]=='t') {printf("Real Fancy\n"); goto en;}
            }
        for(i=0;i<j-3;i++)
        {
            if(i==j-4)
            {
                if(s[i]==' '&&s[i+1]=='n'&&s[i+2]=='o'&&s[i+3]=='t') {printf("Real Fancy\n"); goto en;}
            }
            if(i==0)
            {
                if(s[i]=='n'&&s[i+1]=='o'&&s[i+2]=='t'&&s[i+3]==' ') {printf("Real Fancy\n"); goto en;}
            }
            if(s[i]==' '&&s[i+1]=='n'&&s[i+2]=='o'&&s[i+3]=='t'&&s[i+4]==' ') {printf("Real Fancy\n"); goto en;}
        }
        printf("regularly fancy\n");
        en:;
    }
    return 0;
}
