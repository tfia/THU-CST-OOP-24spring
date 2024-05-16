#include <iostream>
#include <map>
#define fcc(x,y,z) for(int x=y;x<=z;x++)
#define ccf(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define MULTi int T; cin>>T; while(T--)

using namespace std;

typedef long long ll;

map<pair<int, int>, string> mp;

string op;
int n;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> op;
	cin >> n;
	fcc(i,1,n)
	{
		cin >> op;
		if(op == "ban")
		{
			int x, y; string id;
			cin >> x >> y >> id;
			mp[make_pair(x, y)] = id;
		}
		else
		{
			int x, y; cin >> x >> y;
			if(mp.find(make_pair(x, y)) != mp.end())
				cout << mp[make_pair(x, y)] << endl;
			else cout << "open\n";
		}
	}
    return 0;
}