//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        for(int i=0;i<N;i++){
            maxi=max(arr[i],maxi);
        }
        vector<bool> v(maxi+1,false);
        for(int i=0;i<N;i++){
            if(mp[arr[i]]){
                mp[arr[i]]++;
                continue;
            }
            for(int j=2*arr[i];j<=maxi;j+=arr[i]){
                v[j]=true;
            }
            mp[arr[i]]++;
        }
        int count=0;
        for(int i=0;i<N;i++){
            if(v[arr[i]]||mp[arr[i]]>1){
                count++;
            }
        }
        return count;
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends