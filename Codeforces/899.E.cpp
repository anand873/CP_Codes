//Author: AnandRaj doubleux
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
	vi A(n);
	take(A,0,n);
	set<pii> Len,Pos;
	int currlen=1,curr=A[0];
	for(int i=1;i<n;i++)
	{
		if(curr==A[i])
		{
			currlen++;
		}
		else
		{
			Len.insert({-currlen,i-currlen});
			Pos.insert({i-currlen,currlen});
			curr=A[i];
			currlen=1;
		}
	}
	Len.insert({-currlen,n-currlen});
	Pos.insert({n-currlen,currlen});
	
	int ans = 0;
	while(!Len.empty())
	{
		ans++;
		auto longest = Len.begin();

		auto left = Pos.lower_bound({longest->second,0});
		auto right = Pos.upper_bound({longest->second,n});
		if(left==Pos.begin()||right==Pos.end())
		{
			Pos.erase({longest->second,-(longest->first)});
			Len.erase(*longest);
		}
		else
		{
			left--;
			if(A[left->first]==A[right->first])
			{
				pii X = {-(left->second+right->second),left->first};
				pii Y = {left->first,left->second+right->second};
				pii Pe = {longest->second,-(longest->first)};
				pii L = *left;
				pii R = *right;
				pii Le = *longest;
				pii LL = {-left->second,left->first};
				pii LR = {-right->second,right->first};
				
				Len.erase(Le);
				Len.erase(LL);
				Len.erase(LR);
				Len.insert(X);

				Pos.erase(L);
				Pos.erase(R);
				Pos.erase(Pe);
				Pos.insert(Y);

				
			}
			else
			{
				Pos.erase({longest->second,-(longest->first)});
				Len.erase(*longest);
			}
		}
	}
	cout<<ans<<endl;
}	