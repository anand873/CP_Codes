//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isDia(int x,int y,int a,int b)
{
	return (x+y==a+b)||(x-y==a-b);
}

int main()
{
	int n = 8;
	set<pair<int,int>> B;
	for(int i=0;i<n;i++)
	{
		string m;
		cin>>m;
		for(int j=0;j<n;j++)
		{
			if(m[j]=='*') B.insert({i+1,j+1});
		}
	}
	vector<int> V = {1,2,3,4,5,6,7,8};
	int ans = 0;
	while(next_permutation(V.begin(),V.end()))
	{
		set<int> S;
		bool can=true;
		for(int i=1;i<=n;i++)
		{
			if(B.count({i,V[i-1]})) can=false;
		}
		if(!can) continue;
		else
		{
			for(int i=1;i<=8;i++)
			{
				for(int j=i+1;j<=8;j++)
				{
					if(isDia(i,V[i-1],j,V[j-1])) can=false;
				}
			}
			if(can) ans++;
		}
	}
	cout<<ans<<endl;
}	