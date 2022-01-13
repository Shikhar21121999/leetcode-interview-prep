# include <bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>
# define pii pair<int,int>
# define vpii vector<pii>
# define vvpii vector<vpii>
# define space " "
# define newLine "\n"
# define vc vector<char>
# define vvc vector<vc>


vector<vector<int>> threeSum(vector<int>& nums) {
    vvi ans;
    int n = nums.size();

    for (int i=0; i<n-2; i++) {
    	if (i>0 && nums[i] == nums[i-1]) continue;
    	int l=i+1; r=n-1;
    	while(l<r) {
    		int sum = nums[i]+nums[l]+nums[r];

    		if(sum < 0) l++;
    		else if (sum > 0)r--;
    		else {
    			ans.push_back(vector<int>{nums[i],nums[l],nums[r]});
    			while(l+1<r && nums[l]==nums[l+1])l++;
                while(l<r-1 && nums[r]==nums[r-1]) r--;
                l++; r--;
    		}
    	}
    }
    return ans;
}

int main () {
	vi sample{-1,0,1,2,-1,-4}
	vvi ans = threeSum(sample);

	for (auto x: ans) {
		for (auto y: x) {
			cout << y << space;
		}
		cout << newLine;
	}
}