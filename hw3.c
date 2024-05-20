#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define ROWS 9
#define COLS 9

char seats[ROWS][COLS];

// �M���̨�?
void clearScreen() {
    system("CLS");
}

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

// ��ܥD���?
void displayMenu() {
    printf("----------[BookingSystem]----------\n");
    printf("|  a. Available seats             |\n");
    printf("|  b. Arrange for you             |\n");
    printf("|  c. Choose by yourself          |\n");
    printf("|  d. Exit                        |\n");
    printf("-----------------------------------\n");
}

// �ͦ��w�w�q���y��
void generate_seats(char seats[ROWS][COLS]) {
    int reserved = 0;
    while (reserved < 10) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            reserved++;
        }
    }
}

// ��ܮy���
void display_seats(char seats[ROWS][COLS]) {
    printf("  123456789\n");
    for (int i = ROWS; i > 0; i--) {
        printf("%d ", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c", seats[i - 1][j]);
        }
        printf("\n");
    }
}
// �D�禡?
int main() {
    char choice;
    char password[5];
    int attempts = 0;
    const char correctPassword[] = "2024";
 

	// Display Christmas tree    
	display_christmas_tree();
	
    // �K�X��J
    while (attempts < 3) {
        printf("��J4��Ʀr�K�X: ");
        scanf("%4s", password);
        if (strcmp(password, correctPassword) == 0) {
            printf("Welcome!\n");
            break;
        } else {
            printf("Incorrect password. Try again.\n");
            attempts++;
        }
    }

    if (attempts == 3) {
        printf("Too many incorrect attempts. Exiting...\n");
        return 0;
    }
	// Clear screen



    while (1) {    
        clearScreen();
        fflush(stdin);
        displayMenu();
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
    	generate_seats(seats);

	
        switch (choice) {
            case 'a':
            case 'A':	
                clearScreen();
                void display_seats();
                printf("Press any key to return to the main menu...");
                _getch();
                break;
            case 'b':
            case 'B':
                // �w�Ʈy�쪺
                clearScreen();
                printf("Arrange seats feature not implemented yet\n");
                printf("Press any key to return to the main menu...");
                _getch();
                break;
            case 'c':
            case 'C':
                // 
                clearScreen();
                printf("Choose seats yourself feature not implemented yet\n");
                printf("Press any key to return to the main menu...");
                _getch();
                break;
            case 'd':
            case 'D':
                clearScreen();
                printf("Continue? (y/n): ");
                char confirm = _getch();
                if (confirm == 'y' || confirm == 'Y') {
                    continue;
                } else if (confirm == 'n' || confirm == 'N') {
                    printf("Exiting...\n");
                    return 0;
                } else {
                    printf("Invalid input. Returning to the main menu...");
                    _getch();
                }
                break;
            default:
                printf("Invalid choice. Try again.\n");
                _getch();
        }
    }

    return 0;
}
