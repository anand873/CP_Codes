#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int d;
        scanf("%d",&d);
        char S[d];
        scanf("%s",&S);
        int i;
        int p=0,a=0,pr=0;
        for(i=0;i<d;i++)
        {
            if(S[i]=='A') a++;
            else p++;
        }
        //printf("%d %d\n",p,a);
        int k=2;
  loop: if(p>=3*a) goto ending;
        else
        {
     again: if(k<d-2&&S[k]=='A'&&(S[k-1]=='P'||S[k-2]=='P')&&(S[k+1]=='P'||S[k+2]=='P')) {p++;a--;k++;pr++;}
            else if(k<d-3) {k++;goto again;}
            else goto badending;
        }
        goto loop;
ending: printf("%d\n",pr);
        goto endi;
badending: printf("-1\n");
endi:;
    }
    return 0;
}
