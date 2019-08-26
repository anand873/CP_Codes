#include <stdio.h>
#include <string.h>

int solve(char* s, int f, int l)
{
    //printf("f=%d\tl=%d\n",f,l);
    if(f==l-1)
    {
        if(s[f]=='0') return 0;
        else return 1;
    }
    int i;
    for(i=f;i<l;i++)
    {
        //printf("s[%d]=%c\n",i,s[i]);
        if(s[i]=='1')
        {
            if(i==f)
            {
                if(s[i+1]=='0') s[i+1]='1';
                else s[i+1]='0';
                return solve(s,f+1,l);
            }
            else if(i==l-1)
            {
                if(s[i-1]=='0') s[i-1]='1';
                else s[i-1]='0';
                return solve(s,f,l-1);
            }
            else
            {
                if(s[i-1]=='0') s[i-1]='1';
                else s[i-1]='0';
                if(s[i+1]=='0') s[i+1]='1';
                else s[i+1]='0';
                return solve(s,f,i)&&solve(s,i+1,l);
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[100001];
        scanf("%s",&s);
        int n;
        n=strlen(s);
        int a=solve(s,0,n);
        if(a==1) printf("WIN\n");
        else printf("LOSE\n");
    }
    return 0;
}
