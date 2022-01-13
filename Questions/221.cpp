# include <bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>
# define space " "
# define newLine "\n"
# define vc vector<char>
# define vvc vector<vc>


int maximalSquare(vector<vector<char>>& matrix) {
	int row = matrix.size();
	int col = matrix[0].size();

	vector <int> storage(col,0);
	int pre;
	int ans = 0;
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			int temp = storage[j];
			if (i < 1 && j < 1) {
				storage[j] = matrix[i][j] - '0';
			} else {
				storage[j] = min(min(pre, storage[j-1]), storage[j]) + 1;
			}
			pre = temp;
			ans = max(ans, storage[j]);
		}
	}
	return ans * ans;
}

int main () {
	vvc sample = {{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
	cout << maximalSquare(sample);
}