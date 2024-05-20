#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define ROWS 9
#define COLS 9
#define RESERVED_SEATS 10
char seats[ROWS][COLS];

// 清除屏函
void clearScreen() {
    system("CLS");
}

// 個人風格
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

// 顯示主選單
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
// 一開始的隨機座位功能
void initialize_seats(char seats[ROWS][COLS]) {
    int reserved = 0;
    int row, col;
    srand(time(NULL)); // 亂數產生

    // 所有座位初始為空位
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            seats[row][col] = '-';
        }
    }

    // 隨機預留10個座位 
    while (reserved < RESERVED_SEATS) {
        row = rand() % ROWS;
        col = rand() % COLS;
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            reserved++;
        }
    }
}

// 顯示座位表
void display_seats(char seats[ROWS][COLS]) {
    int row, col;
    printf("  ");
    for (col = 0; col < COLS; col++) {
        printf("%d", col + 1);
    }
    printf("\n");
    for (row = 0; row < ROWS; row++) {
        printf("%d ", ROWS - row);
        for (col = 0; col < COLS; col++) {
            printf("%c", seats[row][col]);
        }
        printf("\n");
    }
}

// 安排座位功能
void arrange_seats(char seats[ROWS][COLS]) {
    int num_seats, row, col, i;
    printf("\nHow many seats do you need (1-4)? ");
    scanf("%d", &num_seats);

    // Clear screen
    system("cls");

    if (num_seats < 1 || num_seats > 4) {
        printf("\nInvalid number of seats. Please enter a number between 1 and 4.\n");
        getch();
        return;
    }

    // 建議座位
    int suggested = 0;
    for (row = 0; row < ROWS && suggested == 0; row++) {
        for (col = 0; col < COLS; col++) {
            if (num_seats <= 3) {
                // 找連號座位
                if (col + num_seats <= COLS) {
                    int available = 1;
                    for (i = 0; i < num_seats; i++) {
                        if (seats[row][col + i] != '-') {
                            available = 0;
                            break;
                        }
                    }
                    if (available) {
                        for (i = 0; i < num_seats; i++) {
                            seats[row][col + i] = '@';
                        }
                        suggested = 1;
                        break;
                    }
                }
            } else if (num_seats == 4) {
                // 同一排或相鄰兩兩座位
                if (col + 4 <= COLS) {
                    int available = 1;
                    for (i = 0; i < 4; i++) {
                        if (seats[row][col + i] != '-') {
                            available = 0;
                            break;
                        }
                    }
                    if (available) {
                        for (i = 0; i < 4; i++) {
                            seats[row][col + i] = '@';
                        }
                        suggested = 1;
                        break;
                    }
                }
                if (row + 1 < ROWS && col + 2 <= COLS) {
                    int available = 1;
                    for (i = 0; i < 2; i++) {
                        if (seats[row][col + i] != '-' || seats[row + 1][col + i] != '-') {
                            available = 0;
                            break;
                        }
                    }
                    if (available) {
                        for (i = 0; i < 2; i++) {
                            seats[row][col + i] = '@';
                            seats[row + 1][col + i] = '@';
                        }
                        suggested = 1;
                        break;
                    }
                }
            }
        }
    }

    if (!suggested) {
        printf("\nNo available seats found for your request.\n");
        getch();
        return;
    }

    display_seats(seats);

    // 會座位安排可否
    printf("\nAre you satisfied with the arrangement? (y/n): ");
    char choice;
    fflush(stdin);
    choice = getch();
    if (choice == 'y' || choice == 'Y') {
        // 確認座位
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                if (seats[row][col] == '@') {
                    seats[row][col] = '*';
                }
            }
        }
    }

    // Clear screen
    system("cls");
}

// 自選座位
void choose_seats(char seats[ROWS][COLS]) {
    char input[5];
    int row, col;
    int valid = 0;

    while (!valid) {
        printf("\nEnter your seat choices (e.g., 1-2,2-9): ");
        scanf("%s", input);

        // 拆解輸入內容 
        if (sscanf(input, "%d-%d", &row, &col) != 2 || row < 1 || row > ROWS || col < 1 || col > COLS || seats[ROWS - row][col - 1] != '-') {
            printf("\nInvalid input or seat already taken. Please try again.\n");
        } else {
            valid = 1;
            seats[ROWS - row][col - 1] = '@';
        }
    }

    display_seats(seats);

    // 確認位置
    printf("\nPress any key to confirm your choices...");
    getch();
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (seats[row][col] == '@') {
                seats[row][col] = '*';
            }
        }
    }

    // Clear screen
    system("cls");
}

// 主函式  
int main() {
    char choice;
    char password[5];
    int attempts = 0;
    const char correctPassword[] = "2024";
 
	initialize_seats(seats); 
	// 個人風格    
	display_christmas_tree();
	
    // 密碼輸入
    while (attempts < 3) {
        printf("輸入4位數字密碼: ");
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




    while (1) {    
        clearScreen();
        fflush(stdin);
        displayMenu();
        printf("\nEnter your choice: ");
        choice=getch();


	
        switch (choice) {
            case 'a':
            case 'A':	
                clearScreen();    	
				display_seats(seats);
                printf("Press any key to return to the main menu...");
                getch();
                break;
            case 'b':
            case 'B':
                clearScreen();
                arrange_seats(seats);
				break;
            case 'c':
            case 'C': 
                clearScreen();
                choose_seats(seats);
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
                    getch();
                }
                break;
            default:
                printf("Invalid choice. Try again.\n");
                getch();
        }
    }

    return 0;
}
