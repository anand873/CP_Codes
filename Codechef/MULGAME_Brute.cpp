#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e3 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,q,lim;
		n = 10;
		q = 10;
		lim = 100;
		// cin>>n>>q>>lim;
		vector<int> A(n);
		A[0] = rng()%10 + 1;
		for(int i=1;i<n;i++)
		{
			A[i] = A[i-1] + 1 + rng()%A[0];
		}
		for(auto a:A) cout<<a<<" ";
		cout<<endl;
		vector<vector<int>> M(lim+10);
		for(int i=0;i<q;i++)
		{
			int l,r;
			// cin>>l>>r;
			l = rng()%n;
			r = l + rng()%(n-l);
			cout<<A[l]<<" "<<A[r]<<endl;
			int fir = A[l],sec = A[l]+A[r]-1;
			while(1)
			{
				for(int j=fir;j<min(lim+10,sec+1);j++)
				{
					M[j].push_back(i+1);
				}
				fir += A[l] + A[r];
				sec += A[l] + A[r];
				if(fir>=lim+10) break;
			}
		}
		for(int i=1;i<lim+10;i++)
		{
			cout<<i<<": ";
			for(auto m:M[i]) cout<<m<<" ";
			cout<<endl;
		}
	}
}