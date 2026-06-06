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
static void sortScores(ScoreEntry entries[], int count) {
	for (int i=0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (entries[j].score < entries[j + 1].score) {
				ScoreEntry temp = entries[j];
                entries[j] = entries[j + 1];
                entries[j + 1] = temp;
            }
        }
    }
}

void showLeaderboard(void) {
	FILE *f = fopen(SCORE_FILE, "r");
	if (!f) return;

	ScoreEntry entries[100];
	int count = 0;
	while (fscanf(f, "%s %d", entries[count].player_name, &entries[count].score) == 2) {
        count++;
    }
    fclose(f);

    sortScores(entries, count);

    printf("\n  --- TOP 5 LEADERBOARD ---\n");
    for (int i = 0; i < count && i < 5; i++) {
        printf("  %d. %-15s : %d\n", i + 1, entries[i].player_name, entries[i].score);
    }
}

void showPlayerHistory(const char *name) {
	FILE *f = fopen(SCORE_FILE, "r");
	if (!f) return;

	char current_name[MAX_NAME_LEN];
	int score;
	printf("\n --- History for %s ---\n", name);
	while (fscanf(f, "%s %d", current_name, &score) == 2) {
		if (strcmp(current_name, name) == 0) {
			printf("  Score: %d\n", score);
		}
	}
	fclose(f);
}
	
