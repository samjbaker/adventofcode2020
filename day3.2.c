#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define FLEN 323
#define STRLEN 32

int tree_counter(char text[FLEN][STRLEN], int right, int down);

void test(void);

int main(void)
{
   FILE *myfile = fopen("input3.txt", "r");
   char text[FLEN][STRLEN], text2[FLEN][STRLEN], text3[FLEN][STRLEN], name[STRLEN];
   char text4[FLEN][STRLEN], text5[FLEN][STRLEN];
   unsigned long row = 0, cnt11, cnt31, cnt51, cnt71, cnt12;
   unsigned long z;
   if(myfile == NULL){
      printf("Unable to open file!");
      exit(EXIT_FAILURE);
   }
   while(fscanf(myfile, "%s", &name[0]) != EOF){
      strcpy(text[row], name);
      strcpy(text2[row], name);
      strcpy(text3[row], name);
      strcpy(text4[row], name);
      strcpy(text5[row], name);
      row++;
   }
   cnt11 = tree_counter(text, 1, 1);
   cnt31 = tree_counter(text2, 3, 1);
   cnt51 = tree_counter(text3, 5, 1);
   cnt71 = tree_counter(text4, 7, 1);
   cnt12 = tree_counter(text5, 1, 2);
   printf("R1, D1 Trees = %ld\n", cnt11);
   printf("R3, D1 Trees = %ld\n", cnt31);
   printf("R5, D1 Trees = %ld\n", cnt51);
   printf("R7, D1 Trees = %ld\n", cnt71);
   printf("R1, D2 Trees = %ld\n", cnt12);
   z = (unsigned long)(cnt11*cnt31*cnt51*cnt71*cnt12);
   printf("All multiplied together: %ld\n\n", z);
   return 0;
}

int tree_counter(char text[FLEN][STRLEN], int right, int down)
{
   int i, j, cnt = 0;
   /*int k;*/
   i = right;
   j = down;
   while(j < FLEN){
      if(text[j][i] == '#'){
         text[j][i] = 'X';
      }
      if(text[j][i] == '.'){
         text[j][i] = 'O';
      }
      if(i + right >= STRLEN - 1){
         i = (i + right) - (STRLEN-1);
      }
      else{
         i += right;
      }
      j += down;
   }

   for(j = 0; j < FLEN; j++){
      for(i = 0; i < STRLEN - 1; i++){
         if(text[j][i] == 'X'){
            cnt++;
         }
      }
   }
/*
   for(k = 0; k < FLEN; k++){
      printf("%s",text[k]);
      printf(" %d\n", k);
   }*/
   return cnt;
}

void test(void)
{

}
