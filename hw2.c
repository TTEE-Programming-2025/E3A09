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
		printf("請輸入4位數密碼(2025)\n");
		scanf("%d",&password);
			
    if (password == 2025) {
        printf("密碼正確\n");
        break;  
    } 
	else{
           i++;
           printf("密碼錯誤\n");
        }
    if (i == 3) {
        printf("錯誤次數達到上限，程式結束\n\a");
        return 0;
	}
}
	system("CLS");	
		
	
	char a,A,b,B,c,C;
	printf("************************\n");
	printf("| a. 畫出直角三角形 |   \n");
	printf("|                   |   \n");
	printf("| b. 顯示乘法表     |   \n");
	printf("|                   |   \n");
	printf("| c. 結束           |   \n");
	printf("************************\n");
	
	printf("請選擇:\n");
	scanf("%c",&a,&A,&b,&B,&c,&C);
	system("pause");
	return 0;
	
	
}


