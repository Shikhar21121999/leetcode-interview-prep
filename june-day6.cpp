// longest Consecutive Solution

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution{
	public:
	int longestConsecutive(vector<int>& nums){
		if(nums.size()==0)return 0;
		sort(nums.begin(),nums.end());

		// finding the length of longest consecutive sequence
		int maxSeqLen=1;
		int currSeqLen=1;
		for(int i=1;i<nums.size();i++){
			if(nums[i]-nums[i-1]==1){
				currSeqLen++;
			}
			else if(nums[i]==nums[i-1]){
                // takes care of repetitive case
                continue;
            }
			else{
				// sequence breaks
				maxSeqLen=max(maxSeqLen,currSeqLen);
				currSeqLen=1;
			}
		}
		maxSeqLen=max(maxSeqLen,currSeqLen);
		return maxSeqLen;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.longestConsecutive(a)<<endl;
	}

}