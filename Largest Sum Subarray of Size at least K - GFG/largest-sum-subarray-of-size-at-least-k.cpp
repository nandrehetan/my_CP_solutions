//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    int ans=INT_MIN;
    int dp[n];
    int cursum=a[0];
    dp[0]=cursum;
    for(int i=1;i<n;i++){
        if(cursum>0){
            cursum += a[i];
        }else{
            cursum=a[i];
        }
        dp[i]=cursum;
    }
    int exactk=0;
    for(int i=0;i<k;i++){
        exactk += a[i];
    }
    if(exactk>ans){
        ans=exactk;
    }
    
    for(int i=k;i<n;i++){
        exactk += a[i]-a[i-k];
        if(exactk>ans){
            ans=exactk;
        }
        int morethank=dp[i-k]+exactk;
        if(morethank>ans){
            ans=morethank;
        }
    }
    return ans;
    
}