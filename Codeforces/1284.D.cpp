#include<bits/stdc++.h>
using namespace std;

typedef vector<int > vi;
typedef vector< vi > vvi;
typedef pair< int, int > ii;
#define sz(a)  int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define forn(i,n) for(int i=0;i<n;++i)
#define foru(i,n) for(int i=1;i<=n;++i)
#define fortr(i,v) for(auto &i:v)
#define set(n) __builtin_popcount(n)
#define ll long long
#define MOD 1000000007

bool operator<(pair<ii,int> a,pair<ii ,int> b)
{
 return(a.first<b.first);
}

bool operator<(set<int> s1,set<int> s2)
{
 set<int>::iterator it1=s1.begin();
 set<int>::iterator it2=s2.begin();
 return(*it1<*it2);
}

int main()
{
 int n;
 cin>>n;
 vector< pair<ii,int> > X;
 vector< pair<ii,int> > Y;
 forn(i,n)
 {
  ll l,r;
  cin>>l>>r;
  X.pb(make_pair((make_pair(l,-1)),i));
  X.pb(make_pair((make_pair(r,1)),i));

  cin>>l>>r;
  Y.pb(make_pair((make_pair(l,-1)),i));
  Y.pb(make_pair((make_pair(r,1)),i));

 }
 sort(X.begin(),X.end());
 sort(Y.begin(),Y.end());
   // cout<<"hello"<<endl;
 vector<set<int> > C;
 vector<set<int> > D;
 ll ans=0;
 forn(i,n)
 {
  if(ans==0)
  {
   set<int> s;
   s.insert(X[i].second);
   C.pb(s);
  }

  if(X[i].first.second==1)
   --ans;
  else if(X[i].first.second==-1)
  {
   ++ans;
   C[C.size()-1].insert(X[i].second);
  } 
 }
 ans=0;
 forn(i,n)
 {
  if(ans==0)
  {
   set<int> s;
   s.insert(Y[i].second);
   D.pb(s);
  }

  if(Y[i].first.second==1)
   --ans;
  else if(Y[i].first.second==-1)
  {
   ++ans;
   D[D.size()-1].insert(Y[i].second);
  } 
 }
 //cout<<"hello"<<endl;
 sort(C.begin(),C.end());
 sort(D.begin(),D.end());
 ans=1;
 if(C.size()==D.size())
 {
  forn(i,C.size())
  {
   int x=C[i].size();
   for(set<int>::iterator it=D[i].begin();it!=D[i].end();++it)
   {
    C[i].insert(*it);
   }
   if(x!=C[i].size())
   {
    ans=0;
    break;
   }
  }
 }
 else
 {
  ans=0;
 }
 if(ans)
  cout<<"YES"<<endl;
 else cout<<"NO"<<endl;

}