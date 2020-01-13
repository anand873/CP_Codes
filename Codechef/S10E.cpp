#include <bits/stdc++.h>
using namespace std;
#define N 1000000007

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i;
		int a,b,c,d,e,cnt=0;
		a=b=c=d=e=INT_MAX;
		for(i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(x<min(a,min(b,min(c,min(d,e))))) cnt++;
			a=b;
			b=c;
			c=d;
			d=e;
			e=x;
		}
		cout<<cnt<<endl;
	}
}