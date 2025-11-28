/*
author: arrxy
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <bitset>
#include <tuple>
#include <sstream>
#include <functional>
#include <climits>
#include <cfloat>
#include <cassert>
#include <cstring>
#include <ctime>
#include <random>
#include <chrono>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define int                         long long
#define endl                        '\n'
#define vb                          vector<bool>
#define vbb                         vector<vb>
#define vi                          vector<int>
#define vvi                         vector<vector<int>>
#define inf                         1e18
#define setbits(x)                  __builtin_popcountll(x)
#define loop(i,a,b)                 for(int i = a; i<=b; i+=1)
#define revloop(i,a,b)              for(int i = a; i>=b; i-=1)
#define pii                         pair<int,int>
#define w(x)                        int x; cin >> x; while(x--)
#define pb                          push_back
#define ust                         unordered_set
#define ump                         unordered_map
#define ff                          first
#define ss                          second
#define bug(...)                    __f (#__VA_ARGS__, __VA_ARGS__)
#define printV(v)                   for(auto &it: v) cout<<it<<" "; cout<<endl;
#define printVV(v)                  for(auto &it: v) {printV(it);}
#define all(v)                      v.begin(),v.end()
#define inp(i)                      int i; cin >> i;
#define inp2(i,j)                   int i,j; cin >> i >> j;
#define inp3(i,j,k)                 int i,j,k; cin >> i >> j >> k;
#define inp4(i,j,k,l)               int i,j,k,l; cin >> i >> j >> k >> l;
#define inparr(arr, n)              inp(n); vi arr(n); for(auto &it: arr) cin >> it;
#define MOD                         1000000007ll
#define fill(a,b)       	        memset(a, b, sizeof(a))
#define uniq(v)           		    (v).erase(unique(all(v)),(v).end())
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

// ########################## NUMBER THEORY #############################################
int binexp(int a, int b, int m = MOD) {
    if(a == 0 && b == 0) return 1;
    a = a % m;
    int res = 1;
    while(b) {
        if (b & 1) res = (res * a) % m;
        a = a*a % m;
        b = b >> 1;
    }
    return res%m;
}
vi fact(1000005, 1);
void calcfact() {
    loop(i, 1, 1000004) {
        fact[i] = (fact[i - 1] % MOD * i % MOD) % MOD; 
    }
}
int ncr(int n, int r, int m = MOD) {
    if (fact[5] == 1) calcfact();
    int x = binexp(fact[n - r], MOD - 2, MOD);
    int y = binexp(fact[r], MOD - 2, MOD);
    int res = (fact[n] % MOD * x % MOD * y % MOD) % MOD;
    return res;
}
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

//######################################################################################

void solve()
{
    
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t z = clock();
    cout << fixed << setprecision(12);
    // w(x)
    {
        solve();
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
 
    return 0;
 
}
