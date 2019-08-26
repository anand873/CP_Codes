#include <iostream>
#include <stdio.h>
#include <cstdlib>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n]={0};
        if(n%2==0)
        {
            int i;
            for(i=0;i<(n-1)/2-2;i++)
            {
                printf("?");
                fflush(stdout);
                int m=5;
                int j=0;
                while(m)
                {
                    if(a[j]==0) {printf(" %d",j+1);fflush(stdout);m--;}
                    j++;
                }
                printf("\n");
                fflush(stdout);
                int r,t;
                scanf("%d %d",&r,&t);
                a[r-1]=-1;
                a[t-1]=-1;
            }
            int na[6];
            int j=0;
            i=0;
            int l=6;
            while(l)
            {
                if((a[j])==0)
                {
                    na[i]=j+1;
                    l--;
                    i++;
                }
                j++;
            }
            int d1,d2,e1,e2,f1,f2;
            //Question 1
            int m=5;
            printf("?");
            fflush(stdout);
            j=0;
            while(m)
            {
                printf(" %d",na[j]);
                fflush(stdout);
                j++;
                m--;
            }
            printf("\n");
            fflush(stdout);
            int n1,n2;
            scanf("%d %d",&n1,&n2);
            //Question 2
            m=5;
            printf("?");
            fflush(stdout);
            j=0;
            while(m)
            {
                if(na[j]==n1) {j++; goto go;}
                printf(" %d",na[j]);
                fflush(stdout);
                j++;
                m--;
                go:;
            }
            printf("\n");
            fflush(stdout);
            int n3,n4;
            scanf("%d %d",&n3,&n4);
            int p1,p2,p3;
            p1=n1;
            if(n2==n3) {p2=n2;p3=n4;}
            else {p2=n4;p3=n3;}
            m=3;
            j=0;
            i=0;
            int q[3];
            while(m)
            {
                if(na[j]!=p1&&na[j]!=p2&&na[j]!=p3)
                {
                    q[i]=na[j];
                    i++;
                    m--;
                }
                j++;
            }
            //Question 3-5
            printf("? %d %d %d %d %d\n",p1,p2,p3,q[0],q[1]);
            fflush(stdout);
            scanf("%d %d",&d1,&d2);
            printf("? %d %d %d %d %d\n",p1,p2,p3,q[0],q[2]);
            fflush(stdout);
            scanf("%d %d",&e1,&e2);
            printf("? %d %d %d %d %d\n",p1,p2,p3,q[1],q[2]);
            fflush(stdout);
            scanf("%d %d",&f1,&f2);
            //Answer
            if(d1==e1&&d2==e2) printf("! %d\n",q[0]);
            if(d1==f1&&d2==f2) printf("! %d\n",q[1]);
            if(f1==e1&&f2==e2) printf("! %d\n",q[2]);
            fflush(stdout);
        }
        else
        {
            int i;
            for(i=0;i<(n-7)/2;i++)
            {
                printf("?");
                fflush(stdout);
                int m=5;
                int j=0;
                while(m)
                {
                    if(a[j]==0) {printf(" %d",j+1);fflush(stdout);m--;}
                    j++;
                }
                printf("\n");
                fflush(stdout);
                int r,t;
                scanf("%d %d",&r,&t);
                a[r-1]=-1;
                a[t-1]=-1;
            }
            int na[7];
            int j=0;
            i=0;
            int l=7;
            while(l)
            {
                if((a[j])==0)
                {
                    na[i]=j+1;
                    l--;
                    i++;
                }
                j++;
            }
            int d1,d2,e1,e2,f1,f2;
            //Question 1
            int m=5;
            printf("?");
            fflush(stdout);
            j=0;
            while(m)
            {
                printf(" %d",na[j]);
                fflush(stdout);
                j++;
                m--;
            }
            printf("\n");
            fflush(stdout);
            int n1,n2;
            scanf("%d %d",&n1,&n2);
            //Question 2
            m=5;
            printf("?");
            fflush(stdout);
            j=0;
            while(m)
            {
                if(na[j]==n1||na[j]==n2) {j++; goto ho;}
                printf(" %d",na[j]);
                fflush(stdout);
                j++;
                m--;
                ho:;
            }
            printf("\n");
            fflush(stdout);
            int n3,n4;
            scanf("%d %d",&n3,&n4);
            m=3;
            j=0;
            i=0;
            int q[3];
            while(m)
            {
                if(na[j]!=n1&&na[j]!=n2&&na[j]!=n3&&na[j]!=n4)
                {
                    q[i]=na[j];
                    i++;
                    m--;
                }
                j++;
            }
            //Question 3-5
            printf("? %d %d %d %d %d\n",n1,n2,n3,n4,q[0]);
            fflush(stdout);
            scanf("%d %d",&d1,&d2);
            printf("? %d %d %d %d %d\n",n1,n2,n3,n4,q[1]);
            fflush(stdout);
            scanf("%d %d",&e1,&e2);
            printf("? %d %d %d %d %d\n",n1,n2,n3,n4,q[2]);
            fflush(stdout);
            scanf("%d %d",&f1,&f2);
            //Answer
            if(d1==e1&&d2==e2) printf("! %d\n",q[2]);
            if(d1==f1&&d2==f2) printf("! %d\n",q[1]);
            if(f1==e1&&f2==e2) printf("! %d\n",q[0]);
            fflush(stdout);
        }
    }
    return 0;
}
