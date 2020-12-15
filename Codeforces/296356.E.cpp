//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> A(n);
	for(auto &a:A)
	{
		cin>>a;
	}
	map<int,int> M;
	for(auto a:A) M[a]++;
	set<int> D;
	for(int i=1;i*i<=k;i++)
	{
		if(k%i==0)
		{
			D.insert(i);
			D.insert(k/i);
		}
	}
	ll ans = 0;
	for(auto m:M)
	{
		int num = m.first;
		for(auto d:D)
		{
			if(M.find(num+d)!=M.end()) ans += 2;
			if(M.find(num-d)!=M.end()) ans += 2;
		}
	}
	cout<<ans/2<<endl;
}		