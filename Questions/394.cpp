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

// string decodeString(string s) {
//     int i = 0;
//     return dfs(s, i);
// }

// string dfs(string s, int& i){
//     string res = "";
//     if(i >= s.size()) return res;
//     while(i < s.size()){
//         if(isalpha(s[i])) res += s[i];
//         else if(s[i] == ']') return res;
//         else if(isdigit(s[i])){
//             int loops = 0;
//             while(isdigit(s[i])) loops = loops * 10 + s[i++] - '0';
//             string pat = dfs(s, ++i);
//             for(int j = 0; j < loops; ++j) res += pat;
//         }
//         ++i;
//     }
//     return res;
// }

string recur(string s, int& i) {
	// store result
	string result = "";

	for (;i<s.length(); i++) {
		// if is a character
		if (isalpha(s[i])) result += s[i];
		else if (s[i] == ']') return result;
		else if (isdigit(s[i])) {
			int loops = 0;
			while(isdigit(s[i])) loops = loops*10 + s[i++] - '0';
			string pat = recur(s, ++i);
			for (int j=0; j<loops; ++j) result += pat;
		}
	}
	return result;
}

string decodeString(string s) {
    int i = 0;
    return recur(s, i);
}

int main() {
	string s;
	cin >> s;
	cout << decodeString(s);	
}