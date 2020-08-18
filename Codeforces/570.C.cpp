#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int curr=0;
	int con=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='.') con++;
		else {curr+=max(0,con-1);con=0;}
	}
	if(con!=0) curr+=con-1;
	//cout<<curr<<endl;
	while(m--)
	{
		int in;
		char c;
		cin>>in>>c;
		in--;
		if(c=='.')
		{
			if(s[in]=='.')
			{
				cout<<curr<<endl;
				s[in]=c;
			}
			else
			{
				if(in!=0&&in!=n-1)
				{
					if(s[in+1]=='.'&&s[in-1]=='.') curr+=2;
					else if(s[in+1]=='.'||s[in-1]=='.') curr++;
					else curr=curr;
				}
				else
				{
					if(in==0&&in!=n-1)
					{
						if(s[in+1]=='.') curr++;
					}
					else if(in==n-1&&in!=0)
					{
						if(s[in-1]=='.') curr++;
					}
				}
				s[in]=c;
				cout<<curr<<endl;
			}
		}
		else
		{
			if(s[in]!='.')
			{
				cout<<curr<<endl;
				s[in]=c;
			}
			else
			{
				if(in!=0&&in!=n-1)
				{
					if(s[in+1]=='.'&&s[in-1]=='.') curr-=2;
					else if(s[in+1]=='.'||s[in-1]=='.') curr--;
					else curr=curr;
				}
				else
				{
					if(in==0&&in!=n-1)
					{
						if(s[in+1]=='.') curr--;
					}
					else if(in==n-1&&in!=0)
					{
						if(s[in-1]=='.') curr--;
					}
				}
				s[in]=c;
				cout<<curr<<endl;
			}
		}
		
	}
}