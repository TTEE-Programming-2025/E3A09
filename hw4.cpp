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
    printf("�Ы� Enter ���~��...");
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
        printf("�п�J 4 ��ƱK�X�]�w�]�� 2025�^�G");
        scanf("%s", input);
        getchar(); // �l�� Enter

        if (strcmp(input, "2025") == 0) {
            printf("�K�X���T�A�w��ϥΥ��t�ΡI\n");
            pause();
            return 1;
        } else {
            printf("�K�X���~�I\n");
            attempts++;
        }
    }

    printf("���~�T���A�t�ε����C\n");
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
    printf("�п�J�ﶵ�G");
}

void input_students() {
    clear_screen();
    printf("�п�J�ǥͤH�ơ]5~10�^�G");
    scanf("%d", &student_count);
    getchar();

    if (student_count < 5 || student_count > 10) {
        printf("�H�ƿ��~�A��^�D���C\n");
        pause();
        return;
    }

    for (int i = 0; i < student_count; i++) {
        printf("\n��J�� %d ��ǥͩm�W�G", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // ��������

        printf("��J�Ǹ��]6��ơ^�G");
        scanf("%d", &students[i].id);

        if (students[i].id < 100000 || students[i].id > 999999) {
            printf("�Ǹ����~�I���s��J�o��ǥ͡C\n");
            i--;
            getchar(); // �M�� Enter
            continue;
        }

        printf("��J�ƾǦ��Z�]0~100�^�G");
        scanf("%d", &students[i].math);

        printf("��J���z���Z�]0~100�^�G");
        scanf("%d", &students[i].physics);

        printf("��J�^�妨�Z�]0~100�^�G");
        scanf("%d", &students[i].english);

        if (students[i].math < 0 || students[i].math > 100 ||
            students[i].physics < 0 || students[i].physics > 100 ||
            students[i].english < 0 || students[i].english > 100) {
            printf("���Z���~�I���s��J�o��ǥ͡C\n");
            i--;
            getchar(); // �M�� Enter
            continue;
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
        getchar(); // �M�� Enter
    }

    printf("��ƿ�J�����I\n");
    pause();
}

void display_students() {
    clear_screen();
    printf("�m�W\t�Ǹ�\t�ƾ�\t���z\t�^��\t����\n");
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

    printf("�п�J�n�j�M���ǥͩm�W�G");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = 0;

    for (int i = 0; i < student_count; i++) {
        if (strcmp(search_name, students[i].name) == 0) {
            printf("���ǥ͸�ơG\n");
            printf("�m�W�G%s\n�Ǹ��G%d\n�ƾǡG%d\n���z�G%d\n�^��G%d\n�����G%.1f\n",
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
        printf("�d�L���ǥ͸�ơC\n");
    }
    pause();
}

void grade_ranking() {
    clear_screen();
    // ��w�Ƨ�
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[i].average < students[j].average) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("���Z�ƦW�p�U�G\n");
    printf("�m�W\t�Ǹ�\t����\n");
    for (int i = 0; i < student_count; i++) {
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
    }
    pause();
}

int exit_system() {
    char choice;
    while (1) {
        printf("�T�w���}�H(y/n): ");
        scanf(" %c", &choice);
        getchar(); // �l�� Enter
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
        getchar(); // �l�� Enter

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
                printf("�ﶵ���~�I�Э��s��J�C\n");
                pause();
        }
    }

    return 0;
}

