#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int nn, n, x, y, z, vx, vy, vz, i, j;
	long long sx, sy, sz, svx, svy, svz;
	double a, b, c;
	double mint, mind;

	cin >> nn;

	for (i=0; i<nn; ++i) {
		cin >> n;
		sx = sy = sz = svx = svy = svz = 0;

		for (j=0; j<n; ++j) {
			cin >> x >> y >> z >> vx >> vy >> vz;

			sx += x;
			sy += y;
			sz += z;
			svx += vx;
			svy += vy;
			svz += vz;
		}

		a = svx*svx + svy*svy + svz*svz;
		b = 2*sx*svx + 2*sy*svy + 2*sz*svz;
		c = sx*sx + sy*sy +sz*sz;

		mint = max(0.0, -0.5 * b / a);

		a = a/(n*n);
		b = b/(n*n);
		c = c/(n*n);

		mind = sqrt(max(0.0, mint * mint * a + mint * b + c));

		cout << "Case #" << i + 1 << ": " << mind << " " << mint << endl;
	}

    return 0;
}
