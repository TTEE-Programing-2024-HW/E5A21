#include <stdio.h>
#include <stdlib.h> // For system("cls")
#include <conio.h> // For getch() function
#include <string.h>

// Function to display Christmas tree
void display_christmas_tree() {
    printf("              *\n");
    printf("             ***\n");
    printf("            *****\n");
    printf("           *******\n");
    printf("          *********\n");
    printf("         ***********\n");
    printf("        *************\n");
    printf("       ***************\n");
    printf("             |||\n");
    printf("             |||\n");
    printf("             |||\n");
    printf("              |||\n");
    printf("             |||||\n");
    printf("            |||||||\n");
    printf("           |||||||||\n");
    printf("          |||||||||||\n");
    printf("         |||||||||||||\n");
    printf("        |||||||||||||||\n");
    printf("       |||||||||||||||||\n");
    printf("      |||||||||||||||||||\n");
    printf("     |||||||||||||||||||||\n");
    printf("    |||||||||||||||||||||||\n");
    printf("   |||||||||||||||||||||||||\n");
    printf("  |||||||||||||||||||||||||||\n");
    printf(" |||||||||||||||||||||||||||||\n");
    printf("|||||||||||||||||||||||||||||||\n");
    printf("             |||\n");
    printf("             |||\n");
    printf("             |||\n");
}

// Function to display menu
void display_menu() {
    printf("\n--------------------------\n");
    printf("|  a. 畫出直角三角形 |\n");
    printf("|  b. 顯示乘法表 |\n");
    printf("|  c. 結束 |\n");
    printf("--------------------------\n");
}

// Function to draw right triangle based on user input
void draw_triangle() {
    char input;
    int i, j;
    
    printf("\nPlease enter a character between 'a' and 'n': ");
    scanf(" %c", &input);

    // Clear screen
    system("cls");

    // Check if input is within range
    if (input < 'a' || input > 'n') {
        printf("\nInvalid input. Please enter a character between 'a' and 'n'.");
        return;
    }

    // Display right triangle
    for (i = 0; i <= (input - 'a'); i++) {
        for (j = 0; j <= i; j++) {
            printf("%c ", 'A' + j);
        }
        printf("\n");
    }

    // Wait for any key press to clear the screen
    printf("\nPress any key to return to the main menu...");
    getch();
    system("cls");
}

// Function to display multiplication table based on user input
void display_multiplication_table() {
    int n, i, j;

    printf("\nEnter an integer between 1 and 9: ");
    scanf("%d", &n);

    // Clear screen
    system("cls");

    // Check if input is within range
    if (n < 1 || n > 9) {
        printf("\nInvalid input. Please enter an integer between 1 and 9.");
        return;
    }

    // Display multiplication table
    printf("\nMultiplication table for %d:\n\n", n);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d\t", i * j);
        }
        printf("\n");
    }

    // Wait for any key press to clear the screen
    printf("\nPress any key to return to the main menu...");
    getch();
    system("cls");
}

int main() {
    char choice;
    int password_attempts = 0;
    char password[5] = "2024";
    char input_password[5];

    // Loop to validate password
    while (password_attempts < 3) {
        // Clear screen
        system("cls");

        // Display Christmas tree
        display_christmas_tree();
        
        // Display password for reference
        printf("\nPassword: %s\n", password);
        
        // Prompt user for password
        printf("\n請輸入4位數字密碼: ");
        scanf("%s", input_password);

        // Check if password is correct
        if (strcmp(input_password, password) == 0) {
            break;
        } else {
            password_attempts++;
            printf("\nIncorrect password. Attempts left: %d\n", 3 - password_attempts);
            getch(); // Wait for any key press
        }
    }

    // If reached here, user failed 3 attempts
    if (password_attempts == 3) {
        printf("\nToo many incorrect attempts. Exiting program.\n");
        return 0;
    }

    // Loop to display menu and process user choice
    while (1) {
        // Clear screen
        system("cls");

        // Display Christmas tree
        display_christmas_tree();
		system("cls");

        // Display menu
        display_menu();
        
        // Prompt user for choice
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        // Process user choice
        switch (choice) {
            case 'a':
            case 'A':
            	system("cls");
                draw_triangle();
                break;
            case 'b':
            case 'B':
                display_multiplication_table();
                break;
            case 'c':
            case 'C':
                printf("\nContinue? (y/n): ");
                scanf(" %c", &choice);
                if (choice == 'n' || choice == 'N') {
                    printf("\nExiting program.\n");
                    return 0;
                } else if (choice != 'y' && choice != 'Y') {
                    printf("\nInvalid choice. Please enter 'y' or 'n'.\n");
                    getch(); // Wait for any key press
                }
                break;
            default:
                printf("\nInvalid choice. Please enter 'a', 'b', or 'c'.\n");
                getch(); // Wait for any key press
        }
    }

    return 0;
}
