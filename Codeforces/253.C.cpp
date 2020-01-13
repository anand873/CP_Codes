#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector<int> A(n+1);
	for(int i=1;i<=n;i++) cin>>A[i];
	int r1,c1,r2,c2;
	cin>>r1>>c1>>r2>>c2;
	if(r1<=r2)
	{
		int ans=0;
		ans+=r2-r1;
		int curr=c1;
		for(int i=r1;i<r2;i++)
		{
			curr=min(A[i+1]+1,curr);
		}
		ans+=abs(curr-c2);
		cout<<ans<<endl;
	}
	else
	{
		int ans=0;
		ans+=r1-r2;
		int curr=c1;
		for(int i=r1;i<r2;i++)
		{
			curr=min(A[i-1]+1,curr);
		}
		ans+=abs(curr-c2);
		cout<<ans<<endl;
	}
}