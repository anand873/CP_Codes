//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	string s;
	cin>>s;
	s+='#';
	int ans=0;
	int curr=1;
	int n=s.length();
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1]) curr++;
		else
		{
			ans = max(ans,curr);
			curr=1;
		}
	}
	cout<<ans<<endl;
}	