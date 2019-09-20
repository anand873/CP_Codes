#include <bits/stdc++.h>
using namespace std;

int f(int i)
{
    if(i==1) return 0;
    if(i==2) return 1;
    if((i-3)%4==0) return 2;
    if((i-3)%4==1) return 3;
    if((i-3)%4==2) return 0;
    return 9;

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        int i=0;
        long long int p=n;
        while(p)
        {
            p/=2;
            i+=1;
        }
        printf("%d\n",f(i));
    }
}
