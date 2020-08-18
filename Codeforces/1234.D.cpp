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
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
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

vector<map<char,int>> V(4*MAX);
string s;
int n;
void make_tree(int i)
{
	if(i>=2*n) return;
	if(i>=n)
	{
		V[i][(s[i-n])]++;
		return;
	}
	make_tree(2*i);
	make_tree(2*i+1);

	for(auto c:V[2*i]) V[i][c.first]+=c.second;
	for(auto c:V[2*i+1]) V[i][c.first]+=c.second;

}

void update(int pos,char c,char in)
{
	s[pos]=c;
	pos+=n;
	V[pos][in]--;
	V[pos][c]++;
	for(pos/=2;pos>=1;pos/=2)
	{
		V[pos][in]--;
		V[pos][c]++;
	}
}

int query(int i, int j)
{
	set<char> S;
	i+=n;j+=n;
	while(i<=j)
	{
		if(i%2)
		{
			for(auto x:V[i])
			{
				if(x.second>0) S.insert(x.first);
			}
			i++;
		}
		if(j%2==0)
		{
			for(auto x:V[j])
			{
				if(x.second>0) S.insert(x.first);
			}
			j--;
		}
		i/=2;
		j/=2;
	}
	return (int)S.size();
}

int main()
{
	cin>>s;
	n=s.length();
	V.resize(4*n);
	make_tree(1);
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			int pos;
			char c;
			cin>>pos>>c;
			update(pos-1,c,s[pos-1]);
		}
		else
		{
			int i,j;
			cin>>i>>j; 
			i--;
			j--;

			cout<<query(i,j)<<endl;
		}
	}
}		