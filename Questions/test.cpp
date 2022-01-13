#include <bits/stdc++.h>
using namespace std;

int main() {
	string inp;
	cin >> inp;

	for (int i=0; i<inp.length(); i++) {
		cout << int(inp[i]) - 97 << " ";
	}
}