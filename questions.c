// Stores all the questions and handles the game round logics. 

#include <stdio.h>    
#include <string.h>
#include <ctype.h>     // necessary for toupper
#include <stdlib.h>   // necessary for rand and srand
#include <time.h>     // necessary for time and seeding the random number generator

#ifdef _WIN32
  #include <windows.h>
  #define SLEEP(s) Sleep((s)*1000)

#else
  #include <unistd.h>
  #define SLEEP(s) sleep(s)
#endif

#include "questions.h"
#include "scores.h"

// Load all questions for the different categories

void loadQuestions(Category categories[], int *total_categories) {

    int idx; // tracks the current question slot


    // Geography
    strcpy(categories[0].category_name, "Geography");
    categories[0].question_count = 0;
    

    idx = categories[0].question_count;
    strcpy(categories[0].questions[idx].question_text, "What is the capital of Guyana?");
    strcpy(categories[0].questions[idx].options[0], "A. Berbice");
    strcpy(categories[0].questions[idx].options[1], "B. Georgetown");
    strcpy(categories[0].questions[idx].options[2], "C. Linden");
    strcpy(categories[0].questions[idx].options[3], "D. Bartica");
    categories[0].questions[idx].correct_option = 'B';
    categories[0].question_count++;

    idx = categories[0].question_count;
    strcpy(categories[0].questions[idx].question_text, "Which is the longest river in Guyana?");
    strcpy(categories[0].questions[idx].options[0], "A. Demerara");
    strcpy(categories[0].questions[idx].options[1], "B. Berbice");
    strcpy(categories[0].questions[idx].options[2], "C. Essequibo");
    strcpy(categories[0].questions[idx].options[3], "D. Mazaruni");
    categories[0].questions[idx].correct_option = 'C';
    categories[0].question_count++;

    idx = categories[0].question_count;
    strcpy(categories[0].questions[idx].question_text, "Which country borders Guyana to the west?");
    strcpy(categories[0].questions[idx].options[0], "A. Brazil");
    strcpy(categories[0].questions[idx].options[1], "B. Suriname");
    strcpy(categories[0].questions[idx].options[2], "C. Venezuela");
    strcpy(categories[0].questions[idx].options[3], "D. Trinidad");
    categories[0].questions[idx].correct_option = 'C';
    categories[0].question_count++;

    idx = categories[0].question_count;
    strcpy(categories[0].questions[idx].question_text, "What is the highest mountain in Guyana?");
    strcpy(categories[0].questions[idx].options[0], "A. Mount Roraima");
    strcpy(categories[0].questions[idx].options[1], "B. Ayanganna");
    strcpy(categories[0].questions[idx].options[2], "C. Maringma");
    strcpy(categories[0].questions[idx].options[3], "D. Chinak Meru");
    categories[0].questions[idx].correct_option = 'A';
    categories[0].question_count++;

    idx = categories[0].question_count;
    strcpy(categories[0].questions[idx].question_text, "Which ocean borders Guyana to the north?");
    strcpy(categories[0].questions[idx].options[0], "A. Pacific Ocean");
    strcpy(categories[0].questions[idx].options[1], "B. Indian Ocean");
    strcpy(categories[0].questions[idx].options[2], "C. Arctic Ocean");
    strcpy(categories[0].questions[idx].options[3], "D. Atlantic Ocean");
    categories[0].questions[idx].correct_option = 'D';
    categories[0].question_count++;

    // History
    strcpy(categories[1].category_name, "History");
    categories[1].question_count = 0;

    idx = categories[1].question_count;
    strcpy(categories[1].questions[idx].question_text, "In what year did Guyana gain independence?");
    strcpy(categories[1].questions[idx].options[0], "A. 1962");
    strcpy(categories[1].questions[idx].options[1], "B. 1966");
    strcpy(categories[1].questions[idx].options[2], "C. 1970");
    strcpy(categories[1].questions[idx].options[3], "D. 1975");
    categories[1].questions[idx].correct_option = 'B';
    categories[1].question_count++;

    idx = categories[1].question_count;
    strcpy(categories[1].questions[idx].question_text, "Who was Guyana's first Prime Minister?");
    strcpy(categories[1].questions[idx].options[0], "A. Desmond Hoyte");
    strcpy(categories[1].questions[idx].options[1], "B. Cheddi Jagan");
    strcpy(categories[1].questions[idx].options[2], "C. Forbes Burnham");
    strcpy(categories[1].questions[idx].options[3], "D. Samuel Hinds");
    categories[1].questions[idx].correct_option = 'C';
    categories[1].question_count++;

    idx = categories[1].question_count;
    strcpy(categories[1].questions[idx].question_text, "What was Guyana formerly known as?");
    strcpy(categories[1].questions[idx].options[0], "A. British Honduras");
    strcpy(categories[1].questions[idx].options[1], "B. British Guiana");
    strcpy(categories[1].questions[idx].options[2], "C. Dutch Guiana");
    strcpy(categories[1].questions[idx].options[3], "D. French Guiana");
    categories[1].questions[idx].correct_option = 'B';
    categories[1].question_count++;

    idx = categories[1].question_count;
    strcpy(categories[1].questions[idx].question_text, "In what year did Guyana become a Republic?");
    strcpy(categories[1].questions[idx].options[0], "A. 1966");
    strcpy(categories[1].questions[idx].options[1], "B. 1968");
    strcpy(categories[1].questions[idx].options[2], "C. 1970");
    strcpy(categories[1].questions[idx].options[3], "D. 1972");
    categories[1].questions[idx].correct_option = 'C';
    categories[1].question_count++;

    idx = categories[1].question_count;
    strcpy(categories[1].questions[idx].question_text, "Which European country first colonised Guyana?");
    strcpy(categories[1].questions[idx].options[0], "A. Britain");
    strcpy(categories[1].questions[idx].options[1], "B. France");
    strcpy(categories[1].questions[idx].options[2], "C. Spain");
    strcpy(categories[1].questions[idx].options[3], "D. Netherlands");
    categories[1].questions[idx].correct_option = 'D';
    categories[1].question_count++;

    // Sports 
    strcpy(categories[2].category_name, "Sports");
    categories[2].question_count = 0;

    idx = categories[2].question_count;
    strcpy(categories[2].questions[idx].question_text, "Which sport is considered Guyana's national sport?");
    strcpy(categories[2].questions[idx].options[0], "A. Football");
    strcpy(categories[2].questions[idx].options[1], "B. Cricket");
    strcpy(categories[2].questions[idx].options[2], "C. Basketball");
    strcpy(categories[2].questions[idx].options[3], "D. Volleyball");
    categories[2].questions[idx].correct_option = 'B';
    categories[2].question_count++;

    idx = categories[2].question_count;
    strcpy(categories[2].questions[idx].question_text, "Which Guyanese cricketer acquired the nickname 'Tiger'?");
    strcpy(categories[2].questions[idx].options[0], "A. Alvin Kallicharran");
    strcpy(categories[2].questions[idx].options[1], "B. Shivnarine Chanderpaul");
    strcpy(categories[2].questions[idx].options[2], "C. Clive Lloyd");
    strcpy(categories[2].questions[idx].options[3], "D. Lance Gibbs");
    categories[2].questions[idx].correct_option = 'B';
    categories[2].question_count++;

    idx = categories[2].question_count;
    strcpy(categories[2].questions[idx].question_text, "What is the name of Guyana's national cricket ground?");
    strcpy(categories[2].questions[idx].options[0], "A. Kensington Oval");
    strcpy(categories[2].questions[idx].options[1], "B. Providence Cricket Stadium");
    strcpy(categories[2].questions[idx].options[2], "C. Sabina Park");
    strcpy(categories[2].questions[idx].options[3], "D. Queens Park Oval");
    categories[2].questions[idx].correct_option = 'B';
    categories[2].question_count++;

    idx = categories[2].question_count;
    strcpy(categories[2].questions[idx].question_text, "What year did the Guyana Amazon Warriors win CPL?");
    strcpy(categories[2].questions[idx].options[0], "A. 2022");
    strcpy(categories[2].questions[idx].options[1], "B. 2023");
    strcpy(categories[2].questions[idx].options[2], "C. 2024");
    strcpy(categories[2].questions[idx].options[3], "D. 2020");
    categories[2].questions[idx].correct_option = 'B';
    categories[2].question_count++;

    idx = categories[2].question_count;
    strcpy(categories[2].questions[idx].question_text, "Which Guyanese athlete competed in the Olympics for sprinting?");
    strcpy(categories[2].questions[idx].options[0], "A. James Gilkes");
    strcpy(categories[2].questions[idx].options[1], "B. Colin Boyce");
    strcpy(categories[2].questions[idx].options[2], "C. Aliann Pompey");
    strcpy(categories[2].questions[idx].options[3], "D. All of the above");
    categories[2].questions[idx].correct_option = 'D';
    categories[2].question_count++;

    // Culture 
    strcpy(categories[3].category_name, "Culture");
    categories[3].question_count = 0;

    idx = categories[3].question_count;
    strcpy(categories[3].questions[idx].question_text, "What is the national dish of Guyana?");
    strcpy(categories[3].questions[idx].options[0], "A. Curry and Roti");
    strcpy(categories[3].questions[idx].options[1], "B. Pepperpot");
    strcpy(categories[3].questions[idx].options[2], "C. Cook-up Rice");
    strcpy(categories[3].questions[idx].options[3], "D. Metemgee");
    categories[3].questions[idx].correct_option = 'B';
    categories[3].question_count++;

    idx = categories[3].question_count;
    strcpy(categories[3].questions[idx].question_text, "What is the national flower of Guyana?");
    strcpy(categories[3].questions[idx].options[0], "A. Sunflower");
    strcpy(categories[3].questions[idx].options[1], "B. Orchid");
    strcpy(categories[3].questions[idx].options[2], "C. Victoria Amazonica");
    strcpy(categories[3].questions[idx].options[3], "D. Hibiscus");
    categories[3].questions[idx].correct_option = 'C';
    categories[3].question_count++;

    idx = categories[3].question_count;
    strcpy(categories[3].questions[idx].question_text, "What is the national bird of Guyana?");
    strcpy(categories[3].questions[idx].options[0], "A. Toucan");
    strcpy(categories[3].questions[idx].options[1], "B. Scarlet Macaw");
    strcpy(categories[3].questions[idx].options[2], "C. Harpy Eagle");
    strcpy(categories[3].questions[idx].options[3], "D. Parrot");
    categories[3].questions[idx].correct_option = 'C';
    categories[3].question_count++;

    idx = categories[3].question_count;
    strcpy(categories[3].questions[idx].question_text, "Which holiday in Guyana is known as the festival of colours?");
    strcpy(categories[3].questions[idx].options[0], "A. Eid ul-Fitr");
    strcpy(categories[3].questions[idx].options[1], "B. Phagwah");
    strcpy(categories[3].questions[idx].options[2], "C. Diwali");
    strcpy(categories[3].questions[idx].options[3], "D. Mashramani");
    categories[3].questions[idx].correct_option = 'B';
    categories[3].question_count++;

    idx = categories[3].question_count;
    strcpy(categories[3].questions[idx].question_text, "What does 'Mashramani' celebrate in Guyana?");
    strcpy(categories[3].questions[idx].options[0], "A. Independence Day");
    strcpy(categories[3].questions[idx].options[1], "B. Republic Day");
    strcpy(categories[3].questions[idx].options[2], "C. Emancipation Day");
    strcpy(categories[3].questions[idx].options[3], "D. Arrival Day");
    categories[3].questions[idx].correct_option = 'B';
    categories[3].question_count++;

    // Nature
    strcpy(categories[4].category_name, "Nature");
    categories[4].question_count = 0;

    idx = categories[4].question_count;
    strcpy(categories[4].questions[idx].question_text, "What percentage of Guyana is covered by rainforest?");
    strcpy(categories[4].questions[idx].options[0], "A. 50%");
    strcpy(categories[4].questions[idx].options[1], "B. 65%");
    strcpy(categories[4].questions[idx].options[2], "C. 80%");
    strcpy(categories[4].questions[idx].options[3], "D. 90%");
    categories[4].questions[idx].correct_option = 'C';
    categories[4].question_count++;

    idx = categories[4].question_count;
    strcpy(categories[4].questions[idx].question_text, "Guyana is know for having the worlds's largest single drop waterfall, what is its name?");
    strcpy(categories[4].questions[idx].options[0], "A. Niagara Falls");
    strcpy(categories[4].questions[idx].options[1], "B. Kaieteur Falls");
    strcpy(categories[4].questions[idx].options[2], "C. Angel Falls");
    strcpy(categories[4].questions[idx].options[3], "D. Iguazu Falls");
    categories[4].questions[idx].correct_option = 'B';
    categories[4].question_count++;

    idx = categories[4].question_count;
    strcpy(categories[4].questions[idx].question_text, "There lurks a very big snake in Guyana's Rainforest, what is it");
    strcpy(categories[4].questions[idx].options[0], "A. Python");
    strcpy(categories[4].questions[idx].options[1], "B. Pit Viper");
    strcpy(categories[4].questions[idx].options[2], "C. Green Anaconda");
    strcpy(categories[4].questions[idx].options[3], "D. King Cobra");
    categories[4].questions[idx].correct_option = 'C';
    categories[4].question_count++;

    idx = categories[4].question_count;
    strcpy(categories[4].questions[idx].question_text, "What is the largest freshwater fish found in Guyana?");
    strcpy(categories[4].questions[idx].options[0], "A. Piranha");
    strcpy(categories[4].questions[idx].options[1], "B. Arapaima");
    strcpy(categories[4].questions[idx].options[2], "C. Catfish");
    strcpy(categories[4].questions[idx].options[3], "D. Tilapia");
    categories[4].questions[idx].correct_option = 'B';
    categories[4].question_count++;

    idx = categories[4].question_count;
    strcpy(categories[4].questions[idx].question_text, "What is the name of the Protected Nature Reserve in Guyana's Rupununi Region?");
    strcpy(categories[4].questions[idx].options[0], "A. Iwokrama Rainforest");
    strcpy(categories[4].questions[idx].options[1], "B. Aracari");
    strcpy(categories[4].questions[idx].options[2], "C. Splashmins");
    strcpy(categories[4].questions[idx].options[3], "D. Lake Mainstay");
    categories[4].questions[idx].correct_option = 'C';
    categories[4].question_count++;

    *total_categories = 5; 
}

