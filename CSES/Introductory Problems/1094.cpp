//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin>>n;
	vector<int> X(n);
	for(auto &x:X) cin>>x;
	ll ans=0;
	for(int i=1;i<n;i++)
	{
		ans += max(0,X[i-1]-X[i]);
		X[i] = max(X[i-1],X[i]);
	}
	cout<<ans<<endl;
}	