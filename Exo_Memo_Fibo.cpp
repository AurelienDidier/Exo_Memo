#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>

using namespace std;

static vector<int> memo;

int fibo(int n) {
	if (memo.size()==0) {
		memo.push_back(1);
		memo.push_back(1);
	}
	if (memo.size() > n) {
		return memo[n];
	} else {

		for (int i = memo.size(); i <= n; i++) {

			int val = memo[i - 1] + memo[i - 2];

			memo.push_back(val);
		}
	}
	return memo[n];
}

int main() {

	int result= fibo(10);
	int result2= fibo(4);
	cout << result;
	cout << result2;
}
