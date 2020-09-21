//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

int main()
{
	string s;
	cin>>s;
	vector<int> H(26);
	for(auto c:s) H[c-'A']++;

	string s1,s2;
	char mid = '#';
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<H[i]/2;j++)
		{
			s1 += 'A'+i;
			s2 += 'A'+i;
		}
		H[i]%=2;
		if(H[i]) mid = 'A'+i;
	}
	reverse(s2.begin(),s2.end());
	
	if(mid=='#')
	{
		cout<<s1+s2<<endl;
	}
	else
	{
		if(s1.length()+1+s2.length()==s.length()) cout<<s1+mid+s2<<endl;
		else cout<<"NO SOLUTION"<<endl;
	}
	
}	