//Author: AnandRaj uux
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpll; 

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;

int main()
{
	int n;
	cin>>n;
	vi A(n+1);
	take(A,1,n);
	set<int> taken_row_right,avail_row;
	set<pii> S;
	for(int i=1;i<=n;i++) avail_row.insert(i);
	bool can=true;
	set<pii> AvailCols;
	for(int i=1;i<=n;i++)
	{
		if(A[i]) AvailCols.insert({n+1,i});
	}

	for(int i=n;i>=1;i--)
	{
		if(A[i]==1)
		{
			int next_row;
			if(avail_row.empty())
			{
				can=false;break;
				// next_row = *avail_row.begin();
			}
			else next_row = (*avail_row.begin());
			
			taken_row_right.insert(next_row);
			S.insert({next_row,i});
			AvailCols.erase({n+1,i});
			AvailCols.insert({next_row,i});
			avail_row.erase(next_row);
		}
		else if(A[i]==2)
		{
			if(taken_row_right.empty())
			{
				can=false;
				break;
			}
			else
			{
				int next_row = *taken_row_right.begin();
				S.insert({next_row,i});
				taken_row_right.erase(next_row);
				AvailCols.erase({n+1,i});
				AvailCols.insert({next_row,i});
			}
		}
		else if(A[i]==3)
		{
			if(AvailCols.empty())
			{
				can=false;
				break;
			}
			int col = AvailCols.begin()->second;
			int row = AvailCols.begin()->first+1;
			if(avail_row.empty())
			{
				can=false;
				break;
			}
			row = *avail_row.lower_bound(row);
			S.insert({row,i});
			AvailCols.erase(*AvailCols.begin());
			AvailCols.erase({n+1,i});
			AvailCols.insert({row,i});
			S.insert({row,col});
			avail_row.erase(row);
			taken_row_right.erase(row);
		}
	}
	if(!can)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<S.size()<<endl;
		for(auto s:S)
		{
			prinp(s);
		}
	}

}	