#include <bits/stdc++.h>
using namespace std;
const int MAX=505;

set<pair<int,int>> So;
vector<string> V(MAX);
vector<bool> visited(MAX*MAX);
int n,m,k;
int cnt=0;
void dfs(int i,int j)
{
	if(cnt==k) return;
	//cout<<i<<" "<<j<<endl;
	if(!visited[i*m+j])
	{
		cnt++;
		visited[i*m+j]=true;
		So.insert({i,j});
		if(j+1<m&&V[i][j+1]=='.') dfs(i,j+1);
		if(i+1<n&&V[i+1][j]=='.') dfs(i+1,j);
		if(j-1>=0&&V[i][j-1]=='.') dfs(i,j-1);
		if(i-1>=0&&V[i-1][j]=='.') dfs(i-1,j);
	}
}

int main()
{
	
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) cin>>V[i];
	int ding=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(V[i][j]=='.') ding++;
		}
	}
	k=ding-k;
	//cout<<ding<<" "<<k<<endl;	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(V[i][j]=='.') {dfs(i,j);break;}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(V[i][j]=='.'&&So.count({i,j})==0) V[i][j]='X';
			cout<<V[i][j];
		}
		cout<<endl;
	}

}