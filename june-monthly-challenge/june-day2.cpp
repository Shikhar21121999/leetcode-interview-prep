// interleaving string

#include<bits/stdc++.h>
using namespace std;

int dp[105][105];
class Solution{
public:
	bool recur(string s1, string s2,string s3,int i,int j,int k){
		// base case
		if(k==0)return true;
		// dp already calculated
		if(dp[i][j]!=-1)return dp[i][j];
		int p,q;
		p=0;q=0;
		if(i-1>=0 and s3[k-1]==s1[i-1])p=recur(s1,s2,s3,i-1,j,k-1);
		if(j-1>=0 and s3[k-1]==s2[j-1])q=recur(s1,s2,s3,i,j-1,k-1);
		return dp[j][k]=p or q;
	}
	bool isInterleave(string s1, string s2, string s3) {
        int n,m,len;
        n=s1.length();
        m=s2.length();
        len=s3.length();
        cout<<n<<" "<<m<<" "<<len<<endl;
        if(n+m!=len)return false;
        dp[n][m];
        memset(dp,-1,sizeof(dp));
        return recur(s1,s2,s3,n,m,len);
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2,s3;
		cin>>s1>>s2>>s3;
		Solution ob;
		cout<<ob.isInterleave(s1,s2,s3)<<endl;
	}
}