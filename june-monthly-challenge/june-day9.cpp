// Jump Game 6

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution{
public:
	int maxResult(vector<int>& nums,int k){
		int n=nums.size();
		multiset<int> stor;
		vector<int> dp(nums.size());
		dp[0]=nums[0];
		stor.insert(nums[0]);

		for(int i=1;i<n;i++){
			// check and remove element from store
			// through which it is not possible to 
			// get to current step
			if(i>k)stor.erase(stor.find(dp[i-k-1]));

			// set max cost to reach here
			dp[i]=*stor.rbegin()+nums[i];

			// push in store
			stor.insert(dp[i]);
		}
		return dp[n-1];
	}
};

int main(){
	int n,k;
	cin>>n>>k;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	Solution ob;
	cout<<ob.maxResult(a,k)<<endl;

}