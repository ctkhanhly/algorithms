/* Amazing Robots Grader */
/* Hal Burch */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
  robots.in: input case
  standard input: student solution
  robots.key: optimal length
 */

typedef struct {
	int x, y;
	int dist;
	int dir;
} guard_t;

#define MAXGUARD 20
#define MAXN 20

char maze1[MAXN][MAXN+1];
int h1, w1;
guard_t guard1[MAXGUARD];
int ngd1;

char maze2[MAXN][MAXN+1];
int h2, w2;
guard_t guard2[MAXGUARD];
int ngd2;

#define EAST 0
#define WEST 1
#define SOUTH 2
#define NORTH 3

const char dir[4] = "EWSN";

void
readguard(FILE *input, guard_t *g) {
	char d[3];
	int lv;
	fscanf (input, "%d %d %d %s", &g->y, &g->x, &g->dist, d);
	g->dir = -1;
	for (lv = 0; lv < 4; lv++) if (d[0] == dir[lv]) g->dir = lv;
	assert(g->dir != -1);
	g->x--; g->y--;
}

int rx1, ry1;
int rx2, ry2;

void
find_guard(guard_t *g, int tstep, int *x, int *y) {
	int dx, dy;
	dx = dy = 0;
	switch (g->dir) {
	case EAST: dx = +1; break;
	case WEST: dx = -1; break;
	case NORTH: dy = -1; break;
	case SOUTH: dy = +1; break;
	}
	tstep = tstep % (2*(g->dist-1));
	if (tstep > (g->dist-1))
		tstep = 2*(g->dist-1) - tstep;
	*x = g->x + tstep*dx;
	*y = g->y + tstep*dy;
}

int
robot_coll(int ox, int oy, int nx, int ny, guard_t *g, int ng, int tstep) {
	int lv;
	int gx, gy;
	int pgx, pgy;

	for (lv = 0; lv < ng; lv++) {
		find_guard(&g[lv], tstep, &pgx, &pgy);
		find_guard(&g[lv], tstep+1, &gx, &gy);

		/* cannot coincide */
		if (gx == nx && gy == ny) return lv;

		/* no passing */
		if (gx == ox && gy == oy) {
			if (nx == pgx && ny == pgy) {
#if 0
				fprintf (stderr, "pass\n");
#endif
				return lv;
			}
		}
	}
	return -1;
}

void
move(int dx, int dy, int tstep) {
	int nx, ny;
	int rid;

	if (rx1 != -1) {
		nx = rx1 + dx;
		ny = ry1 + dy;
		if (ny < 0 || ny >= h1 || nx < 0 || nx >= w1) {
			nx = -1;
			ny = 0;
		}
		if (nx != -1 && maze1[ny][nx] == '#') {
			nx = rx1;
			ny = ry1;
		}
		rid = robot_coll(rx1, ry1, nx, ny, guard1, ngd1, tstep);
		if (rid != -1) {
			printf ("Guard %d captures robot 1 at time %d.\n", rid+1, tstep+1);
			exit(0);
		}
		rx1 = nx;
		ry1 = ny;
	}
	if (rx2 != -2) {
		nx = rx2 + dx;
		ny = ry2 + dy;
		if (ny < 0 || ny >= h2 || nx < 0 || nx >= w2) {
			nx = -1;
			ny = 0;
		}
		if (nx != -1 && maze2[ny][nx] == '#') {
			nx = rx2;
			ny = ry2;
		}
		rid = robot_coll(rx2, ry2, nx, ny, guard2, ngd2, tstep);
		if (rid != -1) {
			printf ("Guard %d captures robot 2 at time %d.\n", rid+1, tstep+1);
			exit(0);
		}
		rx2 = nx;
		ry2 = ny;
	}
}

