#include<bits/stdc++.h>
using namespace std;
 
typedef vector<int > vi;
typedef vector< vi > vvi;
typedef pair< int, int > ii;
#define sz(a)  int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define forn(i,n) for(int i=0;i<n;++i)
#define foru(i,n) for(int i=1;i<=n;++i)
#define fortr(i,v) for(auto &i:v)
#define set(n) __builtin_popcount(n)
#define ll long long
#define ld long double
const int MOD = 998244353;
/////////////////FastExp///////////////////
ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}
//////////////ModularInverse///////////////
ll modInv(ll a)
{
	return powN(a,MOD-2);
}
int main()
{
   ll n;
   cin>>n;
   ll int A[1000001],siz;
   forn(i,1000001)
     A[i]=0;
   vector<ll int> B[n];int r;
   forn(i,n)
   {
       cin>>siz;
       forn(j,siz)
       {
           cin>>r;
           B[i].pb(r);
           ++A[r];
       }
   }
   ll int C[n];
   forn(i,n)
   {
       C[i]=0;
       forn(j,B[i].size())
       {
           C[i]+=A[B[i][j]];
       }
   }
   ll sum=0;
   ll x,y,prev_x,prev_y;
   prev_x=prev_y=1;
   forn(i,n)
   {
 
       x=C[i];
       y=B[i].size();
       ll gcd=__gcd(x,y);
       x=x/gcd;
       y=y/gcd;
       sum+=x*modInv(y);
       sum%=MOD;
 
   }
   sum=(((sum*modInv(n))%MOD)*modInv(n))%MOD;
   cout<<sum<<endl;
 
}