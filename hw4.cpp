#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10

typedef struct {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void clear_screen() {
    system("cls"); 
}

void pause() {
    printf("請按 Enter 鍵繼續...");
    getchar();
}

int login() {
    char input[10];
    int attempts = 0;

    while (attempts < 3) {
    	clear_screen();
        printf("                      . . . .                 \n");
        printf("                      ,`,`,`,`,               \n");
        printf(". . . .               `\`\`\`\;               \n");
        printf("`\`\`\`\`,            ~|;!;!;\!               \n");
        printf(" ~\;\;\;\|\          (--,!!!~`!       .       \n");
        printf("(--,\\\===~\         (--,|||~`!     ./        \n");
        printf(" (--,\\\===~\         `,-,~,=,:. _,//         \n");
        printf("  (--,\\\==~`\        ~-=~-.---|\;/J,         \n");
        printf("   (--,\\\((```==.    ~'`~/       a |         \n");
        printf("     (-,.\\('('(`\\.  ~'=~|     \_.  \        \n");
        printf("        (,--(,(,(,'\\. ~'=|       \\_;>       \n");
        printf("          (,-( ,(,(,;\\ ~=/        \          \n");
        printf("          (,-/ (.(.(,;\\,/          )         \n");
        printf("           (,--/,;,;,;,\\         ./------.   \n");
        printf("             (==,-;-'`;'         /_,----`. \  \n");
        printf("     ,.--_,__.-'                    `--.  ` \ \n");
        printf("    (='~-_,--/        ,       ,!,___--. \  \_)\n");
        printf("   (-/~(     |         \   ,_-         | ) /_|\n");
        printf("   (~/((\    )\._,      |-'         _,/ /     \n");
        printf("    \\))))  /   ./~.    |           \_\;      \n");
        printf(" ,__/////  /   /    )  /                      \n");
        printf("  '===~'   |  |    (, <.                      \n");
        printf("           / /       \. \                     \n");
        printf("         _/ /          \_\                    \n");
        printf("        /_!/            >_\                   \n");
        printf("請輸入 4 位數密碼（預設為 2025）：");
        scanf("%s", input);
        getchar(); // 吸收 Enter

        if (strcmp(input, "2025") == 0) {
            printf("密碼正確，歡迎使用本系統！\n");
            pause();
            return 1;
        } else {
            printf("密碼錯誤！\n");
            attempts++;
        }
    }

    printf("錯誤三次，系統結束。\n");
    return 0;
}

void show_menu() {
    clear_screen();
    printf("------------[Grade System]----------\n");
    printf("| a. Enter student grades          |\n");
    printf("| b. Display student grades        |\n");
    printf("| c. Search for student grades     |\n");
    printf("| d. Grade ranking                 |\n");
    printf("| e. Exit system                   |\n");
    printf("------------------------------------\n");
    printf("請輸入選項：");
}

void input_students() {
    clear_screen();
    printf("請輸入學生人數（5~10）：");
    scanf("%d", &student_count);
    getchar();

    if (student_count < 5 || student_count > 10) {
        printf("人數錯誤，返回主選單。\n");
        pause();
        return;
    }

    for (int i = 0; i < student_count; i++) {
        printf("\n輸入第 %d 位學生姓名：", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // 移除換行

        printf("輸入學號（6位數）：");
        scanf("%d", &students[i].id);

        if (students[i].id < 100000 || students[i].id > 999999) {
            printf("學號錯誤！重新輸入這位學生。\n");
            i--;
            getchar(); // 清掉 Enter
            continue;
        }

        printf("輸入數學成績（0~100）：");
        scanf("%d", &students[i].math);

        printf("輸入物理成績（0~100）：");
        scanf("%d", &students[i].physics);

        printf("輸入英文成績（0~100）：");
        scanf("%d", &students[i].english);

        if (students[i].math < 0 || students[i].math > 100 ||
            students[i].physics < 0 || students[i].physics > 100 ||
            students[i].english < 0 || students[i].english > 100) {
            printf("成績錯誤！重新輸入這位學生。\n");
            i--;
            getchar(); // 清掉 Enter
            continue;
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
        getchar(); // 清掉 Enter
    }

    printf("資料輸入完畢！\n");
    pause();
}

void display_students() {
    clear_screen();
    printf("姓名\t學號\t數學\t物理\t英文\t平均\n");
    for (int i = 0; i < student_count; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",
            students[i].name,
            students[i].id,
            students[i].math,
            students[i].physics,
            students[i].english,
            students[i].average);
    }
    pause();
}

void search_student() {
    clear_screen();
    char search_name[50];
    int found = 0;

    printf("請輸入要搜尋的學生姓名：");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = 0;

    for (int i = 0; i < student_count; i++) {
        if (strcmp(search_name, students[i].name) == 0) {
            printf("找到學生資料：\n");
            printf("姓名：%s\n學號：%d\n數學：%d\n物理：%d\n英文：%d\n平均：%.1f\n",
                students[i].name,
                students[i].id,
                students[i].math,
                students[i].physics,
                students[i].english,
                students[i].average);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("查無此學生資料。\n");
    }
    pause();
}

void grade_ranking() {
    clear_screen();
    // 氣泡排序
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[i].average < students[j].average) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("成績排名如下：\n");
    printf("姓名\t學號\t平均\n");
    for (int i = 0; i < student_count; i++) {
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
    }
    pause();
}

int exit_system() {
    char choice;
    while (1) {
        printf("確定離開？(y/n): ");
        scanf(" %c", &choice);
        getchar(); // 吸收 Enter
        if (choice == 'y' || choice == 'Y') return 1;
        if (choice == 'n' || choice == 'N') return 0;
    }
}

int main() {
    if (!login()) return 0;

    while (1) {
        show_menu();
        char option;
        scanf(" %c", &option);
        getchar(); // 吸收 Enter

        switch (option) {
            case 'a':
            case 'A': input_students(); break;
            case 'b':
            case 'B': display_students(); break;
            case 'c':
            case 'C': search_student(); break;
            case 'd':
            case 'D': grade_ranking(); break;
            case 'e':
            case 'E': if (exit_system()) return 0; break;
            default:
                printf("選項錯誤！請重新輸入。\n");
                pause();
        }
    }

    return 0;
}

