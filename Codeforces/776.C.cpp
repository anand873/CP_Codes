#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e15;

int main()
{
	int n,k;
	cin>>n>>k;
	vector<ll> A(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
	}

	for(int i=1;i<=n;i++)
	{
		A[i]+=A[i-1];
		// cout<<A[i]<<" ";
	}
	vector<ll> P;
	if(k==1)
	{
		P.push_back(1);
	}
	else if(k==-1)
	{
		P.push_back(1);
		P.push_back(-1);
	}
	else
	{
		ll p=1;
		while(p<1e15)
		{
			P.push_back(p);
			p*=k;
		}
	}

	// cout<<endl;
	ll ans=0;
	map<ll,int> M;
	M[0]++;
	for(int i=1;i<=n;i++)
	{
		ll curr = A[i];
		for(auto p:P)
		{
			if(M.find(curr-p)!=M.end())
			{
				ans+=M[curr-p];
			}
			p*=k;
		}
		M[curr]++;
	}
	// for(auto m:M)
	// {
	// 	cout<<m.first<<" "<<m.second<<endl;
	// }
	cout<<ans<<endl;

}