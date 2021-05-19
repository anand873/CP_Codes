//Author: AnandRaj doubleux
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s1;
		string s2;
		cin>>s1>>s2;
		while(s1.size()&&s1.back()=='0') s1.pop_back();
		while(s2.size()&&s2.back()=='0') s2.pop_back();
		if(s1.size()>s2.size()) swap(s1,s2);
		while(s1.size()<s2.size()) s1.push_back('0');
		int carry = 0;
		string ans;
		for(int i=0;i<s1.size();i++)
		{
			int v = (s1[i]-'0')+(s2[i]-'0')+carry;
			ans.push_back('0' + v%10);
			carry = v/10;
		}
		if(carry>0)
		{
			ans.push_back('0'+carry);
		}
		reverse(all(ans));
		while(ans.size()&&ans.back()=='0') ans.pop_back();
		reverse(all(ans));
		cout<<ans<<endl;
	}
}	