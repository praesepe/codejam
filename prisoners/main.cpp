#include <iostream>
#include <climits>

using namespace std;

int bribe(int *, int, int);

int main(void) {
	int n, p, q, i, j;
	int *vq;

	cin >> n;

	for (i=0; i<n; ++i) {
		cin >> p >> q;

		vq = new int[q+2];
		vq[0] = 0;
		vq[q+1] = p+1;
		for (j=1; j<=q; ++j) {
			cin >> vq[j];
		}

		cout << "Case #" << i+1 << ": " << bribe(vq, q, p) << endl;
		delete [] vq;
	}

    return 0;
}

int bribe(int *vq, int q, int p)
{
	int *coins, i, j, k, min, left, right, cost;

	coins = new int[q*q];

	for (i=0; i<=q-1; ++i) {
		for (j=0; j<=q-1-i; ++j) {
			min = INT_MAX;
			for (k=j; k<=j+i; k++) {
				left = (j <= k-1) ? coins[j*q + k-1] : 0;
				right = (j+i >= k+1) ? coins[(k+1)*q + j+i] : 0;
				min = (left + right <= min) ? left + right : min;
			}
			cost = max(vq[j+i+2] - vq[j] -2, 0);
			coins[j*q + j+i] = min + cost;
		}
	}

	min = coins[q-1];
	delete [] coins;
	return min;
}
