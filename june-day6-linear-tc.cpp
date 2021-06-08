// solving june day 7 in linear time commplexity

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution{
public:
	int longestConsecutive(vector<int>& nums){
		if(nums.size()==0)return 0;
		unordered_map <int,int> store;
		for(auto x:nums){
			store[x]+=1;
		}

		// implementation starts here
		int maxSeqLen=0;
		for(auto x:nums){
			if(!store[x-1]){
				int currNum=x;
				int currStreak=1;

				while(store[currNum+1]){
					currNum+=1;
					currStreak+=1;
				}

				maxSeqLen=max(maxSeqLen,currStreak);
			}
		}
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
	return 0;
}