#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>


void frontmenudrawing(void);
void answerintextfiles(int day);
void answereddiefunction(int i);
void optionsandpresentation(int choice);

void main(void)
{
	char announce[4][250] = {
		"Eddie has gone for the day.\nif you need to see your memos, Please put a command.\n",
		"Good morning, sir!\nEddie your assistant here.\nHow's your day going?\nif you need some jokes, I can tell you that.\nor just you can put the word like 'memo' etc.\n",
		"Good afternoon, sir. \nhow's your work going today?\nhere is some health tips for you.\nthis can make you feel better.\nalso I can choose a rock song for you.\nor just say the word 'memo' plz.\n",
		"Good evening,sir.\nthanks for your trouble today.\ntake it easy and see you.\n"
		};
	char keyword1[7][4][10] = {
		{"good", "positive", "happy", "excited"},
		{"sad", "terrible", "angry", "tired"},
		{"WTF","fuck","slap", "STFU"},
		{"joke", "jokes", "funny", "hilarious"},
		{"tip", "tips", "health", "healing"},
		{"music", "rock", "recommend", "song"},
		{"memo", "plans", "memos", "events"}
	};
	char keyword2[2][4][10] = {
		{"memo", "memos", "1", "one"},
		{"event", "events", "2", "two"},
	};

	int color[4] = {13, 10, 11, 14};
	
	char awr[50]={};
	int check=0,check2=0;

	char tempy[50] = {};
	int date[3]={0,0,0};
	int reckon=0, m=0;

	struct tm *t;
	time_t timer; //시간 측정

	timer = time(NULL);  // 현재 시각을 초 단위로 얻기
	t = localtime(&timer);  // 초 단위의 시간을 분리하여 구조체에 넣기

	//**** Events
	FILE * f8;
	f8 = fopen("Events.txt", "r");
	
	printf("*****TODAY'S EVENTS*****");
	
	while(fscanf(f8, "%s", &tempy) != EOF){
			if(((t->tm_year+1900) == date[0]) && ((t->tm_mon+1) == date[1]) && (t->tm_mday == date[2])) {
					printf("%s ", tempy); }
		if(strcmp(tempy,"*") == 0){
			for(m=0; m<3;m++){
				fscanf(f8, "%d", &date[m]);
			}
			if(((t->tm_year+1900) == date[0]) && ((t->tm_mon+1) == date[1]) && (t->tm_mday == date[2]))
				printf("\n", ++reckon);
	}}
	if(reckon == 0)
		printf("\n        Nothing\n");
	printf("************************\n\n");
	


	//front
	for(int k=0; k<=4; k++){
		if(t->tm_hour < ((k+1)*6)){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[k]); 
			Sleep(500);
			printf("Eddie : ");
			printf("%s",announce[k]);
			break;
		}
	}
	while(check2==0){			// 이건 처음 대화할 때 
		check=0;
		printf("You   : ");
		while(1){
			scanf("%s", &awr);
			if(strcmp(awr,"*") == 0)
				break;
			for(int i=0; i<7; i++){
				for(int j=0; j<4; j++){
					if(strcmp(awr, keyword1[i][j])==0){
						Sleep(1000);
						check++;
						if(i>=0 && i<=2)
							answereddiefunction(i);
						else if(i>=3 && i<=5)
							answerintextfiles(i);
						else if(i == 6)
							check2++;
						
						break;
		}}}}
		if(check == 0){
			Sleep(1000);
			printf("Eddie : Ok. I'll practice from now. Cheer up! :)\n"); }
	}

	while(1){		// 이건 메뉴판 띄우고 나서
		check=0;
		frontmenudrawing();
		printf("You   : ");
		while(check == 0){
			scanf("%s", &awr);
			if(strcmp(awr,"*") == 0)
				break;
			for(int i=0; i<2; i++){
				for(int j=0; j<4; j++){
					if(strcmp(awr, keyword2[i][j])==0){
						Sleep(1000);
						check++;
						
						optionsandpresentation(i);
						
						break;
		}}}}

		if(check == 0){
			Sleep(1000);
			printf("Eddie : I can't interpret what you said. :(\n"); }
	}


	// 끝
	
}
void frontmenudrawing(void)
{	
	printf("Eddie : Ok. Let's look at the front menu.\n");
	Sleep(2000);
	
	system("cls");
	printf("┌──────────┐\n");
	printf("│     1. memo        │\n");
	printf("│ 2. monthly events  │\n");
	printf("└──────────┘\n\n\n");
	

}
void answerintextfiles(int day)
{
	int random;
	int count=0;
	int total;
	char temp[50]={};

	srand(time(NULL));

	if(day == 3)
	{
		FILE *f1;
		f1 = fopen("Jokes.txt", "r");


		fscanf(f1, "%d", &total);
		random = (rand()%total)+1;

		for(int i=0; i<random; ){
			fscanf(f1, "%s", &temp);
			if(strcmp(temp,"*") == 0)	
				i++;
		}

		strcpy(temp, "");
		printf("Eddie : ");
		while(1){
			fscanf(f1, "%s", &temp);
			if(strcmp(temp,"*") == 0)
				break;
			printf("%s ", temp);
		}
		printf("\n");

		fclose(f1);
	}
	else if(day == 4)
	{
		FILE *f2;
		f2 = fopen("Health tips.txt", "r");

		fscanf(f2, "%d", &total);
		random = (rand()%total)+1;

		for(int i=0; i<random; ){
			fscanf(f2, "%s", &temp);
			if(strcmp(temp,"*") == 0)	
				i++;
		}

		strcpy(temp, "");
		printf("Eddie : ");
		while(1){
			fscanf(f2, "%s", &temp);
			if(strcmp(temp,"*") == 0)
				break;
			printf("%s ", temp);
		}
		printf("\n");

		fclose(f2);
	}

	else if(day == 5)
	{
		FILE *f3;
		f3 = fopen("Alternative Songs.txt", "r");

		fscanf(f3, "%d", &total);
		random = (rand()%total)+1;

		strcpy(temp, "");
		printf("Eddie : ");
		printf("On \"");	//차트 출처 출력
		while(1){
			fscanf(f3, "%s", &temp);
			if(strcmp(temp,"*") == 0)	
				break;
			printf("%s ", temp);
		}
		printf("\",\n");

		for(int i=1; i<random; ){	//음악 타이틀 몇개 랜덤하게 넘기고
			fscanf(f3, "%s", &temp);
			if(strcmp(temp,"*") == 0)	
				i++;
		}
		
		strcpy(temp, "");
		printf("The song title is \"");	// 음악 이름
		while(1){
			fscanf(f3, "%s", &temp);
			if(strcmp(temp,"@") == 0)
				break;
			printf("%s ", temp);
		}
		
		strcpy(temp, "");
		printf("\" and the artist is \"");	// 아티스트 이름
		while(1){
			fscanf(f3, "%s", &temp);
			if(strcmp(temp,"*") == 0)
				break;
			printf("%s ", temp);
		}
		printf("\". I hope you like it.\n");

		fclose(f3);
	}
	
}
void answereddiefunction(int i)
{
	char answereddie[3][3][200] = {
		{"Me too. I feel pretty good.", "Fine. :)", "Let's make the day more cheerful!"},
		{"I'm sorry you feel that way.", "You must feel stressed out now.", "That's too bad."},
		{"What? I feel so embarrassed.", "Don't point at me!", "I'm so confused about what you said just now. \nCould you tell me polite?"},
	};

	srand(time(NULL));

	printf("Eddie : %s\n", answereddie[i][rand()%3]);
}

