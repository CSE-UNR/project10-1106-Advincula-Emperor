
//Author: Emperor Advincula
//april 2025
//wordup Hard mode Vauge hint


#include <stdio.h>
void display(int col,char word[][col],char ans[],int r);
void covinsert(char guess[],int col,char word[][col],int r);//convert guess into lowercase and or upper case 
int tally(char guess[]);//count characters in currect guess
int check(int count,char guess[]);//evaluate guess
void prompt(int r,char guess[]);//ask player

#define wordf mystery.txt
#define ROW 5
#define COL 6
#define PLIMIT 20


int main(){


int r = 0, c = 0; //r = main funtion row guess count, c = main function col
char guess[PLIMIT];//current evaluated guess
char word[ROW][COL];//listed guess
int count = 0, a = 0, b = 0;// count = guess charcater count, a = issue, b holder
char ans[COL];
FILE* inFile;
	inFile = fopen("mystery.txt","r");

if (inFile == NULL){

	printf("Error Opening Mystery file\n");
	return 1;
} else {

fscanf(inFile, "%s", &ans);
printf("Grabbed word :%s\n",ans);



printf("answer %s", ans);

fclose(inFile);
}

while ( r != 6){

prompt(r,guess);


count = tally(guess);
a = check(count,guess);



if (a > 0){

	a = 0;
	} else {
	
		covinsert(guess, COL, word, r);
		display(COL, word, ans ,r);
		r++;
	}
	
printf("The answer is %s",ans);		
}


return 0;
}


void prompt(int r,char guess[]){

int a = r + 1;
printf(">> Enter Guess Number %d! :",a);
scanf("%s",guess);
printf("Guess number %d : %s\n",a, guess);

}


int tally(char guess[]){

int count = 0;
	while(guess[count] != '\0'){
	count++;
	}

return count;
}

int check(int count,char guess[]){
int i = 0,z = 0,a = 0;

if (count != 5){
printf("Your Guess has %d characters / 5 chracter limit\n", count);
a++;

} else {
for(i = 0; guess[i] != '\0'; i++){
	if (guess[i] < 'A' || guess[i] > 'Z' ){
		if (guess[i] < 'a' || guess[i] > 'z' ){
			z++;
			a++;
		}}}
if ( z > 0){
printf("you have %d invalid character(s), try again...\n", z);
return a;
}}}


void covinsert(char guess[],int col,char word[][col],int r){
	int i = 0;
	for(i = 0; i < 5; i++){
	if (guess[i] >= 65 && guess[i] <= 90){		// upper case to lower case
	word[r][i] = guess[i] + 32;
	} else {
	word[r][i] = guess[i];
}}
}




void display(int col,char word[][col],char ans[],int r){

int a = 0, c = 0, d = 0,h = 0;
char hold[col];
for(a = 0; a <= r; a++){
	for(c = 0; c < 5 ; c++){
	
	hold[c] = word[a][c];
	
	if (word[a][c] == ans[c]){ 
	 word[a][c] = word[a][c] - 32;
	 printf(" %c",word[a][c]);
	 
	 } else if (word[a][c] != ans[c]){
	 
	
	  printf(" %c",word[a][c]);
	  
	  }}
	  
	printf("\n");
	
	for (c = 0; c <= 5; c++){
		for (d = 0; d < 5; d++){
		if ( word[a][c] == ans[d] && word[a][c] != ans[d] - 32  && word[a][c] > 90 ){
		printf(" ^");
		} else {
		
		printf(" ");
		}
		}
		}
		
	printf("\n ");	
	}
	}
	



