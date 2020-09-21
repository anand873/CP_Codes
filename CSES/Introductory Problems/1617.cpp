//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

ll powN(ll a,ll n)
{
	if(n==0) return 1;
	ll z = powN(a,n/2);
	z = (z*z)%MOD;
	if(n%2) z*=a;

	return z%MOD;
}

int main()
{
	int n;
	cin>>n;
	cout<<powN(2,n)<<endl;
}	