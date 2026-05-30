#ifndef QUESTIONS_H
#define QUESTIONS_H

// The Question struct - used by all files
struct Question {
    char text[256];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correct;
    char topic[50];
};

// Function announcements
void loadQuestions(struct Question questions[], int *count);
void printQuestion(struct Question q);

#endif