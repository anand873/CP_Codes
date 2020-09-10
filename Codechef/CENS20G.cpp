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
const int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;


int main()
{
	test()
	{
		string s;
		cin>>s;
		int x1,y1;
		cin>>x1>>y1;
		vector<int> M(4);
		for(auto c:s)
		{
			if(c=='L') M[0]++;
			else if(c=='R') M[1]++;
			else if(c=='U') M[2]++;
			else M[3]++;
		}

		int q;
		cin>>q;
		while(q--)
		{
			int x2,y2;
			scanf("%d%d",&x2,&y2);
			int right = x2-x1;
			int up = y2-y1;
			int dis = abs(up) + abs(right);
			if(right==0&&up==0) printf("YES %d\n",dis);
			else if(right>=0&&M[1]>=right&&up>=0&&M[2]>=up) printf("YES %d\n",dis);
			else if(right>=0&&M[1]>=right&&up<=0&&M[3]>=abs(up)) printf("YES %d\n",dis);
			else if(right<=0&&M[0]>=abs(right)&&up<=0&&M[3]>=abs(up)) printf("YES %d\n",dis);
			else if(right<=0&&M[0]>=abs(right)&&up>=0&&M[2]>=up) printf("YES %d\n",dis);
			else printf("NO\n");
		}
	}	
}
