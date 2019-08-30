#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> A;
        int i,coun=0;
        for(i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            A.push_back(a);
        }
        int mi=A[n-1];
        for(i=n-2;i>=0;i--)
        {
            if(A[i]>mi) coun++;
            else mi=A[i];
        }
        printf("%d\n",coun);
    }
}

