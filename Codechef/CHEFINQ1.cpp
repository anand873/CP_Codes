#include <bits/stdc++.h>
using namespace std;

long long int f(int l, int q)
{
    long long int p=1,k=1;
    if (q!=0)
    {
        while (q)
        {
            p *= l;
            k *= q;
            long long m = __gcd(p, k);
            p/=m;
            k/=m;
            l--;
            q--;
        }
    }
    else p = 1;
    return p;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        vector <int> A;
        int i;
        for(i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            A.push_back(a);
        }
        sort(A.begin(),A.end());
        int p=A[k-1];
        int l=count(A.begin(),A.end(),p);
        i=k-1;
        while(A[i]==p && i>=0)
        {
            i--;
        }
        int q=k-i-1;
        printf("%lld\n",f(l,min(q,l-q)));
    }
}

