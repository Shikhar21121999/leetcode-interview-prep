# include <bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>
# define space " "
# define newLine "\n"


int main() {
	vi nums{22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14};
	int k = -33;
	int n = nums.size();
	vi prefixSum(n, 0);
	prefixSum[0] = nums[0];

	for (int i=1; i<n; i++) {
		prefixSum[i] = prefixSum[i-1] + nums[i];
	}
	int totalSum = prefixSum[n-1];

	unordered_map <int, int> left, right;
	
	// let's say we change nums[i] to k
	// change k-nums[i] = d

	// change in prefix and suffix respectively let's say for index j
	// if j < i
	// prefix[j] = prefix[j]
	// suffix[j] = suffix[j] + d
	// prefix[j] - suffix[j] = -d
	// if j == i
	// prefix[j] = prefix[j]
	// prefix[j] - suffix[j] = d
	// suffix[j] = suffix[j] + -d
	// if j > i
	// prefix[j] = prefix[j] + d
	// suffix[j] = suffix[j]
	// prefix[j] - suffix[j] = d

	// so basically for each change we have to see 

	// count for 0
	for (int i=0; i<n; i++) {
		// find the frequency of change in the range j > i
		// find the frequence of -change in the range j <= i
	}
}