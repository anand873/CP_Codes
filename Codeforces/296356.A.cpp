//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sq(ll x)
{
	return x*x;
}

int main()
{
	ll l;
	cin>>l;
	ll x,y;
	cin>>x>>y;
	if(x>y) swap(x,y);
	cout<<max({sq(min(x-1,l)),sq(min(y-1,l)),sq(min(l-x,l)),sq(min(l-y,l))})<<endl;
}	