#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,q,lim;
		cin>>n>>q>>lim;
		vector<int> A(n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>A[i];
		}
		map<pair<int,int>,int> D;
		vector<int> M(lim+10);
		for(int i=0;i<q;i++)
		{
			int l,r;
			cin>>l>>r;
			if(A[l]<=lim)
			{
				D[{A[l],A[r]}]++;
			}
		}
		for(auto d:D)
		{
			int al = d.first.first;
			int ar = d.first.second;
			int x = al,y = ar;
			while(al<lim+10)
			{
				M[al] += d.second;
				if(al+ar<lim+10) M[al + ar] -= d.second;
				al += x+y;
			}
		}
		for(int i=1;i<lim+10;i++)
		{
			M[i] += M[i-1];
		}
		int ans = 0;
		for(int i=1;i<=lim;i++)
		{
			ans = max(ans,M[i]);
		}
		cout<<ans<<endl;
	}
}