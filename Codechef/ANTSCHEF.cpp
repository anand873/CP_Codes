#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		unordered_map<int,int> M;
		vector<vector<int>> X(n);
		for(int i=0;i<n;i++)
		{
			int m;
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				int x;
				scanf("%d",&x);
				M[abs(x)]++;
				X[i].push_back(x);
			}
		}
		long long ans = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<X[i].size();j++)
			{
				if(X[i][j]<0)
				{
					if(M[abs(X[i][j])]>1)
					{
						ans += upper_bound(X[i].begin(), X[i].end() ,abs(X[i][j])) - lower_bound(X[i].begin(), X[i].end() ,0) + 2*j;
					}
					else
					{
						ans += X[i].end() - lower_bound(X[i].begin(), X[i].end() ,0); 
					}
				}
				else
				{
					if(M[abs(X[i][j])]>1)
					{
						ans += upper_bound(X[i].begin(), X[i].end() ,0) - lower_bound(X[i].begin(), X[i].end() ,-X[i][j]+1) + 2*(X[i].size()-1-j);
					}
					else
					{
						ans += upper_bound(X[i].begin(), X[i].end() ,0) - X[i].begin(); 
					}
				}
			}
		}
		ans /= 2;
		for(auto m:M) if(m.second>1) ans++;
		printf("%lld\n",ans);
	}
}