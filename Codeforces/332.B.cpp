#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	vector<long long> X(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>X[i];
	}
	for(int i=1;i<=n;i++)	//Prefix Sum
	{
		X[i]+=X[i-1];
	}

	vector<pair<long long,int>> dp(n+1);	//dp[i] -> BestSubarray from i to end
	dp[n-k+1] = {X[n]-X[n-k],n-k+1};		//dp[i].first -> Sum, dp[i].second -> Index

	for(int i=n-k;i>k;i--)
	{
		if(X[i+k-1]-X[i-1]>=dp[i+1].first)	//Transition: Check subarray starting at i
		{
			dp[i] = {X[i+k-1]-X[i-1],i};	
		}
		else
		{
			dp[i] = dp[i+1];
		}
	}
	int ind1=0,ind2=0;
	long long ans=0;
	for(int i=1;i<=n-2*k+1;i++)				//Check for every first subarray.
	{
		if(X[i+k-1]-X[i-1]+dp[i+k].first>ans)
		{
			ind1=i;
			ind2=dp[i+k].second;
			ans=X[i+k-1]-X[i-1]+dp[i+k].first;
		}	
	}
	cout<<ind1<<" "<<ind2<<endl;
}