void optionsandpresentation(int choice)
{
	char keyword3[2][3][10] = {
		{"1", "write", "one"},
		{"2", "read", "two"}
	};

	char temp[100]={};
	int op = 0;
	int value=1;

	char awr[50]={};
	int check=0;

	system("cls");
	printf("┌──────────┐\n");
	printf("│      1. write      │\n");
	printf("│      2. read       │\n");
	printf("└──────────┘\n\n\n");

	printf("You   : ");

	fflush(stdin);
	while(1){
		scanf("%s", &awr);
		if(strcmp(awr,"*") == 0)
			break;
		for(int i=0; i<2; i++){
			for(int j=0; j<3; j++){
				if(strcmp(awr, keyword3[i][j])==0){
					Sleep(1000);
					check++;
					
					op = i+1;		// write or read
					
					break;
	}}}}

	if(choice == 0){
		if(op == 1){
			system("cls");
			printf("Eddie : How much important is this memo? 1 or 2 or 3?\nPlease enter a number only\n");
			Sleep(500);
			printf("Value : ");
			scanf("%d", &value);
			Sleep(1000);
			printf("Please write down your thoughts : \n");
	
			fflush(stdin);

			FILE * f4;
			f4 = fopen("Note.txt", "a");

			fprintf(f4, "%d\n", value);	// 중요도 파일에 입력
			while(1){
				scanf("%s", &temp);
				if(strcmp(temp,"*") == 0)	
					break;
				fprintf(f4, "%s ", temp);
			}
			fprintf(f4, "\n*\n");
	
			fclose(f4);
		}
		else if(op == 2){
			system("cls");
			fflush(stdin);

			FILE * f5;
			f5 = fopen("Note.txt", "r");

			printf("This is your memos : ");
			while(fscanf(f5, "%s", &temp) != EOF){
				printf("%s ", temp);
				if(strcmp(temp,"*") == 0){
					fscanf(f5, "%s", temp);
					printf("\n\n");
					printf("Value : %s/3\n", temp);
					printf("Memo  : ");
				}
			}
			system("pause");

			fflush(stdin);
			fclose(f5);
		}
	}
	else if(choice == 1){
		int year, month, day;

		if(op == 1){
			system("cls");
			printf("Eddie : plz write the date down.\n\"example : 2016 2 22\"\n");
			Sleep(500);
			printf("date  : ");
			scanf("%d %d %d", &year, &month, &day);
			Sleep(1000);
			printf("Please write down your plan : \n");

			fflush(stdin);

			FILE * f6;
			f6 = fopen("Events.txt", "a");

			fprintf(f6, "%d %d %d\n", year, month, day);	
			while(1){
				scanf("%s", &temp);
				if(strcmp(temp,"*") == 0)	
					break;
				fprintf(f6, "%s ", temp);
			}
			fprintf(f6, "\n*\n");
	
			fclose(f6);
		}
		else if(op == 2){
			system("cls");
			fflush(stdin);

			FILE * f7;
			f7 = fopen("Events.txt", "r");

			printf("This is your monthly Events : ");
			while(fscanf(f7, "%s", &temp) != EOF){
				printf("%s ", temp);
				if(strcmp(temp,"*") == 0){
					printf("\n\n");
					printf("date   : ");
					for(int m=0; m<3;m ++){
						fscanf(f7, "%s", temp);
						printf("%s ", temp);
					}
					printf("\nEvent  : ");
				}
			}
			system("pause");

			fflush(stdin);
			fclose(f7);
		}

	}

}
