#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define PASSWORD "2024"

typedef struct {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    double average;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

// �M���ù����禡
void clearScreen() {
    system("cls");
}

// ø�s�t�Ͼ𪺨禡
void drawChristmasTree() 
{
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

// �n���禡
int login() 
{
    int attempts = 0;
    char inputPassword[5];

    while (attempts < 3) {
        clearScreen();
        drawChristmasTree();
        printf("�п�J4�ӼƦr���K�X(2024)�G");
        scanf("%4s", inputPassword);

        if (strcmp(inputPassword, PASSWORD) == 0) {
            printf("�K�X���T�I�w��ϥΡC\n");
            return 1;
        } else {
            printf("�K�X���~�I\n");
            attempts++;
        }
    }
    printf("�s��T���K�X���~�A�{�������C\n");
    return 0;
}

// ��ܥD��檺�禡
void showMenu() 
{
    printf("------------[Grade System]----------\n");
    printf("|  a. Enter student grades         |\n");
    printf("|  b. Display student grades       |\n");
    printf("|  c. Search for student grades    |\n");
    printf("|  d. Grade ranking                |\n");
    printf("|  e. Exit system                  |\n");
    printf("------------------------------------\n");
}

// �ˬd���Z�O�_�b���Ľd�򤺪��禡
int isValidGrade(int grade) {
    return grade >= 0 && grade <= 100;
}

// ��J�ǥͦ��Z���禡
void enterGrades() 
{
    int n;
    clearScreen();
    printf("�п�J�ǥͤH�� (5~10)�G");
    if (scanf("%d", &n) != 1 || n < 5 || n > 10) {
        printf("��J�H�ƿ��~�A�Э��s��J�C\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("�п�J��%d��ǥͪ��m�W�G", i + 1);
        scanf("%s", students[student_count].name);
        printf("�п�J�Ǹ��]6���ơ^�G");
        if (scanf("%d", &students[student_count].id) != 1 || students[student_count].id < 100000 || students[student_count].id > 999999) {
            printf("�Ǹ���J���~�A�Э��s��J�C\n");
            return;
        }
        printf("�п�J�ƾǦ��Z�]0~100�^�G");
        if (scanf("%d", &students[student_count].math) != 1 || !isValidGrade(students[student_count].math)) {
            printf("�ƾǦ��Z��J���~�A�Э��s��J�C\n");
            return;
        }
        printf("�п�J���z���Z�]0~100�^�G");
        if (scanf("%d", &students[student_count].physics) != 1 || !isValidGrade(students[student_count].physics)) {
            printf("���z���Z��J���~�A�Э��s��J�C\n");
            return;
        }
        printf("�п�J�^�妨�Z�]0~100�^�G");
        if (scanf("%d", &students[student_count].english) != 1 || !isValidGrade(students[student_count].english)) {
            printf("�^�妨�Z��J���~�A�Э��s��J�C\n");
            return;
        }

        students[student_count].average = (students[student_count].math + students[student_count].physics + students[student_count].english) / 3.0;
        student_count++;
    }

    clearScreen();
}

// ��ܾǥͦ��Z���禡
void displayGrades() 
{
    clearScreen();
    printf("�ǥͦ��Z�p�U�G\n");
    for (int i = 0; i < student_count; i++) {
        printf("�m�W�G%s\n", students[i].name);
        printf("�Ǹ��G%d\n", students[i].id);
        printf("�ƾǦ��Z�G%d\n", students[i].math);
        printf("���z���Z�G%d\n", students[i].physics);
        printf("�^�妨�Z�G%d\n", students[i].english);
        printf("�������Z�G%.1f\n", students[i].average);
        printf("\n");
    }
    printf("�����N��^��D���...");
    getch();
    clearScreen();
}

// �D�禡
int main() 
{
    char choice;

    if (!login()) {
        return 0;
    }
	clearScreen();
    while (1) {
        showMenu();
        printf("�п�ܾާ@�G");
        choice = getch();
        printf("%c\n", choice);

        switch (choice) {
            case 'a':
                enterGrades();
                break;
            case 'b':
            	displayGrades();
                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e':
                printf("�T�w���}�H (y/n)�G");
                char confirm = getch();
                if (confirm == 'y' || confirm == 'Y') {
                    return 0;
                } else {
                    clearScreen();
                }
                break;
            default:
                printf("�L�Ī���ܡA�Э��s��ܡC\n");
                break;
        }
    }

    return 0;
}

