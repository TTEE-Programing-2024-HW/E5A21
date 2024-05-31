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

// 清除螢幕的函式
void clearScreen() {
    system("cls");
}

// 繪製聖誕樹的函式
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

// 登錄函式
int login() 
{
    int attempts = 0;
    char inputPassword[5];

    while (attempts < 3) {
        clearScreen();
        drawChristmasTree();
        printf("請輸入4個數字的密碼(2024)：");
        scanf("%4s", inputPassword);

        if (strcmp(inputPassword, PASSWORD) == 0) {
            printf("密碼正確！歡迎使用。\n");
            return 1;
        } else {
            printf("密碼錯誤！\n");
            attempts++;
        }
    }
    printf("連續三次密碼錯誤，程式結束。\n");
    return 0;
}

// 顯示主選單的函式
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

// 檢查成績是否在有效範圍內的函式
int isValidGrade(int grade) {
    return grade >= 0 && grade <= 100;
}

// 輸入學生成績的函式
void enterGrades() 
{
    int n;
    clearScreen();
    printf("請輸入學生人數 (5~10)：");
    if (scanf("%d", &n) != 1 || n < 5 || n > 10) {
        printf("輸入人數錯誤，請重新輸入。\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("請輸入第%d位學生的姓名：", i + 1);
        scanf("%s", students[student_count].name);
        printf("請輸入學號（6位整數）：");
        if (scanf("%d", &students[student_count].id) != 1 || students[student_count].id < 100000 || students[student_count].id > 999999) {
            printf("學號輸入錯誤，請重新輸入。\n");
            return;
        }
        printf("請輸入數學成績（0~100）：");
        if (scanf("%d", &students[student_count].math) != 1 || !isValidGrade(students[student_count].math)) {
            printf("數學成績輸入錯誤，請重新輸入。\n");
            return;
        }
        printf("請輸入物理成績（0~100）：");
        if (scanf("%d", &students[student_count].physics) != 1 || !isValidGrade(students[student_count].physics)) {
            printf("物理成績輸入錯誤，請重新輸入。\n");
            return;
        }
        printf("請輸入英文成績（0~100）：");
        if (scanf("%d", &students[student_count].english) != 1 || !isValidGrade(students[student_count].english)) {
            printf("英文成績輸入錯誤，請重新輸入。\n");
            return;
        }

        students[student_count].average = (students[student_count].math + students[student_count].physics + students[student_count].english) / 3.0;
        student_count++;
    }

    clearScreen();
}

// 顯示學生成績的函式
void displayGrades() 
{
    clearScreen();
    printf("學生成績如下：\n");
    for (int i = 0; i < student_count; i++) {
        printf("姓名：%s\n", students[i].name);
        printf("學號：%d\n", students[i].id);
        printf("數學成績：%d\n", students[i].math);
        printf("物理成績：%d\n", students[i].physics);
        printf("英文成績：%d\n", students[i].english);
        printf("平均成績：%.1f\n", students[i].average);
        printf("\n");
    }
    printf("按任意鍵回到主選單...");
    getch();
    clearScreen();
}

// 主函式
int main() 
{
    char choice;

    if (!login()) {
        return 0;
    }
	clearScreen();
    while (1) {
        showMenu();
        printf("請選擇操作：");
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
                printf("確定離開？ (y/n)：");
                char confirm = getch();
                if (confirm == 'y' || confirm == 'Y') {
                    return 0;
                } else {
                    clearScreen();
                }
                break;
            default:
                printf("無效的選擇，請重新選擇。\n");
                break;
        }
    }

    return 0;
}

