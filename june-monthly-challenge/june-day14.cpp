// Maximum units on a truck

// Greedy approach

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

bool comp(vi a,vi b){
	return a[1]>b[1];
}

class Solution{
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int ans=0;
        for(int i=0;i<boxTypes.size() && truckSize>=0;i++){
        	if(truckSize>=boxTypes[i][0]){
        		ans+=boxTypes[i][0]*boxTypes[i][1];
        		truckSize-=boxTypes[i][0];
        	}
        	else{
        		ans+=truckSize*boxTypes[i][1];
        		truckSize=0;
        	}
        }
        return ans;
    }
};


int main(){
	int n;
	cin>>n;
	vvi boxes(n);
	int boxcnt,unitCnt;
	for(int i=0;i<n;i++){
		cin>>boxcnt>>unitCnt;
		boxes[i]={boxcnt,unitCnt};
	}

	int truckSize;
	cin>>truckSize;
	Solution ob;
	cout<<ob.maximumUnits(boxes,truckSize)<<endl;
}