#include<stdio.h>
#include<stdlib.h>


int main(){
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	system("pause");
	system("CLS");
	
	
	int i=0;
	int password;
		
	while (i < 3) {
		printf("�п�J4��ƱK�X(2025)\n");
		scanf("%d",&password);
			
    if (password == 2025) {
        printf("�K�X���T\n");
        break;  
    } 
	else{
           i++;
           printf("�K�X���~\n");
        }
    if (i == 3) {
        printf("���~���ƹF��W���A�{������\n\a");
        return 0;
	}
}
	system("CLS");	
		
	
	char a,A,b,B,c,C;
	printf("************************\n");
	printf("| a. �e�X�����T���� |   \n");
	printf("|                   |   \n");
	printf("| b. ��ܭ��k��     |   \n");
	printf("|                   |   \n");
	printf("| c. ����           |   \n");
	printf("************************\n");
	
	printf("�п��:\n");
	scanf("%c",&a,&A,&b,&B,&c,&C);
	system("pause");
	return 0;
	
	
}


