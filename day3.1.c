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
   char text[FLEN][STRLEN], name[STRLEN];
   int row = 0, cnt;
   if(myfile == NULL){
      printf("Unable to open file!");
      exit(EXIT_FAILURE);
   }
   while(fscanf(myfile, "%s", &name[0]) != EOF){
      strcpy(text[row], name);
      row++;
   }
   cnt = tree_counter(text, 3, 1);
   printf("\nR3, D1 Trees = %d\n", cnt);
   return 0;
}

int tree_counter(char text[FLEN][STRLEN], int right, int down)
{
   int i, j, cnt = 0, k;
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

   for(k = 0; k < FLEN; k++){
      printf("%s",text[k]);
      printf(" %d\n", k);
   }
   return cnt;
}

void test(void)
{

}
