#include <stdio.h>   
#include "questions.h"

int main() {

    // --- Setup ---
    struct Question questions[50];
    int questionCount = 0;

    // Load all questions from questions.c
    loadQuestions(questions, &questionCount); 

    // Main Meni
    int choice;      // stores whatever number the user picks
    
    printf("\n");
    printf("==============================\n");
    printf("        \n");
    printf("==============================\n");
    printf("  1. Play Game\n");
    printf("  2. View Leaderboard\n");
    printf("  3. Quit\n");
    printf("==============================\n");
    printf("  Enter your choice: ");

    scanf("%d", &choice);   // wait for user to type a number

    // React to their choice
    if (choice == 1) {
        printf("Starting game...\n");
    } else if (choice == 2) {
        printf("Showing leaderboard...\n");
    } else if (choice == 3) {
        printf("Goodbye!\n");
    } else {
        printf("Invalid choice, try again.\n");
    }

    return 0;  // program ends successfully
}

