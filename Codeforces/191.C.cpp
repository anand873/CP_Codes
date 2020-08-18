#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vvi A(n+1);
	vpii E;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		if(u>v) swap(u,v);
		E.push_back({u,v});
		A[u].push_back(v);
		A[v].push_back(u);
	}

	int k;
	cin>>k;
	

}