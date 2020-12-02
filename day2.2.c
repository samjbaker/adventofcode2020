#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define FLEN 1000
#define STRLEN 200

void test(void);

int main(void)
{
   FILE *myfile = fopen("input2.txt", "r");
   char text[FLEN][STRLEN], text2[FLEN][STRLEN], text3[FLEN][STRLEN], text4[FLEN][STRLEN];
   int inty[FLEN][2], inty2[FLEN] = {0}, inty3[FLEN] = {0};
   int row = 0, i, j = 0, k = 0, l = 0, cnt = 0;
   if(myfile == NULL){
      printf("Unable to open file!");
      exit(EXIT_FAILURE);
   }
   while(row < FLEN && fgets(text[row], sizeof(text[0]), myfile) != NULL){
      row++;
   }
/*
   for (i = 0; i < row; i++){
      if(text[i][0] != '#'){
         strcpy(text2[j], text[i]);
         j++;
      }
   }
*/
/*Getting all data into different arrays*/
   for(i = 0; i < FLEN; i++){
      for(j = 0; j < STRLEN; j++){
         l = 0;
         k = 0;
         if(text[i][j] == '-'){
            text2[i][0] = text[i][j+1];
            text2[i][1] = text[i][j+2];
            text2[i][2] = '\0';
         }
         if(text[i][j] == ':'){
            k = j;
            text4[i][0] = text[i][j-1];
            text4[i][1] = '\0';
            while(text[i][k] != '\n'){
               text3[i][l] = text[i][k];
               l++;
               k++;
            }
         }
      }
      inty[i][0] = atoi(text[i]);
      inty[i][1] = atoi(text2[i]);
      /*printf("%s \n",text3[i]);*/
      /*printf("%d %d\n",inty[i][0], inty[i][1]);*/
   }
/*Text3 contains string, text4 contains letter to search for*/
   for(i = 0; i < FLEN; i++){
         if(text3[i][inty[i][0]+1] == text4[i][0]){
            inty2[i]++;
         }
         if(text3[i][inty[i][1]+1] == text4[i][0]){
            inty2[i]++;
         }
      if(inty2[i] == 1){
         cnt++;
      }
   }
   printf("Total = %d\n", cnt);

   for(i = 0; i < FLEN; i++){
      printf("%d\n",inty2[i]);
   }

   return 0;
}

void test(void)
{

}
