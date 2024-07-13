#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to clear the console screen
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Function to generate a random number between min and max
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print colored text
void print_colored_text(const char *text, const char *color) {
    printf("%s%s\033[0m", color, text);
}

// Function to print the Grim Reaper ASCII art
void print_grim_reaper() {
    printf("\033[1;38;2;255;0;0m"); // Set text to bold red
    printf("              ...                            \n");
    printf("             ;::::;                           \n");
    printf("           ;::::; :;                          \n");
    printf("         ;:::::'   :;                         \n");
    printf("        ;:::::;     ;.                        \n");
    printf("       ,:::::'       ;           OOO\\         \n");
    printf("       ::::::;       ;          OOOOO\\        \n");
    printf("       ;:::::;       ;         OOOOOOOO       \n");
    printf("      ,;::::::;     ;'         / OOOOOOO      \n");
    printf("    ;:::::::::`. ,,,;.        /  / DOOOOOO    \n");
    printf("  .';:::::::::::::::::;,     /  /     DOOOO   \n");
    printf(" ,::::::;::::::;;;;::::;,   /  /        DOOO  \n");
    printf(";`::::::`'::::::;;;::::: ,#/  /          DOOO \n");
    printf(":`:::::::`;::::::;;::: ;::#  /            DOOO\n");
    printf("::`:::::::`;:::::::: ;::::# /              DOO\n");
    printf("`:`:::::::`;:::::: ;::::::#/               DOO\n");
    printf(" :::`:::::::`;; ;:::::::::##                OO\n");
    printf(" ::::`:::::::`;::::::::;:::#                OO\n");
    printf(" `:::::`::::::::::::;'`:;::#                O \n");
    printf("  `:::::`::::::::;' /  / `:#                  \n");
    printf("   ::::::`:::::;'  /  /   `#                 \n");
    printf("GRIM REAPER\n");
    printf("\033[0m"); // Reset text to default
}

int main() {
    char os[20];

    #ifdef _WIN32
        strcpy(os, "Windows");
    #elif __APPLE__
        strcpy(os, "macOS");
    #elif __linux__
        strcpy(os, "Linux");
    #elif __FreeBSD__
        strcpy(os, "BSD");
    #else
        strcpy(os, "Unknown OS");
    #endif

    srand(time(NULL)); // Seed the random number generator
    int secretNumber = generate_random_number(1, 10);
    int userGuess;
    int attempts = 5;

    clear_screen(); // Clear the screen for a fresh start
    print_grim_reaper(); // Print the Grim Reaper ASCII art

    print_colored_text("System detected: ", "\033[1;38;2;0;255;0m"); // Bold green text
    printf("%s\n", os);
    printf("\033[0m"); // Reset text to default

    printf("\033[1;38;2;255;255;0m"); // Set text to bold yellow
    printf("Enter the forbidden realm. Guess the number if you dare (between 1 and 10):\n");
    printf("\033[0m"); // Reset text to default

    for (int i = 0; i < attempts; i++) {
        printf("\033[1;38;2;255;165;0m"); // Set text to bold orange
        printf("Attempt %d: ", i + 1);
        printf("\033[0m"); // Reset text to default
        scanf("%d", &userGuess);

        if (userGuess == secretNumber) {
            printf("\033[1;38;2;0;255;0m"); // Set text to bold green
            printf("Congratulations, mortal. You have guessed the number correctly. Peace shall befall you... for now.\n");
            printf("\033[0m"); // Reset text to default
            return 0;
        } else {
            if (userGuess < secretNumber) {
                printf("\033[1;38;2;255;0;0m"); // Set text to bold red
                printf("Wrong guess. The number is higher. Try again...\n");
                printf("\033[0m"); // Reset text to default
            } else {
                printf("\033[1;38;2;255;0;0m"); // Set text to bold red
                printf("Wrong guess. The number is lower. Try again...\n");
                printf("\033[0m"); // Reset text to default
            }
        }
    }

    // Diabolical twist - summoning the dark forces after 5 failed attempts
    printf("\033[1;38;2;255;0;0m"); // Set text to bold red
    printf("You have failed the ancient riddle. The abyss opens beneath your feet, prepare for eternal damnation...\n");
    printf("\033[0m"); // Reset text to default

    return 0;
}
