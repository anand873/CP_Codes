//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin>>n;
	if(((n+1)*n/2)%2) cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		ll sum = n*(n+1)/2;
		sum/=2;
		set<int> S1;
		for(int curr = n;curr>=1;curr--)
		{
			if(sum>=curr)
			{
				S1.insert(curr);
				sum-=curr;
			}
		}
		cout<<S1.size()<<endl;
		for(auto s:S1) cout<<s<<" ";
		cout<<endl;
		cout<<n-S1.size()<<endl;
		for(int i=1;i<=n;i++)
		{
			if(!S1.count(i)) cout<<i<<" ";
		}
		cout<<endl;
	}
}	