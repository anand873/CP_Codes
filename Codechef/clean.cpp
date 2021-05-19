#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rb  pop_back
#define rf  pop_front
#define ins insert
#define f   first
#define s   second
#define um  unordered_map
#define us  unordered_set
#define pq  priority_queue

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef pair< long long int ,long long int > iil;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector< ll > vl;
typedef vector< vl > vvl;
typedef vector<double> vd;
typedef pair<double,double> pd;
typedef queue<int> qi;
typedef queue<double> qd;
typedef queue<ll> qll;
typedef us<int> si;
typedef us<double> sd;
typedef us<ll> sll;
typedef vector<vd> md;


const int MAX = 1e6;
const int N = 200043;
const int MOD = 998244353;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define EE endl
#define PI 3.14159265
#define maximum(a,b) a>b?a:b
#define minimum(a,b) a<b?a:b
#define SOT(A) sort(A.begin(),A.end())
#define SOTR(A) sort(A.rbegin(),A.rend())
#define REV(a) reverse(ALL(a))

// LOOP Control Statements
#define forn(i,j,n) for ( auto i=j ; i<n ; i++ )
#define fornd(i,j,n) for ( auto i=j ; i>n ; i-- )
#define FORE(i, b) for(auto &i:b)


#define SQ(i) (i*i)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define IN(a, b) (a.find(b) != a.end())
#define BACK(a) a.back(); a.RB()
#define QBACK(a) a.top(); a.pop()
#define PRINT(a) FORE(i, a) cout << i << " "; cout << endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define tcase(term) int tc;cin>>tc;for(int term=0; term<tc;term++)

ll mul(ll x, ll y) {return (x * 1ll * y) % MOD;}
ll binpow(ll x, ll y){
    ll z = 1;
    while(y){
        if(y & 1) z = mul(z, x);
        z%=MOD;
        x = mul(x, x)%MOD;
        y >>= 1;
    }
    return z%MOD;
}
ll inv(ll x) {return binpow(x, MOD - 2);}
ll divide(ll x, ll y) {return mul(x, inv(y));}
ll fact[N+1],INV[N+1];
vl bitdp;
ll NN=1<<18;
ll C(ll n, ll k){
	if(n<k or k<0 or n<0) return 0;
	return mul(fact[n], mul(INV[k], INV[n - k]))%MOD;
}

///////////////////////////////////////////////////  CP STUFF ENDS HERE ///////////////////////////////////////////////////////////////////////////////////////
const int mod = 998244353;
const ll root = 996173970;
const ll root_1 = 121392023;
const ll root_pw = 262144;
vl fft(vl & a, bool invert) {
    ll n = a.size();
    
    int d=0;
    while((n<<d) !=NN) d++;
    forn(i,0,n){
    	if(i< (bitdp[i]>>d)){
    		swap(a[i],a[bitdp[i]>>d]);
    	}
    }

    for (ll len = 2; len <= n; len <<= 1) {
        ll wlen = invert ? root_1 : root;
        for (ll i = len; i < root_pw; i <<= 1)
            wlen = (ll)(1LL * wlen * wlen % mod);

        for (ll i = 0; i < n; i += len) {
            ll w = 1;
            for (ll j = 0; j < len / 2; j++) {
                ll u = a[i+j], v = (ll)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (ll)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        ll n_1 = inv(n);
        for (auto & x : a)
            x = (ll)(1LL * x * n_1 % mod);
    }
    
    return a;
}
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
	
    vl fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    
    fa.resize(n);
    fb.resize(n);
    

    fa= fft(fa, false);
    fb= fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] = (fa[i]*fb[i])%MOD;
    fa = fft(fa, true);
    return fa;

}

void fastscan(int &x)
    {
        bool neg=false;
        register int c;
        x =0;
        c=getchar();
        if(c=='-')
        {
            neg = true;
            c=getchar();
        }
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
    }

int main()
{
	bitdp.resize(NN+1);
	forn(i,1,NN) bitdp[i]=bitdp[i>>1]>>1 | ((i&1)<<17);
    fact[0] = 1;
    for(ll i = 1; i <=N; i++) fact[i] = mul(fact[i - 1], i);
    INV[N]=binpow(fact[N],MOD-2);
    fornd(i,N-1,-1) INV[i]=((ll)INV[i+1]*(i+1))%MOD;
	{	
		int n,t;
        fastscan(n);
		vl A(n,0);
		forn(i,0,n) {fastscan(t);A[i]=t;}
		vi D(32,0);
		vl Q(n+1,0);
		forn(i,0,n){
			forn(j,0,32){
				D[j]+=(A[i]>>j)&1;
			}
			Q[1]+=A[i];
			Q[1]%=MOD;
		}
		map<int,vl> mps;
		forn(i,0,32){
			if(present(mps,D[i])) continue;
			vl A,B;
			forn(j,0,(D[i]+1)){ 
				ll x=C(D[i],j);
				A.pb((j%2? x:0));
			}
			forn(j,0,(n-D[i]+1)) B.pb(C(n-D[i],j));
			mps[D[i]]=multiply(A,B);
		}
		vl powers;
		forn(i,0,32) powers.pb(binpow(2,i));
		forn(m,2,n+1){
			ll ans=0;
			forn(i,0,32){
				ans+=(mps[D[i]][m]*powers[i])%mod;
				ans%=mod;
			}
			Q[m]=(Q[m-1]+ans)%mod;
		}
		int q;
		fastscan(q);
		int x;
		forn(i,0,q){
            fastscan(x);
			printf("%d\n",Q[x]);
		}
	}
}