// Prints the questions along with the options
void printQuestion(Question q) {
    printf("\n  Question: %s\n", q.question_text);
    printf("    %s\n", q.options[0]);
    printf("    %s\n", q.options[1]);
    printf("    %s\n", q.options[2]);
    printf("    %s\n", q.options[3]);
}

// prints a question, collects input and checks if correct
void askQuestion(Question q) {
    char answer;
    printQuestion(q);
    printf("\n  Enter your answer (A/B/C/D): ");

    scanf(" %c", &answer);
    answer = toupper(answer); // allows both lowercase and uppercase input

    if (answer == q.correct_option)
        printf("  Correct!\n");
    else
        printf("  Wrong! The correct answer is %c\n", q.correct_option);
}

// Fisher-Yates Shuffle which randomises the index array's order
static void shuffle(int *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1); // picks a random index form 0 up to i
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

// Shows the lives that the player gets based on the selected diffculty
static int livesForDifficulty(int diff) {
    if (diff == 1) return 5;   // Easy   
    if (diff == 2) return 3;   // Medium 
    return 1;                  // Hard   
}

/* Runs one full round and returns the score
   category_choice : 0 = all categories, 1-5 = specific category
   difficulty      : 1=Easy  2=Medium  3=Hard */

int playRound(Category game_bank[], int num_categories,
              int category_choice, int difficulty,
              const char *player_name)
{
    srand((unsigned int)time(NULL)); // syncs with the current time so question can be randomised everytime

    // Build a pool of pointers to every question in the category chosen
    Question *pool[50];
    int pool_size = 0;

    for (int c = 0; c < num_categories; c++) {
        /* Skip categories not selected (0 = all) */
        if (category_choice != 0 && c != category_choice - 1) continue;
        for (int q = 0; q < game_bank[c].question_count; q++) {
            if (pool_size < 50)
                pool[pool_size++] = &game_bank[c].questions[q];
        }
    }

    if (pool_size < 5) {
        printf("\n  Not enough questions for that selection. Try again.\n");
        return 0;
    }

    // Shuffles an index array for random order of questions
    int order[50];
    int i;
    for (i = 0; i < pool_size; i++)
        order[i] = i;
    shuffle(order, pool_size);

    int lives      = livesForDifficulty(difficulty);
    int score      = 0;
    int asked      = 0;
    int base_pts   = (difficulty == 1) ? 10 : (difficulty == 2) ? 20 : 30;

    printf("\n  ============================================\n");
    printf("  Player : %s\n", player_name);
    printf("  Category: %s\n",
           category_choice == 0 ? "All Categories"
                                : game_bank[category_choice - 1].category_name);
    printf("  Difficulty: %s    Lives: %d    Points/Q: %d\n",
           difficulty == 1 ? "Easy" : difficulty == 2 ? "Medium" : "Hard",
           lives, base_pts);
    printf("  ============================================\n");
    printf("  Press ENTER to begin...");

    // clears any left over newline from the buffer and waits on the player
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
    getchar();

    // Main loop for the questions which runs until lives are finished or all questions completed
    while (asked < pool_size && lives > 0) {
        Question *curr = pool[order[asked]];

        // Every 5th question correct is a bonus double point
        int is_bonus = ((asked + 1) % 5 == 0);
        int pts      = is_bonus ? base_pts * 2 : base_pts;

        printf("\n  --------------------------------------------\n");
        printf("  Q%d  |  Lives: %d  |  Score: %d%s\n",
               asked + 1, lives, score,
               is_bonus ? "  [*** BONUS — 2x points! ***]" : "");
        printf("  --------------------------------------------");

        printQuestion(*curr);

        printf("\n  Enter your answer (A/B/C/D): ");
        char answer;
        scanf(" %c", &answer);
        answer = toupper(answer);

        if (answer == curr->correct_option) {
            printf("  Correct! +%d points\n", pts);
            score += pts;
        } else {
            printf("  Wrong! The correct answer was %c.  Lives left: %d\n",
                   curr->correct_option, lives - 1);
            lives--;
        }

        asked++;

        if (lives == 0) {
            printf("\n  No lives remaining — round over!\n");
            break;
        }
    }

    // End of round scoring details
    printf("\n  ============================================\n");
    printf("             ROUND OVER!\n");
    printf("  ============================================\n");
    printf("  Player          : %s\n", player_name);
    printf("  Questions asked : %d\n", asked);
    printf("  Lives remaining : %d\n", lives);
    printf("  FINAL SCORE     : %d\n", score);
    printf("  ============================================\n");

    // Saves the score
    saveScore(player_name, score);
    showPlayerHistory(player_name);
    showLeaderboard();

    return score;
}
