#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int nn, i, j, n, *a, *b;
	long long sum;

	cin >> nn;

	for (i=0; i<nn; ++i) {
		cin >> n;

		a = new int[n];
		b = new int[n];

		for (j=0; j<n; ++j) {
			cin >> a[j];
		}

		for (j=0; j<n; ++j) {
			cin >> b[j];
		}

		sort(a, a+n);
		sort(b, b+n);
		
		sum = 0;
		for (j=0; j<n; ++j) {
			sum += (long long) a[j] * b[n-j-1];
		}

		cout << "Case #" << i+1 << ": " << sum << endl;

		delete a;
		delete b;
	}

    return 0;
}
