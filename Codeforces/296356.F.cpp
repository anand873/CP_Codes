//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	string s;
	cin>>s;
	int n = s.size();
	vector<vector<int>> dp(n,vector<int>(26));
	dp[0][s[0]-'a']=1;

	for(int i = 1 ; i < n ; i++)
	{
		dp[i] = dp[i-1];
		for(int j=0;j<=(s[i]-'a');j++)
		{
			dp[i][s[i]-'a'] = max(dp[i-1][j]+1,dp[i][s[i]-'a']);
		}
	}
	char first;
	string str;
	int curr=0;
	for(int j=0;j<26;j++)
	{
		if(curr<dp[n-1][j])
		{
			curr = dp[n-1][j];
			first = 'a'+j;
		}
	}
	str+=first;
	for(int i=n-2;i>=0;i--)
	{
		if(dp[i][str.back()-'a']==curr) continue;
		for(int j=0;j<=str.back()-'a';j++)
		{
			if(dp[i][j]==curr-1&&s[i]=='a'+j)
			{
				str += 'a'+j;
				curr--;
				break;
			}
			else if(dp[i][j]==curr-1) break;
		}
	}
	reverse(str.begin(),str.end());
	cout<<str.size()<<endl;
	cout<<str<<endl;
}		