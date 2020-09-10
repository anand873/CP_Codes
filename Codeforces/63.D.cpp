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
	fastio
	int a,b,c,d,n;
	cin>>a>>b>>c>>d>>n;
	vi X(n);
	take(X,0,n);
	char curr='a';
	vector<vector<char>> V(max(b,d),vector<char>(a+c));
	if(b>=d)
	{
		bool flip=false;
		if(d%2) flip=true; 
		for(int i=0;i<b;i++)
		{
			if(flip)
			{
				for(int j=a+c-1;j>=0;j--)
				{
					if(i<d||j<a)
					{
						V[i][j] = curr;
						X[curr-'a']--;
						if(X[curr-'a']==0) curr++;
					}
					else V[i][j] = '.';
				}
				flip = !flip;
			}	
			else
			{
				for(int j=0;j<a+c;j++)
				{
					if(i<d||j<a)
					{
						V[i][j] = curr;
						X[curr-'a']--;
						if(X[curr-'a']==0) curr++;
					}
					else V[i][j] = '.';
				}
				flip = !flip;
			}
		}
	}
	else
	{
		bool flip=true;
		if(b%2) flip=false; 
		for(int i=0;i<d;i++)
		{
			if(flip)
			{
				for(int j=a+c-1;j>=0;j--)
				{
					if(i<b||j>=a)
					{
						V[i][j] = curr;
						X[curr-'a']--;
						if(X[curr-'a']==0) curr++;
					}
					else V[i][j] = '.';
				}
				flip = !flip;
			}	
			else
			{
				for(int j=0;j<a+c;j++)
				{
					if(i<b||j>=a)
					{
						V[i][j] = curr;
						X[curr-'a']--;
						if(X[curr-'a']==0) curr++;
					}
					else V[i][j] = '.';
				}
				flip = !flip;
			}
		}
	}
	cout<<"YES"<<endl;
	for(int i=0;i<max(b,d);i++)
	{
		for(int j=0;j<a+c;j++) cout<<V[i][j];
		cout<<endl;
	}
}	