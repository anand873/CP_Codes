//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

int main()
{
	int n;
	cin>>n;
	int ans = 0;
	while(n)
	{
		ans += n/5;
		n/=5;
	}
	cout<<ans<<endl;
}	