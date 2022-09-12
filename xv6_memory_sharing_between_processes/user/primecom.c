#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

int strcmpn(char *a,char *b,int n)
{
	for(int i=0;i<n;i++)
	{	
		if(a[i]!=b[i])
			return -1;
	}	
	return 0;
}

int
main(int argc, char *argv[])
{
		/*for(int i=1; i<argc; i++)
		printf(argv[i]);*/
	
	//Kao zadatak
	printf("Commands:\n");
	printf("prime <n>\n");
	printf("latest\n");
	printf("pause\n");
	printf("resume\n");
	printf("end\n");

	char *tekst;
	int* ind;
	while(*ind!=1)
	{
		gets(tekst,20);
		
		if(strcmpn(tekst,"end",3)==0 && strlen(tekst)==4)
		{
			//set_kraj(1);
			get_shared("indikator",&ind);
			*ind=1;
		}
		else if(strcmpn(tekst,"pause",5)==0 && strlen(tekst)==6)
		{
				get_shared("indikator",&ind);
			*ind=2;
		}
		else if(strcmpn(tekst,"resume",6)==0 && strlen(tekst)==7)
		{
				get_shared("indikator",&ind);
			*ind=3;
		}
		else if(strcmpn(tekst,"prime ",6)==0)
		{
			int d=strlen(tekst);
			int broj[d-6];int brojaccc=0;
			int greskao=0;
			for(int i=6;i<strlen(tekst)-1;i++)
			{
				if(!(tekst[i]-'0'>=0 && tekst[i]-'0'<=9))
				{
					greskao=1;
					break;					
				}
				int pomocni=tekst[i]-'0';
				broj[brojaccc]=pomocni;brojaccc++;
				//printf("%d\n",broj[brojaccc-1]);
			}
			if(greskao==0)
			{

				int brojstvarno=0;			
				for(int i=0;i<brojaccc;i++)
				{
					brojstvarno=brojstvarno*10+broj[i];
				}
			
			int *nizz;

			get_shared("niz",&nizz);
			

			if(brojstvarno<100000)
			{
				if(nizz[brojstvarno]!=0)
				{
					printf("%d\n",nizz[brojstvarno]);	
				}
				else
				{	
					printf("Jos nije stigao do tog broja\n");	
				}
			}
			else
			{
				printf("Greska pri unosu broja\n");
			}


			}
			else
			{
				printf("Greska pri unosu broja\n");
			}

			
		}	
		else if((strcmpn(tekst,"latest",6)==0 || strcmpn(tekst,"prime",5)==0) && 				(strlen(tekst)==6 || strlen(tekst)==7) )
		{

			int *brojac;
			int *nizz;

			get_shared("brojac niza",&brojac);	
			get_shared("niz",&nizz);

			printf("%d\n",nizz[(*brojac)-1]);
		}
		else
		{
			printf("Greska pri unosu\n");
		}
	}
	exit();

}
