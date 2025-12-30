
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

int main() {
    int secret_number, guess, attempts = 0, lives = 7;
    int hint_unlocked = 0; // The "Switch" (0 = locked, 1 = unlocked)
    
    srand(time(0)); 
    secret_number = (rand() % 100) + 1;
    // Introduction
    printf("*********************************\n");
    printf("*      THE NUMBER HUNTER        *\n");
    printf("*********************************\n");
    char name[50];
printf("Enter your Hunter Name: ");
fgets(name, sizeof(name), stdin); 
printf("WELCOME TO THE ULTIMATE GUESSER, %s!\n", name);
    printf("Initializing secret number...\n");
    do {   
        // 1. Every turn, check if the hint should be displayed
        if (hint_unlocked == 1) {
            printf("\n>>> [ ACTIVE HINT: The number is %s ] <<<\n", 
                   (secret_number % 2 == 0) ? "EVEN" : "ODD");
        }

        printf("\nHEALTH: ");
        for(int i = 0; i < lives; i++) printf("\xe2\x9d\xa4\t");
        
        printf("\nEnter guess (0 for hint): ");
        scanf("%d", &guess);

        // 2. The Hint Logic
        if(guess == 0) {
            if (hint_unlocked == 1) {
                printf("(!) You already have the hint, buddy!\n");
            } 
            else if (lives > 2) {
                lives -= 2;
                hint_unlocked = 1; 
                printf("💡 Hint purchased! Check above your next turn.\n");
            } 
            else {
                printf("❌ Too low on health for a hint!\n");
            }
            continue; 
        }

        // 3. Regular Guess Logic
        attempts++;
        if(guess > secret_number) {
            printf("\aTOO HIGH! 📈\n");
            lives--;
        } 
        else if (guess < secret_number) {
            printf("\aTOO LOW! 📉\n");
            lives--;
        }

    } while(guess != secret_number && lives > 0);

    // ... (Win/Loss messages stay the same) ...
    if(lives > 0) {
    printf("\n==================================");
    printf("\n🏆 VICTORY, %s!", name);
    printf("\nNumber: %d | Attempts: %d", guess, attempts);
    printf("\n==================================\n");
}
   
    return 0;
}
