#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,q;
	cin>>n>>q;
	vector<int> VU(n+1),VR(n+1);
	deque<int> DQ;
	int cun=0,cur=0;
	int poi=0;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(x==1)
		{
			DQ.push_back({y});
			cun++;
			VU[y]++;
			cout<<cun<<endl;
		}
		if(x==2)
		{
			cun-=VU[y];
			VR[y]+=VU[y];
			VU[y]=0;
			cout<<cun<<endl;
		}
		if(x==3)
		{
			y=max(y-poi,0);
			for(int i=poi;i<poi+y;i++)
			{
				if(VR[DQ.front()]>0) VR[DQ.front()]--;
				else if(VU[DQ.front()]>0) {VU[DQ.front()]--;cun--;}
				DQ.pop_front();
			}
			poi+=y;
			cout<<cun<<endl;
		}

	}
}