#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

int prost(int broj)
{
	for(int i=2;i<=broj/2;i++)
	{
		if(broj%i==0)
			return 0;
	}
	return 1;
}


int
main(int argc,char *argv[])
{
	
	int broj=2;
	int prostbr=2;


	int *brojac;
	int *ind;
	int *nizz;	
	
	get_shared("brojac niza",&brojac);	
	get_shared("niz",&nizz);	
	int brojacc=0;
	
	nizz[0]=2;(*brojac)++;
	while(*ind!=1)
	{
	  
	//printf("%d\n",get_shared("indikator",ind));
		get_shared("indikator",&ind);
		
	   if(get_prikazibroj()==0)
		{
			printf("%d\n",nizz[(*brojac)-1]);
			set_prikazibroj(1);
		}
	   if(*ind==2)
		continue;
		
	   broj++;
	   if(prost(broj))	
	   {	
		nizz[*brojac]=broj;
		//*brojac++;
		(*brojac)++;
		prostbr=broj;
       	   }
	
	}
	exit();
}
