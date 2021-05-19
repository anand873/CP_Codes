#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX = 1e6 + 5;
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll val(int x1, int y1, int x2, int y2, int x, int y)
{
	return (ll)(y-y1)*(x2-x1) - (ll)(x-x1)*(y2-y1);
}

int main()
{
	int n,m,r;
	cin>>n>>m>>r;
	map<pair<int,int>, vector<int>> M;
	vector<pair<int,int>> P(n+1);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		P[i] = {x,y};
	}

	for(int i=1;i<=m;i++)
	{
		vector<int> PP(3);
		cin>>PP[0]>>PP[1]>>PP[2];
		sort(PP.begin(), PP.end());
		M[{PP[0],PP[1]}].push_back(PP[2]);
		M[{PP[0],PP[2]}].push_back(PP[1]);
		M[{PP[1],PP[2]}].push_back(PP[0]);
	}
	for(int i=1;i<=r;i++)
	{
		int b;
		cin>>b;
	}
	set<pair<int,int>> Flippable;
	vector<pair<int,int>> Flips;
	set<pair<int,int>> Poss_Lines;
	for(auto m:M)
	{
		if(m.second.size()==2)
		{
			Poss_Lines.insert(m.first);
		}
	}

	// for(auto line:Poss_Lines)
	// {
	// 	int x3 = P[M[line][0]].first;
	// 	int y3 = P[M[line][0]].second;

	// 	int x4 = P[M[line][1]].first;
	// 	int y4 = P[M[line][2]].first;

	// 	int x1 = P[line.first].first;
	// 	int y1 = P[line.first].second;

	// 	int x2 = P[line.second].first;
	// 	int y2 = P[line.second].second;

	// 	if(val(x1,y1,x2,y2,x3,y3) * val(x1,y1,x2,y2,x4,y4) <= 0)
	// 	{
	// 		if(val(x3,y3,x4,y4,x1,y1) * val(x3,y3,x4,y4,x2,y2) <= 0)
	// 		{
	// 			Flippable.insert(line);
	// 		}
	// 	}
	// }

	// int F = 1;
	// for(int i=0;i<F;i++)
	// {
	// 	if(Flippable.empty()) break;
	// 	int which = rng()%Flippable.size();
	// 	int curr=0;
	// 	for(auto f:Flippable)
	// 	{
	// 		// cout<<f.first<<" "<<f.second<<endl;
	// 		if(curr==which)
	// 		{
	// 			Flips.push_back(f);
	// 			int x = M[f][0];
	// 			int y = M[f][1];
	// 			if(x>y) swap(x,y);
	// 			Flippable.erase({x,y});
	// 			Poss_Lines.erase({x,y});
	// 			Flippable.insert({x,y});
	// 			Poss_Lines.insert({x,y});
	// 			// cout<<x<<","<<y<<endl;
	// 			break;
	// 		}
	// 		curr++;
	// 	}
	// }
	// cout<<Flips.size()<<endl;
	// for(auto line:Flips)
	// {
	// 	cout<<line.first<<" "<<line.second<<endl;
	// }
	cout<<0<<endl;
	for(int i=0;i<m-r;i++)
	{
		int which = rng()%Poss_Lines.size();
		int curr=0;
		for(auto f:Poss_Lines)
		{
			if(curr==which)
			{
				cout<<f.first<<" "<<f.second<<endl;
				Poss_Lines.erase(f);
				break;
			}
			curr++;
		}
	}
}