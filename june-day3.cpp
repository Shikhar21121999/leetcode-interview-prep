// max area after horizontal and vertical cuts

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution{
public:
	long long maxLong(long long a,long long b){
		if(a>b)return a;
		return b;
	}
	long long maxConsecDiff(vi a,int term){
		long long ans=maxLong(a[0]-0,term-a[a.size()-1]);
		// cout<<a[0]-0<<" "<<term<<" "<<a[a.size()-1]<<endl;
		for(int i=1;i<a.size();i++){
			ans=maxLong(ans,a[i]-a[i-1]);
		}
		return ans;
	}
	long long maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        // first we sort the horizontal and vertical cuts vector
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        // find the max difference btw two consecutive elements
        return maxConsecDiff(horizontalCuts,h)*maxConsecDiff(verticalCuts,w);
        // return maxConsecDiff(horizontalCuts)*maxConsecDiff(verticalCuts);
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int h,w;
		cin>>h>>w;
		int horSize,vertSize;
		cin>>horSize;

		vi horizontalCuts(horSize);
		for(int i=0;i<horSize;i++){
			cin>>horizontalCuts[i];
		}
		cin>>vertSize;
		vi verticalCuts(vertSize);
		for(int i=0;i<vertSize;i++){
			cin>>verticalCuts[i];
		}
		Solution ob;
		cout<<ob.maxArea(h,w,horizontalCuts,verticalCuts)<<endl;
	}
}