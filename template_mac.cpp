/*
author: arrxy
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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


#define int                         long long
#define endl                        '\n'
#define vb                          vector<bool>
#define vbb                         vector<vb>
#define vi                          vector<int>
#define vvi                         vector<vector<int>>
#define inf                         1e18
#define setbits(x)                  __builtin_popcountll(x)
#define pii                         pair<int,int>
#define w(x)                        int x; cin >> x; while(x--)
#define pb                          push_back
#define F                           first
#define S                           second
#define printV(v)                   for(auto &it: v) cout<<it<<" "; cout<<endl;
#define printVV(v)                  for(auto &it: v) {printV(it);}
#define all(v)                      v.begin(),v.end()
#define inp(i)                      int i; cin >> i;
#define inp2(i,j)                   int i,j; cin >> i >> j;
#define inp3(i,j,k)                 int i,j,k; cin >> i >> j >> k;
#define inp4(i,j,k,l)               int i,j,k,l; cin >> i >> j >> k >> l;
#define inparr(arr, n)              arr.resize(n, 0); for(auto &it: arr) cin >> it;
#define MOD                         1000000007ll
#define fill(a,b)                   memset(a, b, sizeof(a))
#define uniq(v)                     (v).erase(unique(all(v)),(v).end())
using namespace std;

// ########################## POLICY BASED DATA STRUCTURE ################################
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
int current_mod = -1;

void calcfact(int m) {
    current_mod = m;
    fact[0] = 1;
    for (int i = 1; i <= 1000004; ++i) {
        fact[i] = (fact[i - 1] * i) % m; 
    }
}

int ncr(int n, int r, int m = MOD) {
    if (n < r || r < 0) return 0;
    if (current_mod != m) calcfact(m);
    
    int x = binexp(fact[n - r], m - 2, m);
    int y = binexp(fact[r], m - 2, m);
    int res = (fact[n] * x) % m;
    res = (res * y) % m;
    return res;
}

// ########################### CUSTOM HASH #############################################
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// Use like this: unordered_map<int, int, custom_hash> safe_map;
// ########################## SEGMENT TREE #############################################

template <typename T>
struct SegmentTree {
public:
    vector<T> tree;
    int N;
    T default_val;
    // Functional operator for flexibility (e.g., plus<T>(), minimum, etc.)
    function<T(T, T)> op; 

    // Constructor requires the array, a default value (identity), and the merge operation
    SegmentTree(vector<T>& arr, T identity, function<T(T, T)> merge_op) {
        N = arr.size();
        default_val = identity;
        op = merge_op;
        tree.resize(4 * N + 1, default_val);

        if (N > 0) {
            build(arr, 1, 0, N - 1);
        }
    }

    void update(int idx, T val) {
        if (idx < 0 || idx >= N) return;
        update(idx, val, 1, 0, N - 1);
    }

    T query(int start, int end) {
        if (N == 0) return default_val;
        start = max(start, 0ll);
        end = min(end, (int)N - 1);
        if (start > end) return default_val;
        return query(start, end, 1, 0, N - 1);
    }

private:
    void build(vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(arr, node << 1, start, mid);
        build(arr, node << 1 | 1, mid + 1, end);
        tree[node] = op(tree[node << 1], tree[node << 1 | 1]);
    }

    void update(int idx, T val, int node, int start, int end) {
        if (start == end) {
            tree[node] = val; // For point updates. Change to tree[node] += val if needed.
            return;
        }
        int mid = (start + end) >> 1;
        if (idx <= mid) {
            update(idx, val, node << 1, start, mid);
        } else {
            update(idx, val, node << 1 | 1, mid + 1, end);
        }
        tree[node] = op(tree[node << 1], tree[node << 1 | 1]);
    }

    T query(int queryStart, int queryEnd, int node, int start, int end) {
        if (start >= queryStart && end <= queryEnd) {
            return tree[node];
        }
        if (queryStart > end || queryEnd < start) {
            return default_val;
        }
        int mid = (start + end) >> 1;
        return op(
            query(queryStart, queryEnd, node << 1, start, mid),
            query(queryStart, queryEnd, node << 1 | 1, mid + 1, end)
        );
    }
};
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
