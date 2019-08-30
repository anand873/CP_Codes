#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    int o=0;
    for(i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        if(c%2) o++;
    }
    int ans=min(o,n-o);
    printf("%d\n",ans);
}
