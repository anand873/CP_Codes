//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int bal=0,len=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		len++;
		if(s[i]=='(') bal++;
		else bal--;
		if(bal==0&&s[i]=='(') {ans+=len;len=0;}
		else if(bal==0) len=0;
	}
	if(bal!=0) cout<<-1<<endl;
	else cout<<ans<<endl;
}		