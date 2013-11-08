#include <stdio.h>
#include <string.h>
#include <bitset>
#include <unordered_map>
#include <iostream>

#define COLUMN_COUNT 15
#define BITSET_SIZE 234

using namespace std;

void read_game(bitset<BITSET_SIZE> &, int *, int *, int *, int *);
char search(bitset<BITSET_SIZE> &, int, int, int, int, char, unordered_map<bitset<BITSET_SIZE>, char> &);

int main(void) {
	int n, i, r, c, x, y, w;
	bitset<BITSET_SIZE> board;
	string player = "AB";
	unordered_map<bitset<BITSET_SIZE>, char> history;

	scanf("%d\n", &n);

	for (i=0; i<n; i++) {
		board.reset();
		read_game(board, &r, &c, &x, &y);
		printf("Case #%d: %c\n", i+1, player[search(board, r, c, x, y, 1, history)]);
	}

    return 0;
}

void read_game(bitset<BITSET_SIZE> &board, int *r, int *c, int *x, int *y)
{
	int i, j;
	char s;

	scanf("%d %d\n", r, c);
	for (i=0; i<*r; i++) {
		for (j=0; j<*c; j++) {
			scanf("%c", &s);
			board[(i * COLUMN_COUNT) + j] = (s == '#' || s == 'K') ? 0 : 1;
			*x = s == 'K' ? i : *x;
			*y = s == 'K' ? j : *y;
		}
		scanf("\n");
	}
}

char search(bitset<BITSET_SIZE> &board, int r, int c, int x, int y, char player,
			unordered_map<bitset<BITSET_SIZE>, char> &history)
{
	int x_start, x_end, y_start, y_end, i, j, move_idx;
	unsigned int start_point;
	char sub_result;

	start_point = (x * COLUMN_COUNT) + y;
	bitset<BITSET_SIZE> start_point_bitset(start_point);
	start_point_bitset <<= 225;
	start_point_bitset[BITSET_SIZE - 1] = player;

	unordered_map<bitset<BITSET_SIZE>, char>::const_iterator cache = history.find(
		start_point_bitset | board);

	if (cache != history.end()) {
		return cache->second;
	}

	x_start = (x > 0) ? x-1 : x;
	x_end = (x < r-1) ? x+1 : x;
	y_start = (y > 0) ? y-1 : y;
	y_end = (y < c-1) ? y+1 : y;

	for (i=x_start; i<=x_end; ++i) {
		for (j=y_start; j<=y_end; ++j) {
			move_idx = (i * COLUMN_COUNT) + j;

			if (board[move_idx] == 0) {
				continue;
			}

			board[move_idx] = 0; 
			sub_result = search(board, r, c, i, j, (player + 1) % 2, history);
			board[move_idx] = 1;

			if (sub_result != player) {
				player = sub_result;
				goto END;
			}
		}
	}

	END:
		history[start_point_bitset | board] = player;
		return player;
}
