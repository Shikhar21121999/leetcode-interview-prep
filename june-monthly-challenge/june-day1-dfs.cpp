// june day1 using dfs

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution{
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int m=grid.size();
		int n=grid[0].size();
		int ans=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j]==1)ans=max(ans,dfs(grid,i,j));
			}
		}
		return ans;
    }
private:
	int dfs(vvi &grid,int row,int col){
		int m=grid.size();
		int n=grid[0].size();
		int area=1;
		// mark current element to prevent cycle
		grid[row][col]=2;

		// get all the four directions
		vi dir({-1,0,1,0,-1});
		for(int i=0;i<4;i++){
			int r=row+dir[i];
			int c=col+dir[i+1];

			if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1){
				area+=dfs(grid,r,c);
			}
		}
		return area;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;

		vvi grid(n,vi(m));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>grid[i][j];
			}
		}

		Solution ob;
		cout<<ob.maxAreaOfIsland(grid)<<endl;	
	}
	
}