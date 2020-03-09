#include <stdio.h>
#include <iostream>
#include <fstream>

int main()
{
	FILE *fp;
	char rawfile[500];
	fp = fopen("raw1","r");
	while(!feof(fp))
	{
		fscanf(fp,"%s\n",rawfile);
		printf("line: %s\n",rawfile);
	}
	fclose(fp);

	FILE *lnfp;
	char lnfile[500];
	lnfp = fopen("lnfiles","r");
	while(!feof(lnfp))
	{
		fscanf(lnfp,"%s\n",lnfile);
		printf("line2: %s\n",lnfile);
	}
	fclose(lnfp);
}