int
main(int argc, char **argv) {
	FILE *input, *answer, *key;
	int corr;
	int lv, lv2;
	char line[100];
	int sans;

	input = fopen("robots.in", "r");
	assert(input);

	answer = stdin;

	key = fopen("robots.key", "r");
	assert(key);
	fscanf (key, "%d", &corr);

	fscanf (input, "%d %d", &h1, &w1);
	rx1 = -1;
	for (lv = 0; lv < h1; lv++) {
		fscanf (input, "%s", maze1[lv]);
		for (lv2 = 0; lv2 < w1; lv2++)
			if (maze1[lv][lv2] == 'X') {
				assert(rx1 == -1);
				ry1 = lv;
				rx1 = lv2;
			}
	}
	assert(rx1 != -1);
	fscanf (input, "%d", &ngd1);
	for (lv = 0; lv < ngd1; lv++) readguard(input, &guard1[lv]);

	fscanf (input, "%d %d", &h2, &w2);
	rx2 = -1;
	for (lv = 0; lv < h2; lv++) {
		fscanf (input, "%s", maze2[lv]);
		for (lv2 = 0; lv2 < w2; lv2++)
			if (maze2[lv][lv2] == 'X') {
				assert(rx2 == -1);
				ry2 = lv;
				rx2 = lv2;
			}
	}
	assert(rx2 != -1);
	fscanf (input, "%d", &ngd2);
	for (lv = 0; lv < ngd2; lv++) readguard(input, &guard2[lv]);

	if (!fgets(line, sizeof(line), answer))  {
		printf ("output file empty\n");
		exit(1);
	}
	if (line[0] == '-') {
		if (line[1] == '1' && (line[2] == '\n' || line[2] == '\0')) {
			if (corr == -1) printf ("OK\n");
			else printf ("Your program thinks the maze is unsolvable, but there is a solution.\n");
			exit(0);
		}
	}
	if (line[0] < '0' || line[0] > '9') {
		printf ("first line not integer: %s", line);
		exit(1);
	}
	sans = 0;
	for (lv = 0; line[lv]; lv++) {
		if (line[lv] >= '0' && line[0] <= '9') {
			sans = 10*sans + line[lv] - '0';
		} else if (line[lv] != '\n') {
			printf ("first line not all integer: %s", line);
			exit(1);
		}
	}
	if (sans > 10000) {
		printf ("Number of commands exceeds 10000\n");
		exit(1);
	}

	for (lv = 0; lv < sans; lv++) {
		if (!fgets(line, sizeof(line), answer)) {
			fprintf (stdout, "only %d of %d lines present\n", lv, sans);
			exit(1);
		}
		if (rx1 == -1 && rx2 == -1){
			fprintf (stdout, "Your output gave a command after both robots exited their mazes.\n");
			exit(0);
		}
		if (line[1] != '\n' && line[1] != '\0') {
			fprintf (stdout, "extra characters on move %d: %s", lv+1, line);
			exit(1);
		}
		if (line[0] == 'E') move(+1,0,lv);
		else if (line[0] == 'W') move(-1,0,lv);
		else if (line[0] == 'N') move(0,-1,lv);
		else if (line[0] == 'S') move(0,+1,lv);
		else {
			fprintf (stdout, "unknown move %c\n", line[0]);
			exit(1);
		}
	}
	if (fgets(line, sizeof(line), answer)) {
		fprintf (stdout, "Extra data at the end: %s", line);
		exit(1);
	}
	if (rx1 != -1 || rx2 != -1) {
		printf("After running the moves in your output, \n");
		if (rx1 != -1) printf ("robot 1 (%d,%d) ", rx1+1, ry1+1);
		if (rx2 != -1) printf ("%srobot 2 (%d,%d) %s ", (rx1!=-1?"and " : ""), rx2+1, ry2+1, rx1!=-1?"are":"is");
		printf ("still in the maze.\n");
		exit(0);
	}
	if (sans < corr) {
		printf ("OK\nWarning: student answer %d is better than correct solution %d\n", sans, corr);
	} else if (sans == corr)
		printf ("OK\n");
	else printf ("OK 2\n");

	return 0;
}
