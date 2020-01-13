#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int x1,y1;
	cin>>x1>>y1;
	long long int x2,y2;
	cin>>x2>>y2;
	int n;
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		long long int a,b,c;
		cin>>a>>b>>c;
		if(((a*x1+b*y1+c)>0&&(a*x2+b*y2+c)<0)||((a*x1+b*y1+c)<0&&(a*x2+b*y2+c)>0)) ans++;
	}
	cout<<ans<<endl;
}