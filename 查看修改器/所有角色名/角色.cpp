#include<stdio.h>

main()
{
 int i,k,p;
 FILE* fp;
 FILE* f1;
 char acco[20];
 fp = fopen("D:\\story\\name.ys","rb");
 fread(&p,4,1,fp);
 printf("×Ü¹²%d¸ö\n\n",p);
 i = 1;
 while(i<=p)
 {
  fread(acco,20,1,fp);
  printf("%s\n",acco);
  i++;
 }
 fclose(fp);
}