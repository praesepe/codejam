#include <iostream>

using namespace std;

int main(void) {
	int n, i, distinct, base;
	int map[129], a[129];
	unsigned long long total;
	string s;

	for (i=0; i<129; ++i) {
		a[i] = i;
	}
	a[0] = 1;
	a[1] = 0;

	cin >> n;

	for (i=0; i<n; ++i) {
		cin >> s;

		distinct = 0;
		fill_n(map, 129, -1);
		for (string::iterator it = s.begin(); it != s.end(); ++it) {
			if (map[*it] == -1) {
				map[*it] = a[distinct++];
			}
		}

		total = 0;
		base = (distinct >= 2) ? distinct : 2;
		for (string::iterator it = s.begin(); it != s.end(); ++it) {
			total *= base;
			total += map[*it];
		}

		cout << "Case #" << i+1 << ": " << total << endl;
	}

    return 0;
}
