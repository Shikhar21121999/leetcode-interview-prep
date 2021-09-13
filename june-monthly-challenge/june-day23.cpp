// Out of boundary paths

// Approach: Iterative dp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dp[51][51][51];
	int nbor[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // fill the dp
        // define dp[i][j][k]= number of possible paths to get out of grid
    	// from coordinate i,j when at most k steps are allowed
        memset(dp,0,sizeof dp);

        for(int k=1;k<=maxMove;k++){
        	for(int i=0;i<m;i++){
        		for(int j=0;j<n;j++){
        			for(int nb=0;nb<4;nb++){
        				int a=i+nbor[nb][0];
        				int b=j+nbor[nb][1];
        				dp[i][j][k]=(dp[i][j][k]+(a<0 or a>=m or b<0 or b>=n)?1:dp[a][b][k-1])%1000000007;
        			}
        		}
        	}
        }
        return dp[startRow][startColumn][maxMove];
    }
};

int main(){
	int m,n,maxMove,startRow,startColumn;
	cin>>m>>n>>maxMove>>startRow>>startColumn;
	Solution ob;
	cout<<ob.findPaths(m,n,maxMove,startRow,startColumn)<<endl;
}