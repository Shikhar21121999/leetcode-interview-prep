#include <bits/stdc++.h>
using namespace std;

# define vi vector<int>
# define vvi vector<vi>
# define pii pair<int,int>
# define vpii vector<pii>
# define vvpii vector<vpii>
# define space " "
# define newLine "\n"

// Subrectangle Queries

class SubrectangleQueries {
public:
	vector<vector<int>> rectangle;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
		this->rectangle = rectangle;        
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        // traverse through the rectange and change the values
        for(int i=row1; i<=row2; i++) {
        	for (int j=col1; j<=col2; j++) {
        		this -> rectangle[i][j] = newValue;
        	}
        }
    }
    
    int getValue(int row, int col) {
        return this -> rectangle[row][col];
    }

    void printSubrectangle() {
    	for(auto x: this -> rectangle) {
    		for(auto y: x) {
    			cout << y << space;
    		}
    		cout<<newLine;
    	}
    }
};


int main() {
	vector<vector<int>> sample{
        {1, 2, 1},
        {4, 3, 4},
        {3, 2, 1},
        {1, 1, 1},
    };;

	for(auto x:sample) {
		for(auto y: x) {
			cout << y <<space;
		}
		cout<<newLine;
	}
	cout<<newLine;

	SubrectangleQueries* obj = new SubrectangleQueries(sample);
	obj -> updateSubrectangle(0, 0, 3, 2, 5);
	obj -> printSubrectangle();

}