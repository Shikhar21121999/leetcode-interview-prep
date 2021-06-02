// max area of island
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

vi parent;
vi len;

// find set in which v is present
int find_set(int v){
	if(parent[v]==v){
		return v;
	}
	return parent[v]=find_set(parent[v]);
}

// union set
void union_set(int a,int b){
	a=find_set(a);
	b=find_set(b);
	if(a==b)return;

	if(len[a]<len[b]){
		swap(a,b);
	}

	// size of a is bigger
	parent[b]=a;
	len[a]+=len[b];
}

class Solution{
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int n=grid.size();
        int m=grid[0].size();
        int totalel=n*m;

		// initialize the dsu
		parent.resize(totalel+1);
		for(int i=1;i<=totalel;i++){
			parent[i]=i;
		}
		len.resize(totalel+1,1);
        
		bool ansZero=true;
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		
        		// check if the cell is a valid island
        		if(grid[i][j]==1){
        			ansZero=false;
        			// iterative connect it with all the possible island
        			// as we are doing it iterative
        			// we need to check for bottom and right island
        			int cell1num=i*m+j+1;
        			// bottom
        			if(i+1<n and grid[i+1][j]==1){
        				int cell2num=(i+1)*m+j+1;
        				union_set(cell1num,cell2num);
        			}
        			// right
        			if(j+1<m and grid[i][j+1]==1){
        				int cell2num=i*m+j+2;
        				union_set(cell1num,cell2num);
        			}

        		}
        	}
        }
        if(ansZero)return 0;
        
        // find the size of longest connected component
        int ans=0;
        for(int i=1;i<=totalel;i++){
        	if(ans<len[i]){
        		ans=len[i];
        	}
        }
        return ans;
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;

		vvi grid(n,vi(m));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>grid[i][j];
			}
		}

		Solution ob;
		cout<<ob.maxAreaOfIsland(grid)<<endl;	
	}
	
}



