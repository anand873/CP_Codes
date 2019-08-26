#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n,x,k,i,o=0,e=0;
        scanf("%d %d %d %d",&n,&m,&x,&k);
        char s[k];
        scanf("%s",&s);
        for(i=0;i<k;i++)
        {
            if(s[i]=='E') e++;
            else o++;
        }
        if(n<=k&&n<=((e*(m/2))+(o*((m/2)+m%2))))
        {
            for(i=0;i<m;i++)
            {
                if(i%2==0)
                {
                    if(o<=x)
                        {
                            n-=o;
                            o=0;
                        }
                    else
                        {
                            o=o-x;
                            n-=x;
                        }
                }
                else
                {
                    if(e<=x)
                        {
                            n-=e;
                            e=0;
                        }
                    else
                        {
                            e=e-x;
                            n-=x;
                        }
                }
            }
            if(n<=0) printf("yes\n");
             else printf("no\n");
        }
        else printf("no\n");
    }
    return 0;
}
