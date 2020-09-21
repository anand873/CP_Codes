//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		if(a>b) swap(a,b);
		if(b<=2*a&&(a+b)%3==0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}	