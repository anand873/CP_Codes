#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>

int main()
{
    char o;
    int c=1,d=0;
    scanf("%c",&o);
    char p='1';
    while(p!='\n')
    {
        scanf("%c",&p);
        c++;
        if(p=='1') d=1;
    }
    c--;
    if(d==0) printf("%d\n",c/2);
    else
    {
        printf("%d\n",c/2+c%2);
    }

}
