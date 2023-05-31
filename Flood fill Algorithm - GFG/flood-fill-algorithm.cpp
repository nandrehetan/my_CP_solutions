//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int row, int col, int color, int curColor)
    {
        if(sr<0 || sc<0 || sr>=row || sc>=col || image[sr][sc]!=curColor){
            return;
        }
        
        image[sr][sc] = color;
        
        dfs(image,sr-1,sc,row,col,color,curColor);
        dfs(image,sr+1,sc,row,col,color,curColor);
        dfs(image,sr,sc-1,row,col,color,curColor);
        dfs(image,sr,sc+1,row,col,color,curColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();
        
        int curColor = image[sr][sc];
        
        if(image[sr][sc] == newColor){
            return image;
        }
        
        dfs(image,sr,sc,row,col,newColor,curColor);
        
        return image;
        // Code here 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends