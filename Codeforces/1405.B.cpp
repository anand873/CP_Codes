//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++) cin>>A[i];
	vector<long long> dp(n);
	long long ans = A[n-1];
	dp[n-1] = A[n-1];
	for(int i=n-2;i>=0;i--)
	{
		dp[i] = dp[i+1]+A[i];
		ans = max(ans,dp[i]);
	}
	cout<<ans<<endl;
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