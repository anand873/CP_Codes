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
	string s;
	cin>>s;
	
	int n = s.length();
	vector<vector<int>> Left(n+1,vector<int>(20)),Right(n+1,vector<int>(20));
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='(')
		{
			Left[i][0]++;
		}
		else Right[i][0]++;
	}
	
	for(int j=1;j<20;j++)
	{
		int len=1<<j;
		for(int i=1;i+len-1<=n;i++)
		{
			int idx = i+len/2;
			Left[i][j] = Left[idx][j-1];
			Right[i][j] = Right[i][j-1];

			if(Left[i][j-1]>Right[idx][j-1])
			{
				Left[i][j] += Left[i][j-1]-Right[idx][j-1];
			}
			else
			{
				Right[i][j] += Right[idx][j-1]-Left[i][j-1];
			}
		}
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int st = l;
		int len = r-l+1;
		int left=0,right=0;
		for(int j=0;j<20;j++)
		{
			if((len>>j)&1)
			{
				int jump = 1<<j;
				int this_left = Left[l][j];
				int this_right = Right[l][j];

				right = right + max(0,this_right-left);
				left = this_left + max(0,left-this_right);
				len -= jump;
				l += jump;
			}
		}
		printf("%d\n",r-st+1 - (left+right));
	}

}	