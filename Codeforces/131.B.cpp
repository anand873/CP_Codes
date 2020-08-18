#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	map<int,long long> M;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		M[t]++;
	}
	long long ans=0;
	for(auto t:M)
	{
		if(t.first==0)
		{
			ans+=t.second*(t.second-1);
		}
		else
		{
			ans+=M[t.first]*M[-t.first];
		}
	}
	cout<<ans/2<<endl;
}