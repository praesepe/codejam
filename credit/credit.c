#include <stdio.h>
#include <string.h>

int main(void) {
	short price_idx[1001];
	char garbage[10100];
	int n, c, p, ii, i, j;

	scanf("%d\n", &n);

	for (i=1; i<=n; i++) {
		memset(price_idx, 0, sizeof(short) * 1000);
		scanf("%d\n", &c);
		scanf("%d\n", &ii);

		for (j=1; j<=ii; j++) {
			scanf("%d", &p);
			if ( p >= c) {
				continue;
			}

			if (price_idx[c - p]) {
				printf("Case #%d: %d %d\n", i, price_idx[c - p], j);
				break;
			}

			price_idx[p] = j;
		}
		
		gets(garbage);
	}
    return 0;
}
