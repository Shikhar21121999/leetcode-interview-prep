// Max consecutive ones III

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,curr_zer=0,ans=0,n=nums.size();

        while(r<n){
        	if(nums[r]==0)curr_zer++;
        	if(curr_zer<=k){
        		ans=max(ans,r-l+1);
        	}
        	else if(curr_zer>k){
        		while(l<r and curr_zer>k){
        			if(nums[l]==0){
        				curr_zer--;
        			}
        			l++;
        		}
        	}
        	r++;

        }
        return ans;
    }
};

int main(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	Solution ob;
	cout<<ob.longestOnes(a,k)<<endl;
}