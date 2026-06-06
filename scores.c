#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scores.h"

void initScores(void) {
	FILE *f = fopen(SCORE_FILE, "a");
	if (f) {
			fprintf(f, "%s %d\n", name, score);
			fclose(f);
	}
}

//sorting the scores
