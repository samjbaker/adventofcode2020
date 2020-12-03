#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define FLEN 200

void test(void);

int main(void)
{
   FILE *fp;
   char name[50], str[FLEN][50] = {0};
   int nums[FLEN] = {0}, a, b, c;
   int i = 0, j, k;
   fp = fopen("input/input1.1.txt", "r");

   if(fp == NULL){
      printf("Error opening file\n");
      exit(EXIT_FAILURE);
   }

   while(fscanf(fp, "%s", &name[0]) != EOF){
      strcpy(str[i], name);
      nums[i] = atoi(str[i]);
      i++;
   }
   for(i = 0; i < FLEN - 2; i++){
      /*printf("%d ", nums[i]);*/
      for(j = i + 1; j < FLEN - 1; j++){
         for(k = j + 1; k < FLEN; k++){
            if(nums[i] + nums[j] + nums[k] == 2020){
               a = nums[i];
               b = nums[j];
               c = nums[k];
            }
         }
      }
   }
   printf("%d %d %d\n", a, b, c);
   printf("Product: %d", a*b*c);
   /*printf("%s",str[1]);*/
   printf("\n");
   fclose(fp);
   return 0;
}

void test(void)
{

}
