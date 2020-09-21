//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int n;
	cin>>n;
	vector<int> P(n);
	for(auto &p:P) cin>>p;
	ll sum = 0;
	ll ans = 1e16+5;
	for(int i=0;i<n;i++) sum += P[i];

	for(int mask=0;mask<(1<<n);mask++)
	{
		ll temp=0;
		for(int j=0;j<n;j++)
		{
			if((mask>>j)&1) temp += P[j];
		}
		ans = min(ans,abs(sum-2*temp));
	}
	cout<<ans<<endl;
}	