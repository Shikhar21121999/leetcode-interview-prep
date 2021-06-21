// Swimming in rising water

// Approach1 : dfs optimization with binary search

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
	int n;
	int neighbor[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};
    bool recur(vector<vector<int>>& grid,bool vis[][50],int i,int j,int waterLevel){

    	// lost cause
    	if(i<0 or j<0 or i>=n or j>=n or vis[i][j] or grid[i][j]>waterLevel)return false;

        // base case
    	if(i==n-1 && j==n-1)return true;
        
    	// recursive case
    	// check for neighbours
    	vis[i][j]=true;
    	for(int k=0;k<4;k++){
    		if(recur(grid,vis,i+neighbor[k][0],j+neighbor[k][1],waterLevel))return true;
    	}
    	return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        bool vis[50][50]={};
        int l=0,r=n*n-1,mid;
        while(l<=r){
        	mid=(l+r)/2;
        	if(recur(grid,vis,0,0,mid))r=mid-1;
        	else l=mid+1;
        	memset(vis,false,sizeof vis);
        }
        return l;
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

}