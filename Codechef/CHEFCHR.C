#include <stdio.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a[500000];
        int count=0,i;
            scanf("%s",&a);
        for(i=0;i<strlen(a);i++)
        {
            if((a[i]=='c'||a[i]=='h'||a[i]=='e'||a[i]=='f')&&(a[i+1]!=a[i]&&(a[i+1]=='c'||a[i+1]=='h'||a[i+1]=='e'||a[i+1]=='f'))&&((a[i+2]=='c'||a[i+2]=='h'||a[i+2]=='e'||a[i+2]=='f')&&a[i+2]!=a[i]&&a[i+2]!=a[i+1])&&((a[i+3]=='c'||a[i+3]=='h'||a[i+3]=='e'||a[i+3]=='f')&&a[i+3]!=a[i+1]&&a[i+3]!=a[i+2]&&a[i+3]!=a[i]))
            count++;
        }
        if(count) printf("lovely %d\n",count);
        else printf("normal\n");
    }
    return 0;
}
