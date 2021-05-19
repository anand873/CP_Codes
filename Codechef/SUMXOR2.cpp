#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll exp(int a, int p)
{
	if(p==0) return 1;
	ll z = exp(a,p/2);
	z = z * z % MOD;
	if(p&1) z = z * a % MOD;
	return z;
}

struct NTT
{
	const int g = 3;
	const int N = 1<<18;
	const int wn = exp(g,(MOD-1)/N);
	const int wn_1 = exp(wn,MOD-2);
	vector<int> bitrev;
	void init()
	{
		bitrev.resize(N+1);
		for(int i=1;i<N;i++)
		{
			bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << 17);
		}
	}

	void fft(vector<int> &a, bool invert)
	{
		int n = a.size();
		int d = 0;
		while((n<<d) != N) d++;
		for(int i=1;i<n;i++)
		{
			if(i < bitrev[i]>>d)
			{
				swap(a[i],a[bitrev[i]>>d]);
			}
		}
		for(int len=2;len<=n;len<<=1)
		{
			int wlen = invert? wn_1 : wn;
			for(int i=len;i<N;i<<=1)
			{
				wlen = (int)(1ll*wlen*wlen % MOD);
			}
			for(int i=0;i<n;i+=len)
			{
				int w = 1;
				for(int j=0;j<len/2;j++)
				{
					int u = a[i+j], v = (int)(1ll * a[i+j+len/2] * w % MOD);
					a[i+j] = u+v < MOD ? u+v : u + v - MOD;
					a[i+j+len/2] = u-v>=0 ? u-v : u-v + MOD;
					w = (int)(1ll * w * wlen % MOD); 
				}
			}
		}
		if(invert)
		{
			int n_1 = exp(n,MOD-2);
			for(int &x : a)
			{
				x = (int)(1ll * x * n_1 % MOD);
			}
		}
	}
	vector<int> multiply(vector<int> const& a, vector<int> const& b)
	{
		vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
		int n = 1;
		while(n < a.size() + b.size())
		{
			n<<=1;
		}
		fa.resize(n);
		fb.resize(n);

		fft(fa,false);
		fft(fb,false);
		for(int i=0;i<n;i++)
		{
			fa[i] = (int)(1ll * fa[i] * fb[i] % MOD);
		}
		fft(fa,true);
		return fa;
	}
};

vector<int> Fact,Inv;
ll C(int n, int r)
{		
	if(n-r<0 || r<0 || n<0) return 0;
	return ((((ll)Fact[n]*Inv[r])%MOD)*1ll*Inv[n-r])%MOD;
}

int main()
{
	fastio
	int n;
	cin>>n;
	NTT Ntt;
	Ntt.init();
	vector<int> A(n);
	vector<int> Ones(32);

	Fact.resize(n+1);
	Inv.resize(n+1);

	Fact[0] = 1;
	for(int i=1;i<=n;i++)
	{
		Fact[i] = ((ll)Fact[i-1]*i)%MOD;
	}
	Inv[n] = exp(Fact[n],MOD-2);
	for(int i=n-1;i>=0;i--)
	{
		Inv[i] = ((ll)Inv[i+1]*(i+1)) % MOD;
	}

	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		for(int j=0;j<32;j++)
		{
			Ones[j] += (A[i]>>j)&1;
		}
	}
	vector<int> NCr(n+1);
	for(int i=0;i<=n;i++)
	{
		NCr[i] = C(n,i);
	}
	vector<long long> M(n+1);
	for(int bit=0;bit<32;bit++)
	{
		int x = Ones[bit];
		vector<int> P1(x + 1);
		vector<int> P2(n - x + 1);
		for(int i=0;i<P1.size();i++)
		{
			P1[i] = (1 - 2*(i%2))*C(x,i);
			P1[i] %= MOD;
			if(P1[i]<0) P1[i] += MOD;
		}
		for(int i=0;i<P2.size();i++)
		{
			P2[i] = C(n-x,i);
		}
		vector<int> P3 =  Ntt.multiply(P1,P2);
		for(int i=0;i<=n;i++)
		{
			M[i] += ((NCr[i]-P3[i]) * 1ll * (1<<bit)) % MOD;
			if(M[i]<0) M[i] += MOD;
			M[i] %= MOD;
		}
	}
	for(int i=1;i<=n;i++)
	{
		M[i] = (M[i] + M[i-1])%MOD;
	}

	int q;
	cin>>q;
	int inv2 = exp(2,MOD-2);
	for(int i=0;i<q;i++)
	{
		int m;
		cin>>m;
		cout<<(M[m] * inv2 )%MOD<<"\n";
	}

}