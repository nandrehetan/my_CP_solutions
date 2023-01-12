                //  ॐ
/******************************************
*    AUTHOR:         HETAN HEMANT NANDRE  *
*    INSTITUITION:   VIT PUNE             *
******************************************/
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
// using namespace __gnu_pbds;
using namespace std;
//Hetan Nandre's code 


// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;


// Constants 
#define INF 1e18
#define EPS 1e-9
#define MOD 1000000007



// Macros
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define pb push_back
#define MAX 1e18
#define in(a)        for(auto &i:a) cin>>i
#define MP make_pair
#define rep(i,s,e)   for(int i=s;i<e;i++)
#define repr(i,s,e)  for(int i=s;i>=e;i--)
typedef vector<int>vi;


template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
   for (auto &it : v)
      cin >> it;
   return istream;
}

template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
   for (auto &it : c)
      cout << it << " ";
   return ostream;
}

// Mathematical functions
int GCD(int a, int b)
{
   while (b)
   {
      a %= b;
      swap(a, b);
   }
   return a;
}
 

int GCD_extended(int a, int b, int &x, int &y)
{
   x = 1, y = 0;
   int x1 = 0, y1 = 1, a1 = a, b1 = b;
   while (b1)
   {
      int q = a1 / b1;
      tie(x, x1) = make_tuple(x1, x - q * x1);
      tie(y, y1) = make_tuple(y1, y - q * y1);
      tie(a1, b1) = make_tuple(b1, a1 - q * b1);
   }
   return a1;
}


int LCM(int a, int b)
{
   return ((ll)a * b) / GCD(a, b);
}
 
ll modpow(ll x, ll n, int m = MOD)
{
   if (x == 0 && n == 0)
      return 0; // undefined case
   ll res = 1;
   while (n > 0)
   {
        if (n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
   }
   return res;
}
 
int modinv(int x, int m = MOD)
{
   return modpow(x, m - 2, m);
}
 
mt19937 rng;
int getRandomNumber(int l, int r)
{
   uniform_int_distribution<int> dist(l, r);
   return dist(rng);
}

ll binToDec(string s) { return bitset<64>(s).to_ullong(); }
string decToBin(ll a) { return bitset<64>(a).to_string(); }
 
int fact(ll n)
{
      if(n==0)
      return 1;
    ll res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

ll binarySearch(ll arr[], ll l, ll r, ll x)
{
    while (l <= r) {
        ll m = l + (r - l) / 2;
       
        if (arr[m] == x)
            return m; 
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int maxSubArraySum(vector <int> a, int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int longSubSeq(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    return *max_element(lis, lis + n);
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}


// void ssss()
// {
// vector<int> v{1,2,3,4,5,6,7,8,9,10};
//     int N = v.size(),K = 4;
//     for (int b = 0; b < (1<<N); b++) {
//     if(__builtin_popcount(b)!=K)
//         continue;
//     vector<int> subset;
//     for (int i = 0; i < N; i++)
//         if (b&(1<<i)) subset.push_back(v[i]);
    
//     for (int i = 0; i < subset.size(); ++i)
//     {
//         cout<<subset[i]<<" ";
//     }
//     cout<<endl;
//     }
// }
ll smallestDivisor(ll n)
{
    // if divisible by 2
    if (n % 2 == 0)
        return 2;
 
    // iterate from 3 to sqrt(n)
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }
 
    return n;
}
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
bool is_good_sequence(vector<int> &A, int x) {
    int cnt_ones = 0;
    int cnt_zeros = 0;
    for (int i = x; i < A.size(); i++) {
        if (A[i] == 1) {
            cnt_ones++;
        } else {
            cnt_zeros++;
        }
        if (cnt_ones - cnt_zeros != i - x + 1) {
            return false;
        }
    }
    return true;
}
void max_good_sequence(vector<int> A) {
    int max_length = 0;
    int x = A[0];
    vector<int> sequence;
    for (int i = 0; i < A.size(); i++) {
        if (is_good_sequence(A, i)) {
            if (i - x + 1 > max_length) {
                max_length = i - x + 1;
                sequence = vector<int>(x, i+1);
            }
        }
    }
    cout<<sequence.size()<<endl;
    for(auto gf: sequence){
        cout<<gf<<" ";
    }
    cout<<endl;
    // return max_length, sequence;
}


void solve()
{
    // int n;
    // cin>>n;
    // vector<int>v(n);
    // rep(i,0,n){
    //     cin>>v[i];
    ll a,b;
    cin>>a>>b;
    cout<<GCD(a,b)<<endl;
    // }
    // max_good_sequence(v);
}



    
 

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   t=1;
   cin >> t;
   while(t--)
   {
      solve();
   }
   return 0;
   
}













