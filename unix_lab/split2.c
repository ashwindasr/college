#include <stdio.h>
#include <stdlib.h>

int split(char file[],int size,char prefix)
{
		char generated_filename[4]={prefix,'a','`','\0'};
		char buf[200];
		int c=0;
		FILE *ptr_file,*ptr_file2;
		ptr_file = fopen(file,"r");

while(fgets(buf,200,ptr_file)!=NULL)
    {
			
			if(c==size || c==0)		//Condition for creating new file
			{
				c=0;
				if(generated_filename[2] < 'z'){
				generated_filename[2]++;
			}
			else{
				generated_filename[1]++;
				generated_filename[2] = 'a';
			}
			if(generated_filename[2] > 'z'){
				printf("File limit: 676 reached\n");
				exit(0);
			}
				ptr_file2 =fopen(generated_filename, "w");
			}
       	fprintf(ptr_file2,"%s",buf);
			c+=1;
			if(c==size)					//Condition for closing already open file 	
        		fclose(ptr_file2);
    }
    fclose(ptr_file);
	return 0;
}
void main(int argc, char** argv)
{
	char prefix='x';
	switch(argc)
	{
		case 1: 
				{
					printf("No arguments");
				 	break;
				}
		case 2: 
				{
					split(argv[1],1000,'x');
					break;
				}
		case 3: 
				{
					printf("Invalid number of arguemnts");
					break;		
				}
		case 4: 
				{
					if(argv[1][1]=='l')
					{
						split(argv[3],atoi(argv[2]),'x');
				 		break;
					}
					else
						printf("Option not supported");
				}
		case 5:
				{
					if(argv[1][1]=='l')
					{
						split(argv[3],atoi(argv[2]),*argv[4]);
				 		break;
					}
					else
						printf("Invalid number of arguments");
				}
		}
}
