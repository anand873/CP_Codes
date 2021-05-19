#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> W(n);
		map<int,int> L;
		for(int i=0;i<n;i++)
		{
			cin>>W[i];
		}
		for(int i=0;i<n;i++)
		{
			int l;
			cin>>l;
			L[W[i]] = l;
		}
		set<pair<int,int>> Wp;
		for(int i=0;i<n;i++) Wp.insert({W[i],i});
		int ans = 0;
		while(Wp.size()>1)
		{
			auto small = *Wp.begin();
			int pos = small.second;
			set<pair<int,int>> NWp;
			for(auto w:Wp)
			{
				if(w==small) continue;
				int jump = 0;
				if(w.second<=pos)
				{
					jump = (pos - w.second + L[w.first])/L[w.first];
				}
				ans += jump;
				NWp.insert({w.first,w.second + jump*L[w.first]});
			}
			Wp = NWp;
		}
		cout<<ans<<endl;

	}
}