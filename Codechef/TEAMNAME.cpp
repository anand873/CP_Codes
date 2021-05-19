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
		vector<string> V(n);
		for(int i=0;i<n;i++)
		{
			cin>>V[i];
		}
		map<char,int> F;
		map<pair<char,char>, int> FS;
		map<string,vector<char>> M;
		for(int i=0;i<n;i++)
		{
			string suff = V[i].substr(1,V[i].length()-1);
			M[suff].push_back(V[i][0]);
		}
		for(auto psuff:M)
		{
			auto vc = psuff.second;
			sort(vc.begin(), vc.end());
			for(int i=0;i<vc.size();i++)
			{
				F[vc[i]]++;
				for(int j=i+1;j<vc.size();j++)
				{
					FS[{vc[i],vc[j]}]++;
				}
			}
		}
		int ans = 0;
		for(int i=0;i<26;i++)
		{
			for(int j=i+1;j<26;j++)
			{
				char f = 'a' + i;
				char s = 'a' + j;

				ans += (F[f] - FS[{f,s}])*(F[s] - FS[{f,s}]);
			}
		}
		cout<<2*ans<<endl;

	}
}