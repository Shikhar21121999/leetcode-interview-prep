# include <bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>
# define space " "
# define newLine "\n"


// important is to only set 0 corrosponding to initial 0 values
// and not derived 0's

// solution 1:
// create an extra array and keep on marking 0's in that
// traverse given array and keep marking in second at end
// put first = second or vice versa

// solution 2:
// create 1 set: keep marking corrosponding rows and columns in it
// at end put all the rows, columns as zero

// solution 3:
// effectively use matrix provided and store required information in matrix itself
// store state for row and column in first elements or row and columns respectively
// for 0th use a variable for columns and for row remaing same

void setZeroes(vector<vector<int>>& matrix) {
	int col0 = 0;
	int rows = matrix.size();
	int cols = matrix[0].size();

	// set the state of rows and columns
	for (int i=0; i < rows; i++) {
		// in case first column
		if (matrix[i][0] == 0) { 
			col0 = 1;
		}
		for (int j = 1; j < cols; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = matrix[0][j] = 0;
			}
		} 
	}

	for (auto x: matrix) {
		for (auto y: x) {
			cout << y << space;
		}
		cout << newLine;
	}

	cout << col0 << newLine;

	// set zeroes using set states
	for (int i = rows - 1; i >= 0; i--) {
		for (int j = cols -1; j >= 1; j--) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
		if (col0) {
			matrix[i][0] = 0;
		}
	}
}

int main() {
	vector <vector <int> > sample{{-4,-2147483648,6,-7,0},{-8,6,-8,-6,0},{2147483647,2,-9,-6,-10}};
	for (auto x: sample) {
		for (auto y: x) {
			cout << y << space;
		}
		cout << newLine;
	}
	cout << newLine;
	setZeroes(sample);
	cout << newLine;
	for (auto x: sample) {
		for (auto y: x) {
			cout << y << space;
		}
		cout << newLine;
	}
}