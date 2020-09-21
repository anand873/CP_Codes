//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin>>n;
	if(n==3||n==2) cout<<"NO SOLUTION"<<endl;
	else
	{
		for(int i=1;2*i<=n;i++) cout<<2*i<<" ";
		for(int i=0;1+i*2<=n;i++) cout<<2*i+1<<" ";
		cout<<'\n';
	}
}	