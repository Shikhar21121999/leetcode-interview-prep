// Swimming in rising water

// djkstras approach

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
	int neighbor[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),ans=max(grid[0][0],grid[n-1][n-1]);
        priority_queue<vi,vvi,greater<vi>> mpq;
        vvi vis(n,vi(n,0));
        vis[0][0]=1;
        mpq.push({grid[0][0],0,0});
        while(!mpq.empty()){
        	vi curr=pq.top();
        	pq.pop();
        	ans=max(ans,curr[0]);
        	for(int i=0;i<4;i++){
        		int r=curr[1]+neighbor[i][0],c=curr[2]+neighbor[i][1];
        		if(r>=0 and r<n and c>=0 and c<n and !vis[r][c]){
        			if(r==n-1 && c==n-1)return ans;
        			mpq.push({grid[r][c],r,c});
        			vis[r][c]=1;
        		}
        	}
        }
        return -1;

    }
};

int main(){
	int n;
	cin>>n;
	vvi ans(n,vi(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>ans[i][j];
		}
	}
	Solution ob;
	cout<<swimInWater(ans);
	return 0;
}