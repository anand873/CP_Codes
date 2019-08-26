#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#define m 1000000000

void fastscan(int &number)
{
    bool negative = false;
    register int c;

    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j=1;
        scanf("%d",&n);
        int color[n];
        for(i=0;i<n;i++)
        {
            fastscan(color[i]);
        }
        int arr[m],count=0;
        for(i=0;i<m;i++) arr[i]=0;
        for(i=0;i<n;i++)
        {
            if(color[i]==0) arr[color[i]]--;
            if(color[i]=-1) count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
