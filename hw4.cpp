#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 10

// 學生結構
typedef struct 
{
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

// 清除畫面
void clear_screen() 
{
    system("CLS"); 
}

// 暫停
void pause() 
{
    printf("請按 Enter 鍵繼續...");
    getchar();
}

// 自訂字串比較函式
int string_compare(const char *a, const char *b) 
{
    while (*a && *b) 
	{
        if (*a != *b)
            return 0;
        a++;
        b++;
    }
    return (*a == '\0' && *b == '\0');
}

// 登入
int login() 
{
    char input[10];
    int attempts = 0;

    while (attempts < 3) 
	{
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
        getchar();

        if (string_compare(input, "2025")) 
		{
            printf("密碼正確，歡迎使用本系統！\n");
            pause();
            return 1;
        } else 
		{
            printf("密碼錯誤！\n");
            attempts++;
        }
    }

    printf("錯誤三次，系統結束。\n");
    return 0;
}

// 主選單
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

    if (student_count < 5 || student_count > 10) 
	{
        printf("人數錯誤，返回主選單。\n");
        pause();
        return;
    }

    for (int i = 0; i < student_count; i++) 
	{
        printf("\n輸入第 %d 位學生姓名（不含空格）：", i + 1);
        scanf("%s", students[i].name);

        printf("輸入學號（6位數）：");
        scanf("%d", &students[i].id);
        if (students[i].id < 100000 || students[i].id > 999999) 
		{
            printf("學號錯誤！重新輸入這位學生。\n");
            i--;
            getchar();
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
            students[i].english < 0 || students[i].english > 100) 
			{
            printf("成績錯誤！重新輸入這位學生。\n");
            i--;
            getchar();
            continue;
            }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
        getchar();
    }

    printf("資料輸入完畢！\n");
    pause();
}

// 選項 b：顯示學生資料
void display_students() 
{
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

// 選項 c：搜尋學生
void search_student() 
{
    clear_screen();
    char search_name[50];
    int found = 0;

    printf("請輸入要搜尋的學生姓名：");
    scanf("%s", search_name);

    for (int i = 0; i < student_count; i++) 
	{
        if (string_compare(search_name, students[i].name)) 
		{
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

// 選項 d：排序與排名
void grade_ranking() 
{
    clear_screen();
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

    printf("成績排名如下：\n");
    printf("姓名\t學號\t平均\n");
    for (int i = 0; i < student_count; i++) 
	{
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
    }
    pause();
}

// 選項 e：確認離開
int exit_system() 
{
    char choice;
    while (1) {
        printf("確定離開？(y/n): ");
        scanf(" %c", &choice);
        getchar();
        if (choice == 'y' || choice == 'Y') return 1;
        if (choice == 'n' || choice == 'N') return 0;
    }
}

// 主程式
int main() 
{
    if (!login()) return 0;

    while (1) 
	{
        show_menu();
        char option;
        scanf(" %c", &option);
        getchar();

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
