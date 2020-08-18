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

const int MOD = 1e9+7,MAX = 1e6+5;
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
	for(int i=2;i<=MAX;i++) if(is_prime[i]) MinDiv[i]=i;
}
//////////////////Sieve////////////////////

// struct Q4
// {
// 	int r1,c1,r2,c2;
// };

int main()
{
	test()
	{
		int n,p;
		cin>>n>>p;
		vvi A(n+1,vi(n+1));
		int M[n+1][n+1][n+1][n+1];

		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=n;b++)
			{
				for(int c=1;c<=n;c++)
				{
					for(int d=1;d<=n;d++) M[a][b][c][d] = -1;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int Big,S1,S2,S3;
				if(i>n/2&&j<=n/2)
				{
					if(M[1][j][i][n]==-1)
					{
						cout<<1<<" "<<1<<" "<<j<<" "<<i<<" "<<n<<endl;
						cin>>Big;
						M[1][j][i][n] = Big;
					}
					else
					{
						Big = M[1][j][i][n];
					}
					if(M[1][j+1][i][n]==-1)
					{
						cout<<1<<" "<<1<<" "<<j+1<<" "<<i<<" "<<n<<endl;
						cin>>S1;
						M[1][j+1][i][n] = S1;
					}
					else
					{
						S1 = M[1][j+1][i][n];
					}
					if(M[1][j][i-1][n]==-1)
					{
						cout<<1<<" "<<1<<" "<<j<<" "<<i-1<<" "<<n<<endl;
						cin>>S2;
						M[1][j][i-1][n] = S2;				
					}
					else
					{
						S2 = M[1][j][i-1][n];
					}
					if(M[1][j+1][i-1][n]==-1)
					{
						cout<<1<<" "<<1<<" "<<j+1<<" "<<i-1<<" "<<n<<endl;
						cin>>S3;
						M[1][j+1][i-1][n] = S3;
					}
					else
					{
						S3 = M[1][j+1][i-1][n];
					}
				}
				else if(i>n/2&&j>n/2)
				{
					if(M[1][1][i][j]==-1)
					{
						cout<<1<<" "<<1<<" "<<1<<" "<<i<<" "<<j<<endl;
						cin>>Big;
						M[1][1][i][j] = Big;
					}
					else
					{
						Big = M[1][1][i][j];
					}

					if(M[1][1][i-1][j]==-1)
					{
						cout<<1<<" "<<1<<" "<<1<<" "<<i-1<<" "<<j<<endl;
						cin>>S1;
						M[1][1][i-1][j] = S1;
					}
					else
					{
						S1 = M[1][1][i-1][j];
					}

					if(M[1][1][i][j-1]==-1)
					{
						cout<<1<<" "<<1<<" "<<1<<" "<<i<<" "<<j-1<<endl;
						cin>>S2;
						M[1][1][i][j-1] = S2;				
					}
					else
					{
						S2 = M[1][1][i][j-1];
					}

					if(M[1][1][i-1][j-1]==-1)
					{
						cout<<1<<" "<<1<<" "<<1<<" "<<i-1<<" "<<j-1<<endl;
						cin>>S3;
						M[1][1][i-1][j-1] = S3;
					}
					else
					{
						S3 = M[1][1][i-1][j-1];
					}
				}
				else if(i<=n/2&&j<=n/2)
				{
					if(M[i][j][n][n]==-1)
					{
						cout<<1<<" "<<i<<" "<<j<<" "<<n<<" "<<n<<endl;
						cin>>Big;
						M[i][j][n][n] = Big;
					}
					else
					{
						Big = M[i][j][n][n];
					}

					if(M[i+1][j][n][n]==-1)
					{
						cout<<1<<" "<<i+1<<" "<<j<<" "<<n<<" "<<n<<endl;
						cin>>S1;
						M[i+1][j][n][n] = S1;
					}
					else
					{
						S1 = M[i+1][j][n][n];
					}

					if(M[i][j+1][n][n]==-1)
					{
						cout<<1<<" "<<i<<" "<<j+1<<" "<<n<<" "<<n<<endl;
						cin>>S2;
						M[i][j+1][n][n] = S2;				
					}
					else
					{
						S2 = M[i][j+1][n][n];
					}

					if(M[i+1][j+1][n][n]==-1)
					{
						cout<<1<<" "<<i+1<<" "<<j+1<<" "<<n<<" "<<n<<endl;
						cin>>S3;
						M[i+1][j+1][n][n] = S3;
					}
					else
					{
						S3 = M[i+1][j+1][n][n];
					}
				}
				else 
				{
					if(M[i][1][n][j]==-1)
					{
						cout<<1<<" "<<i<<" "<<1<<" "<<n<<" "<<j<<endl;
						cin>>Big;
						M[i][1][n][j] = Big;
					}
					else
					{
						Big = M[i][1][n][j];
					}

					if(M[i][1][n][j-1]==-1)
					{
						cout<<1<<" "<<i<<" "<<1<<" "<<n<<" "<<j-1<<endl;
						cin>>S1;
						M[i][1][n][j-1] = S1;
					}
					else
					{
						S1 = M[i][1][n][j-1];
					}

					if(M[i+1][1][n][j]==-1)
					{
						cout<<1<<" "<<i+1<<" "<<1<<" "<<n<<" "<<j<<endl;
						cin>>S2;
						M[i+1][1][n][j] = S2;				
					}
					else
					{
						S2 = M[i+1][1][n][j];
					}

					if(M[i+1][1][n][j-1]==-1)
					{
						cout<<1<<" "<<i+1<<" "<<1<<" "<<n<<" "<<j-1<<endl;
						cin>>S3;
						M[i+1][1][n][j-1] = S3;
					}
					else
					{
						S3 = M[i+1][1][n][j-1];
					}
				}

				A[i][j] = (Big-S1)+(Big-S2)-(Big-S3);
			}
		}

		// for(int i=1;i<n;i++)
		// {
		// 	int Big = M[1][i][1][n];
		// 	int S1 = M[1][i+1][1][n];
		// 	A[1][i] = Big-S1;
		// }

		// for(int i=n;i>1;i--)
		// {
		// 	int Big = M[1][n][i][n];
		// 	int S1 = M[1][n][i-1][n];

		// 	A[i][n] = Big - S1;
 	// 	}



		// A[1][n] = M[1][n][1][n];

		cout<<2<<endl;

		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<A[i][j]<<" ";
			}
			cout<<endl;
		}
		int x;
		cin>>x;
		if(x==-1) return 0;
	}
}		