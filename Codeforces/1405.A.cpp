//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> P(n);
	for(int i=0;i<n;i++)
	{
		cin>>P[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<P[n-1-i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}	