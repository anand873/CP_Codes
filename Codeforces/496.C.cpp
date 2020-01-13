#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<string> V(n+1);
	for(int i=1;i<=n;i++) cin>>V[i];
	set<int> S;
	int ans=0;
up:	int ansold=S.size();
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(S.count(j)) continue;
			else if(V[i][j]>V[i-1][j]) break;
			else if(V[i][j]==V[i-1][j]) continue;
			else S.insert(j);
		}
	}
	int ansnew=S.size();
	if(ansnew!=ansold) goto up; 
	cout<<S.size()<<endl;
}