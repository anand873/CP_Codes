#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX = 1e6 + 5;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<vector<int>> V;
vector<int> C;
vector<map<int,int>> M;


void find_child(int u,int p)
{
	int x = u;
	while(V[x].size()==1)
	{
		C[x] = p;
		x = V[x][0];
	}
	while(V[u].size()==1)
	{
		C[u] = x;
		u = V[u][0];
	}
	C[u] = u;
	for(auto v:V[u])
	{
		find_child(v,u);
	}
}

void find_paths(int u)
{
	u = C[u];
	int num_child = V[u].size();
	if(V[u].size()==0)
	{
		M[u][1] = 1;
	}
	for(int v:V[u])
	{
		find_paths(v);
		for(auto m:M[C[v]])
		{
			if(m.first == -1) M[u][-1] = m.second;
			else
			{
				if(m.first * num_child > MAX)
				{
					M[u][-1] += m.second;
				}
				else M[u][m.first * num_child] += m.second;
			}
		}
	}

}

int main()
{
	fastio
	int n;
	cin>>n;
	V.resize(n+1);
	C.resize(n+1,-1);
	M.resize(n+1);
	for(int i=1;i<n;i++)
	{
		int p;
		cin>>p;
		V[p].push_back(i+1);
	}
	find_child(1,1);
	find_paths(1);
	int q;
	cin>>q;
	while(q--)
	{
		int v,w;
		cin>>v>>w;
		v = C[v];
		int ans = 0;
		for(auto m:M[v])
		{
			if(m.first==-1) continue;
			if(w%m.first==0)
			{
				ans += (ll)m.second*(w/m.first);
			}
		}
		cout<<w - ans<<"\n";
	}
	for(auto c:C) cout<<c<<" ";
	cout<<endl;
}