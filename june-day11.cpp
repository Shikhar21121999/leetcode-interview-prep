// Stone Game VII

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution{
public:
	int recur(int currSum,int start,int end,vi &stones,vvi &dp){
		cout<<currSum<<" "<<start<<" "<<end<<" "<<endl;
		// not allowed state
		if(start>=end)return 0;

		// base case already calculated
		if(dp[start][end]!=-1)return dp[start][end];

		// choose first one
		int ch1=currSum-stones[start]+min(recur(currSum-stones[start+1],start+2,end,stones,dp)
			,recur(currSum-stones[end],start+1,end-1,stones,dp));

		// choose last one
		int ch2=currSum-stones[end]+min(recur(currSum-stones[start+1],start+1,end-1,stones,dp)
			,recur(currSum-stones[end-1],start,end-2,stones,dp));
		return dp[start][end]=max(ch1,ch2);
	}
	int stoneGameVII(vector<int>& stones) {
		// Abstract function to call set variables
		// and call recursive function

		int n=stones.size();
		vvi dp(n,vi(n,-1));
		int currSum=0;
		for(int i=0;i<n;i++){
			currSum+=stones[i];
			dp[i][i]=0;
		}

		int alice_max=recur(currSum,0,n-1,stones,dp);
		int bob_max=min(recur(currSum-stones[0],1,n-1,stones,dp),recur(currSum-stones[n-1],0,n-2,stones,dp));
		// cout<<alice_max<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		return alice_max-bob_max;
    }
};

int main(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	Solution ob;
	cout<<ob.stoneGameVII(a)<<endl;
}