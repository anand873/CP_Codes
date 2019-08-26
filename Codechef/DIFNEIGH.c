#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        int i;
        scanf("%d %d",&n,&m);
        if(n==1)
        {
            if(m==1) printf("1\n");
            if(m==2) printf("1\n");
            if(m>=3) printf("2\n");

            printf("1");
            for(i=1;i<m;i++)
            {
                if(i%4==0||i%4==1) printf(" 1");
                else
                {
                    printf(" 2");
                }
            }
            printf("\n");
        }
        if(n==2)
        {
            if(m==1) printf("1\n");
            if(m==2) printf("2\n");
            if(m>=3) printf("3\n");
            for(i=0;i<m-1;i++)
            {
                printf("%d ",i%3+1);
            }
            printf("%d\n",(m-1)%3+1);
            for(i=0;i<m-1;i++)
            {
                printf("%d ",i%3+1);
            }
            printf("%d\n",(m-1)%3+1);
        }
        if(n>=3)
        {
            if(m==1)
            {
                printf("2\n");
                printf("1\n");
                for(i=1;i<n;i++)
                {
                    if(i%4==0||i%4==1) printf("1\n");
                    else
                    {
                        printf("2\n");
                    }
                }
            }
            if(m==2)
            {
                printf("3\n");
                for(i=0;i<n;i++)
                {
                    printf("%d %d\n",i%3+1,i%3+1);
                }
            }
            if(m>=3)
            {
                printf("4\n");
                int j;
                for(i=0;i<n;i++)
                {
                    if(i%4==0)
                    {
                        printf("1");
                        for(j=1;j<m;j++)
                        {
                            if(j%4==0||j%4==1) printf(" 1");
                            else
                            {
                                printf(" 4");
                            }
                        }
                        printf("\n");
                    }
                    if(i%4==1)
                    {
                        printf("2");
                        for(j=1;j<m;j++)
                        {
                            if(j%4==1||j%4==2) printf(" 3");
                            else
                            {
                                printf(" 2");
                            }
                        }
                        printf("\n");
                    }
                    if(i%4==2)
                    {
                        printf("4");
                        for(j=1;j<m;j++)
                        {
                            if(j%4==0||j%4==1)
                            {
                                printf(" 4");
                            }
                            else printf(" 1");
                        }
                        printf("\n");
                    }
                    if(i%4==3)
                    {
                        printf("3");
                        for(j=1;j<m;j++)
                        {
                            if(j%4==1||j%4==2) printf(" 2");
                            else printf(" 3");
                        }
                        printf("\n");
                    }
                }
            }
        }
    }
    return 0;
}
