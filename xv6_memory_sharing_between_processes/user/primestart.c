#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"


int niz[100000];
int
main(int argc, char *argv[])
{
	int brojacniza=0;
	int indikator=0;
		

	if(share_mem("niz",niz,400000)<0)
	{	
		//printf("%d\n",share_mem("niz",niz,400000));
	}
	if(share_mem("brojac niza",&brojacniza,4)<0)
	{	
		printf("Greska1\n");
	}
	
	if(share_mem("indikator",&indikator,4)<0)
	{
		//printf("Ispisi: %d\n",share_mem("indikator",&indikator,4));
	}

		int pid;
		
		pid = fork();
			
		if(pid < 0){
			printf("init: fork failed\n");
			exit();
		}
		if(pid == 0){
			exec("/bin/primecalc", argv);
		}
		/*while((wpid=wait()) >= 0 && wpid != pid)
			printf("zombie!\n");*/
		pid = fork();
		if(pid < 0){
			printf("init: fork failed\n");
			exit();
		}
		if(pid == 0){
			exec("/bin/primecom", argv);
			}
		/*while((wpid=wait()) >= 0 && wpid != pid)
			printf("zombie!\n");*/


		
		wait();
		wait();

			//share_mem(name,addr,size);	
			
		exit();
		
}
