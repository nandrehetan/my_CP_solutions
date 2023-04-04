//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int n = str.length();
    int count_a =0,count_b=0;
    for(int i=0; i< n; i++){
        if (str[i] == 'a') {
            count_a++;
        } else {
            count_b++;
        }
        // Skip over consecutive characters
        while (i +1 < n && str[i] == str[i + 1]) {
            i++;
        }
    }
    return min(count_a,count_b)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends