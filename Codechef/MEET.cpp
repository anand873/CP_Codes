#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string hhmm,when;
		cin>>hhmm>>when;
		int H = stoi(hhmm.substr(0,2));
		int M = stoi(hhmm.substr(3,2));

		if(when=="AM")
		{
			if(H==12) H=0;
		}
		else
		{
			if(H!=12) H += 12;
		}

		int n;
		cin>>n;
		string ans;
		for(int i=0;i<n;i++)
		{
			bool can = false;
			string ft,fw,tt,tw;
			cin>>ft>>fw>>tt>>tw;
			int fH = stoi(ft.substr(0,2));
			int fM = stoi(ft.substr(3,2));
			if(fw=="AM")
			{
				if(fH==12) fH=0;
			}
			else
			{
				if(fH!=12) fH += 12;
			}

			int tH = stoi(tt.substr(0,2));
			int tM = stoi(tt.substr(3,2));
			if(tw=="AM")
			{
				if(tH==12) tH=0;
			}
			else
			{
				if(tH!=12) tH += 12;
			}

			if(fH==H)
			{
				if(tH==H)
				{
					if(M>=fM&&M<=tM) can = true;
				}
				else
				{
					if(M>=fM) can = true;
				}
			}
			else if(H>fH)
			{
				if(tH==H)
				{
					if(M<=tM) can = true;
				}
				else if(tH>H)
				{
					can = true;
				}
			}
			if(can) ans.push_back('1');
			else ans.push_back('0');
		}
		cout<<ans<<endl;
	}
}