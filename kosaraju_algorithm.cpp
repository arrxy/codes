#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int 					long long
#define endl 					'\n'
#define vb						vector<bool>
#define vbb						vector<vb>
#define vi 						vector<int>
#define vvi 					vector<vector<int>>
#define inf						1e18
#define setbits(x)				__builtin_popcountll(x)
#define loop(i,a,b)				for(int i = a; i<=b; i+=1)
#define revloop(i,a,b)			for(int i = a; i>=b; i-=1)
#define pii						pair<int,int>
#define w(x)					int x; cin >> x; while(x--)
#define pb 						push_back
#define ust						unordered_set
#define ump						unordered_map
#define ff 						first
#define ss  				    second
#define bug(...)       			__f (#__VA_ARGS__, __VA_ARGS__)
#define printV(v)				for(auto &it: v) cout<<it<<" "; cout<<endl;
#define all(v)      			v.begin(),v.end()
#define inp(i)  				int i; cin >> i;

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 1e5;
vi adj[N + 1];
vi revadj[N + 1];
int vis[N + 1];
vi topo;
vi conn_store[N + 1];
void dfs1(int src)
{
	vis[src] = 1;
	for (auto &it : adj[src])
	{
		if (!vis[it])
			dfs1(it);
	}
	topo.pb(src);
}
void dfs2(int src, int clr)
{
	conn_store[clr].pb(src);
	vis[src] = 1;
	for (auto &it : revadj[src])
		if (!vis[it])
			dfs2(it, clr);
}
void solve()
{
	inp(n);
	inp(m);
	while (m--)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		revadj[v].pb(u);
	}
	dfs1(1);
	memset(vis, 0, sizeof vis);
	reverse(all(topo));
	int color = 0;
	for (auto &it : topo)
	{
		if (!vis[it])
			dfs2(it, color++);
	}
	loop(i, 0, color - 1)
	{
		cout << i << "-> ";
		printV(conn_store[i]);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t z = clock();
	//w(x)
	{
		solve();
	}
	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;

	return 0;

}
