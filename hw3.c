#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define ROWS 9
#define COLS 9

char seats[ROWS][COLS];

// 清除屏函?
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

// 顯示主選單?
void displayMenu() {
    printf("----------[BookingSystem]----------\n");
    printf("|  a. Available seats             |\n");
    printf("|  b. Arrange for you             |\n");
    printf("|  c. Choose by yourself          |\n");
    printf("|  d. Exit                        |\n");
    printf("-----------------------------------\n");
}

// 生成已預訂的座位
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

// 顯示座位表
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
// 主函式?
int main() {
    char choice;
    char password[5];
    int attempts = 0;
    const char correctPassword[] = "2024";

    // Display Christmas tree
    display_christmas_tree();
    
    // 密碼輸入
    while (attempts < 3) {
        printf("Enter 4-digit password: ");
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

    generate_seats(seats);

    while (1) {
        clearScreen();
        displayMenu();
        choice = _getch();

        switch (choice) {
            case 'a':
                clearScreen();
                void display_seats();
                printf("Press any key to return to the main menu...");
                _getch();
                break;
            case 'b':
                // 安排座位的
                clearScreen();
                printf("Arrange seats feature not implemented yet\n");
                printf("Press any key to return to the main menu...");
                _getch();
                break;
            case 'c':
                // 
                clearScreen();
                printf("Choose seats yourself feature not implemented yet\n");
                printf("Press any key to return to the main menu...");
                _getch();
                break;
            case 'd':
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
