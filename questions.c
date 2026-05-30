#include <stdio.h>
#include <string.h>
#include "questions.h"

void loadQuestions(struct Question questions[], int *count) {

   
}

void printQuestion(struct Question q) {
    printf("\nQuestion: %s\n", q.text);
    printf("  A) %s\n", q.optionA);
    printf("  B) %s\n", q.optionB);
    printf("  C) %s\n", q.optionC);
    printf("  D) %s\n", q.optionD);
}