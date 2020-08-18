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
#define forn(f,n) for(int i=f;i<f+n;i++)
#define rforn(l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i];
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 1005;
/////////////////FastExp///////////////////
ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}
/////////////////FastExp///////////////////
//////////////////Sieve////////////////////
vector<bool> is_prime(MAX+1, true);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
        	for (j = i * i; j <= MAX; j += i)
            	is_prime[j] = false;
    	}
	}
}
//////////////////Sieve////////////////////



int main()
{
	int n;
	cin>>n;
	vector<vpii> M(n+5,vpii(n+5));
	vector<vector<char>> V(n+5,vector<char> (n+5));
	bool ans=true;
	set<pii> P;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x,y;
			cin>>x>>y;
			M[i][j]={x,y};

			if(x!=-1&&y!=-1) {P.insert({x,y});V[x][y]='X';}
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(V[i][j]=='X')
			{
				if(i!=M[i][j].first||j!=M[i][j].second)
				{
					ans=false;
					break;
				}
			}
		}
		if(!ans) break;
	}

	if(!ans) {cout<<"INVALID"<<endl;return 0;}
	vector<vector<bool>> B(n+5,vector<bool> (n+5));
	int done=0;
	while(done<n*n)
	{
		set<pii> TA;
		for(auto p:P)
		{
			int x=p.first,y=p.second;
			if(B[x][y]) continue;
			B[x][y]=true;
			done++;
			if(M[x-1][y]==p&&!B[x-1][y]) {V[x-1][y]='D';TA.insert({x-1,y});}
			else if(M[x+1][y]==p) {V[x+1][y]='U';TA.insert({x+1,y});}
			else if(M[x][y-1]==p) {V[x][y-1]='R';TA.insert({x,y-1});}
			else if(M[x][y+1]==p) {V[x][y+1]='L';TA.insert({x,y+1});}
			else
			{
				ans=false;
				break;
			}
		}
		for(auto t:TA)
		{
			cout<<t.first<<" "<<t.second<<endl;
		}
		if(!ans) break;
		for(auto t:TA)
		{
			cout<<t.first<<" "<<t.second<<endl;
		}
		P=TA;
	}
	

	if(!ans) cout<<"INVALID"<<endl;
	else
	{
		cout<<"VALID"<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<V[i][j];
			}
			cout<<endl;
		}
	}
}		