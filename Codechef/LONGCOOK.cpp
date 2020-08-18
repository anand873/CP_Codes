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
#define test(t) int t;cin>>t;while(t--)
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define what(x) cerr<<#x<<" = "<<x<<endl

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

bool is_leap(int y)
{
	if(((y%100==0&&y%400!=0)||y%4!=0)) return false;
	else return true;
}

int main()
{	
	vi YM(401);
	YM[1]=4;
	for(int i=2;i<=400;i++)
	{
		if(!is_leap(i-1))
			YM[i]=(YM[i-1]+1)%7;
		else YM[i]=(YM[i-1]+2)%7;
	}
	int cnt=0;
	for(int i=1;i<=400;i++)
	{
		if((YM[i]==0&&!is_leap(i))||YM[i]==6) cnt++;
	}
	test(t)
	{
		int m1,m2,y1,y2;
		cin>>m1>>y1>>m2>>y2;

		int cnty1=0,cnty2=0;
		if(m1<=2) y1--;
		if(m2<2) y2--;

		cnty1=(y1/400)*cnt;
		y1%=400;
		for(int i=1;i<=y1;i++)
		{
			if((YM[i]==0&&!is_leap(i))||YM[i]==6) cnty1++;
		}

		cnty2=(y2/400)*cnt;
		y2%=400;
		for(int i=1;i<=y2;i++)
		{
			if((YM[i]==0&&!is_leap(i))||YM[i]==6) cnty2++;
		}
		
		cout<<cnty2-cnty1<<endl;
	}
}		