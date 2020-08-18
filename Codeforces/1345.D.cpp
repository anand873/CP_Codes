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
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 1e5+5;
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
vector<bool> is_prime(MAX, true);
vector<int> MinDiv(MAX);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
    		MinDiv[i]=i;
        	for (j = i * i; j <= MAX; j += i)
            {
				is_prime[j] = false;
				MinDiv[j]=i;
    		}
    	}
	}
}
//////////////////Sieve////////////////////

int main()
{
	int n,m;
	cin>>n>>m;
	vector<string> V(n);
	take(V,0,n);
	bool ans=true;
	set<int> Z,S;
	int cnt=0;

	for(int j=0;j<m;j++)
	{
		int blk=0;
		int i=0;
		while(i<n)
		{
			int x=0;
			while(i<n&&V[i][j]=='.') i++;
			while(i<n&&V[i][j]=='#') {x++;i++;}
			if(x!=0)
			{
				blk++;
			}
		}
		if(blk>=2) {ans=false;break;} 
	}	
	if(!ans) {cout<<-1<<endl;return 0;}

	for(int i=0;i<n;i++)
	{
		int blk=0;
		int j=0;
		while(j<m)
		{
			int x=0;
			while(j<m&&V[i][j]=='.') j++;
			while(j<m&&V[i][j]=='#') {S.insert(j);x++;j++;}
			if(x!=0)
			{
				blk++;
			}
		}
		if(blk==0)
		{
			Z.insert(i);
		}
		else if(blk==1)
		{
			j=0;
			while(j<m&&V[i][j]=='.') j++;
			bool used=true;
			while(j<m&&V[i][j]=='#')
			{
				if(i!=0)
				{
					if(V[i-1][j]=='#') used=false;
				}
				j++;
			}
			if(used) cnt++;
		}
		else {ans=false;break;}
	}
	if(!ans) cout<<-1<<endl;
	else
	{
		if(Z.size())
		{
			if(S.size()) cout<<cnt<<endl;
			else cout<<-1<<endl;
		}
		else cout<<cnt<<endl;
	}

}		