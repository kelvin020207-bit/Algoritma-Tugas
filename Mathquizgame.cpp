#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0, mistakes = 0, question = 1;
    int a, b, answer, correct;
    char ops[] = {'+', '-', '*', '/'};

    srand(time(0));   
    int id = rand() % 10000;   // random ID for society member

    printf("=== Math Quiz Game ===\n");
    printf("Only 3 mistakes are allowed.\n\n");

    do {
        int maxOperand, points;

        if (question <= 3) {
            maxOperand = 10;  
            points = 5;
        } else if (question <= 6) {
            maxOperand = 30;  
            points = 10;
        } else {
            maxOperand = 60;  
            points = 15;
        }

        a = rand() % maxOperand + 1;
        b = rand() % maxOperand + 1;
        char op = ops[rand() % 4];

        if (op == '/') {
            while (b == 0) {
                b = rand() % maxOperand + 1;
            }
        }

        switch (op) {
            case '+': correct = a + b; break;
            case '-': correct = a - b; break;
            case '*': correct = a * b; break;
            case '/': correct = a / b; break;
        }

        printf("Question %d: %d %c %d = ", question, a, op, b);
        scanf("%d", &answer);

        if (answer == correct) {
            printf("Correct! +%d point(s).\n", points);
            score += points;
        } else {
            printf("WRONG! The right answer is: %d\n", correct);
            mistakes++;
            printf("Mistakes: %d/3\n", mistakes);
        }

        printf("Current Score: %d\n\n", score);
        question++;

    } while (question <= 9 && mistakes < 3);

    printf("\n=== Game Over! ===\n");
    printf("Total Score: %d\n", score);

    if (mistakes >= 3) {
        printf("Game over, you have made three mistakes!.\n");
    } else if (mistakes == 2) {
        printf("Welcome to the Intelligentsia Guild\n");
    } else if (mistakes == 1) {
        printf("Welcome to the Genius Society! Here is your Society ID: %d\n", id);
    } else if (mistakes == 0) {
        printf("Thus Speak Genius Society Number One, Zandar One Kuwabara\n");
    } else {
        printf("Congratulations!\n");
    }

    return 0;
}
