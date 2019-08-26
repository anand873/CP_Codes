#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char str[100000];
        scanf("%s",str);
        int n=strlen(str);
        int i;
        for(i=0;i<n;i++)
        {
            str[i]=219-str[i];
        }
        printf("%s\n",str);
    }
    return 0;
}
