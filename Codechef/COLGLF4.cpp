#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 5;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,e,h,a,b,c;
		cin>>n>>e>>h>>a>>b>>c;
		long long ans = INF;
		int zlim = min({n,e,h});
		for(int z = 0;z<=zlim;z++)
		{
			int sum = n - z;
			int xmax = min(sum,(e - z)/2);
			int ymax = min(sum,(h - z)/3);
			if( sum > xmax + ymax) continue;
			else
			{
				ans = min({(long long)a * xmax + (long long)b * (sum - xmax) + (long long)c * z, (long long)b * ymax + (long long)a * (sum - ymax) + (long long)c * z, ans});
			}
		}
		if(ans == INF) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}