//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<int>suar(leaves+1,0);
        
        for(int i=0;i<N; i++)
        {
            int kung=frogs[i];
            if(kung<=leaves and  !suar[kung])
            {
                for(int j=kung; j<=leaves; j+=kung)
                {
                    suar[j]=1;
                }
            }
            
        }
        
        int laa=0;
        for(int i=1; i<=leaves; i++)
        {
            if(suar[i]==0)laa++;
        }
        
        return laa;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends