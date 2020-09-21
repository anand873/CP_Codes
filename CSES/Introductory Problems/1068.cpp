//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin>>n;
	cout<<n;
	while(n>1)
	{
		if(n%2==0) n/=2;
		else n = 3*n+1;

		cout<<" "<<n;
	}
	cout<<'\n';
}	