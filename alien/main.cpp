#include <iostream>
#include <bitset>

using namespace std;

int main(void) {
	int n, l, d, i, j, idx;
	bool multi;
	string word;
	bitset<5000> **index;
	bitset<5000> ans, c;

	cin >> l >> d >> n;

	index = new bitset<5000> * [l];
	for (i=0; i<l; ++i) {
		index[i] = new bitset<5000>[26];
	}

	for (i=0; i<d; ++i) {
		cin >> word;
		for (j=0; j<l; ++j) {
			index[j][word[j]-'a'][i] = 1;
		}
	}

	for (i=0; i<n; ++i) {
		cin >> word;
		ans.set();
		idx = 0;

		for (j=0; j<l; ++j) {
			multi = (word[idx] == '(');
			c.reset();
			if (multi) {
				while (word[++idx] != ')') {
					c = c | index[j][word[idx] - 'a'];
				}
			} else {
				c = index[j][word[idx] - 'a'];
			}
			++idx;
			ans = ans & c;
		}

		cout << "Case #" << i+1 << ": " << ans.count() << endl;
	}

    return 0;
}
