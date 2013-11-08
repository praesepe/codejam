#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
	int nn, i, j, n, m, existed, pos;
	string dir;
	unordered_set<string> dirs;

	cin >> nn;

	for (i=0; i<nn; ++i) {
		dirs.clear();

		cin >> n >> m;

		for (j=0; j<n; ++j) {
			cin >> dir;
			dirs.insert(dir);
			while ((pos = dir.rfind("/")) != 0) {
				dir = dir.substr(0, pos);
				dirs.insert(dir);
			}
		}

		existed = dirs.size();

		for (j=0; j<m; ++j) {
			cin >> dir;
			dirs.insert(dir);
			while ((pos = dir.rfind("/")) != 0) {
				dir = dir.substr(0, pos);
				dirs.insert(dir);
			}
		}

		cout << "Case #" << i+1 << ": " << dirs.size() - existed  << endl;
	}

    return 0;
}
