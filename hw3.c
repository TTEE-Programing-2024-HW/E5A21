#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define ROWS 9
#define COLS 9
#define RESERVED_SEATS 10
char seats[ROWS][COLS];

// �M���̨�?
void clearScreen() {
    system("CLS");
}

// �ӤH����
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
// �@�}�l���H���y��\��
void initialize_seats(char seats[ROWS][COLS]) {
    int reserved = 0;
    int row, col;
    srand(time(NULL)); // �üƲ���

    // �Ҧ��y���l���Ŧ�
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            seats[row][col] = '-';
        }
    }

    // �H���w�d10�Ӯy�� 
    while (reserved < RESERVED_SEATS) {
        row = rand() % ROWS;
        col = rand() % COLS;
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            reserved++;
        }
    }
}

// ��ܮy���
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

// �D�禡
int main() {
    char choice;
    char password[5];
    int attempts = 0;
    const char correctPassword[] = "2024";
 
	initialize_seats(seats); 
	// �ӤH����    
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
                // �w�Ʈy�쪺
                clearScreen();
                printf("Arrange seats feature not implemented yet\n");
                printf("Press any key to return to the main menu...");
                getch();
                break;
            case 'c':
            case 'C':
                // 
                clearScreen();
                printf("Choose seats yourself feature not implemented yet\n");
                printf("Press any key to return to the main menu...");
                getch();
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
