#include<stdio.h>
#include<string.h>

main()
{
 int i,k,p;
 FILE* fp;
 char jiami[20] = "hbxfbmphbxfbmphbxfb";
 char acco[20];
 fp = fopen("D:\\story\\account.ys","rb");
 fread(&p,4,1,fp);
 i = 1;
 while(i<=p)
 {
  fread(acco,20,1,fp);
  printf("%d.%s    ",i,acco);
  fread(acco,20,1,fp);
  k = 0;
  for(k=0;k<=strlen(acco)-1;k++)
  {
   acco[k] -= jiami[k];
  }
  printf("%s\n",acco);
  i++;
 }
 fclose(fp);
 int t;
 printf("请选择删除的账号:");
 scanf("%d",&t);
 getchar();
 if(p>=1&&t>=1&&t<=p)
 {
	printf("确认删除？ 1.确定  2.取消\n");
	printf("请选择:");
	scanf("%d",&i);
	getchar();
	if(i==1)
	{
		FILE *fr;
		char c;
		fp = fopen("D:\\story\\account.ys","rb");
		fr = fopen("D:\\story\\temp.ys","wb");
		c=fgetc(fp);
		while(!feof(fp))
		{
			fputc(c,fr);
			c=fgetc(fp);
		}
		fclose(fp);
		fclose(fr);
		fp = fopen("D:\\story\\account.ys","wb");
		fr = fopen("D:\\story\\temp.ys","rb");
		fread(&i,4,1,fr);
		i--;
		fwrite(&i,4,1,fp);
		for(k=1;k<t;k++)
		{
			fread(acco,20,1,fr);
			fwrite(acco,20,1,fp);
			fread(acco,20,1,fr);
			fwrite(acco,20,1,fp);
		}
		k++;
		fseek(fr,40L,1);
		for(;k<=p;k++)
		{
			fread(acco,20,1,fr);
			fwrite(acco,20,1,fp);
			fread(acco,20,1,fr);
			fwrite(acco,20,1,fp);
		}
		fclose(fp);
		fclose(fr);
		printf("已删除\n");
		unlink("D:\\story\\temp.ys");
	}
 }
}