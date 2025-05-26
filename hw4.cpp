#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10 // 最多學生人數

typedef struct 
{
    char name[50]; // 姓名 
    int id; // 學號（6位數） 
    int math; // 數學成績  
    int physics; // 物理成績 
    int english;  // 英文成績 
    float average; // 平均成績 
} Student;

Student students[MAX_STUDENTS]; // 學生陣列 
int student_count = 0; // 實際學生人數 

void clear_screen() 
{
    system("cls"); 
}
// 暫停畫面，等待使用者按下 Enter
void pause() 
{
    printf("請按 Enter 鍵繼續...");
    getchar();
}
// 登入驗證函式
int login() {
    char input[10]; // 存放輸入密碼
    int attempts = 0;

    while (attempts < 3) 
	{
    	clear_screen();
    	// 顯示個人風格畫面（20 行）
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
        scanf("%s", input); // 輸入密碼 
        getchar(); // 吸收 Enter

        if (strcmp(input, "2025") == 0) 
		{
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
// 顯示主選單
void show_menu() 
{
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
// 選項 a：輸入學生資料
void input_students() 
{
    clear_screen();
    printf("請輸入學生人數（5~10）：");
    scanf("%d", &student_count);
    getchar();
// 人數檢查
    if (student_count < 5 || student_count > 10) 
	{
        printf("人數錯誤，返回主選單。\n");
        pause();
        return;
    }

    for (int i = 0; i < student_count; i++) 
	{
        printf("\n輸入第 %d 位學生姓名：", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // 移除換行
// 輸入學號
        printf("輸入學號（6位數）：");
        scanf("%d", &students[i].id);

        if (students[i].id < 100000 || students[i].id > 999999) 
		{
            printf("學號錯誤！重新輸入這位學生。\n");
            i--;
            getchar(); // 清掉 Enter
            continue;
        }
// 輸入各科成績
        printf("輸入數學成績（0~100）：");
        scanf("%d", &students[i].math);

        printf("輸入物理成績（0~100）：");
        scanf("%d", &students[i].physics);

        printf("輸入英文成績（0~100）：");
        scanf("%d", &students[i].english);
// 成績檢查
        if (students[i].math < 0 || students[i].math > 100 ||
            students[i].physics < 0 || students[i].physics > 100 ||
            students[i].english < 0 || students[i].english > 100) 
			{
            printf("成績錯誤！重新輸入這位學生。\n");
            i--;
            getchar(); // 清掉 Enter
            continue;
            }
// 計算平均
    students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    getchar(); // 清掉 Enter
    }

        printf("資料輸入完畢！\n");
        pause();
}
// 選項 b：顯示所有學生資料
void display_students() 
{
    clear_screen();
    printf("姓名\t學號\t數學\t物理\t英文\t平均\n");
    for (int i = 0; i < student_count; i++) 
	{
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
// 選項 c：搜尋學生資料
void search_student() 
{
    clear_screen();
    char search_name[50];
    int found = 0;

    printf("請輸入要搜尋的學生姓名：");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = 0;

    for (int i = 0; i < student_count; i++) 
	{
        if (strcmp(search_name, students[i].name) == 0) 
		{   // 找到後顯示資料 
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

    if (!found) 
	{
        printf("查無此學生資料。\n");
    }
    pause();
}
// 選項 d：依平均排序並顯示排名
void grade_ranking() 
{
    clear_screen();
    // 氣泡排序
    for (int i = 0; i < student_count - 1; i++) 
	{
        for (int j = i + 1; j < student_count; j++) 
		{
            if (students[i].average < students[j].average) 
			{
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
// 顯示排序後成績
    printf("成績排名如下：\n");
    printf("姓名\t學號\t平均\n");
    for (int i = 0; i < student_count; i++) 
	{
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
    }
    pause();
}
// 選項 e：離開系統前確認
int exit_system() 
{
    char choice;
    while (1) 
	{
        printf("確定離開？(y/n): ");
        scanf(" %c", &choice);
        getchar(); // 吸收 Enter
        if (choice == 'y' || choice == 'Y') return 1;
        if (choice == 'n' || choice == 'N') return 0;
    }
}
// 主程式進入點
int main() 
{
    if (!login()) return 0;  // 若登入失敗則直接結束程式 
 // 進入主選單迴圈
    while (1) 
	{
        show_menu();  // 顯示選單
        char option;
        scanf(" %c", &option);
        getchar(); // 吸收 Enter
// 執行選項功能
        switch (option) 
		{
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

