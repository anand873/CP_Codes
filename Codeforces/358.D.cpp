#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	int n;
	cin>>n;
	vi A(n+1),B(n+1),C(n+1);
	take(A,1,n);
	take(B,1,n);
	take(C,1,n);
	
	vector<vi> dp(n+1,vi(2));
	dp[n][0] = A[n];
	dp[n][1] = B[n];

	for(int i=n-1;i>0;i--)
	{
		dp[i][0] = max(dp[i+1][0]+B[i],dp[i+1][1]+A[i]);
		dp[i][1] = max(dp[i+1][0]+C[i],dp[i+1][1]+B[i]);
	}
	cout<<dp[1][0]<<endl;

}