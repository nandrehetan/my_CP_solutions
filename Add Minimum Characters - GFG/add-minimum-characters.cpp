//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        int st=0;
        int end=str.size()-1;
        int ans=0;
        while(st<=end){
            if(str[st]==str[end]){
                st++;
                end--;
            }
            else{
                ans++;
                st=0;
                end=str.size()-1-ans;
                
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends