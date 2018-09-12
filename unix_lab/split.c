#include <stdio.h>
#include <stdlib.h>

void main(int argc, char** argv)
{
	// Find the number of lines in the text file
	FILE *fileptr;
   int count_lines;
	count_lines=0;
   char filechar[40], chr;
 	if(argv[1][1]=='l')
   	fileptr = fopen(argv[3], "r");
	else
		fileptr = fopen(argv[1], "r");

    chr = getc(fileptr);
    while (chr != EOF)
    {

        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }

        chr = getc(fileptr);
    }
	//Set the split value (the number of lines each to be split)
	int split_num;
	if(argv[1][1]=='l')								//checking for 'l' of '-l'
		split_num=argv[2][0] - '0';
	else
		split_num=count_lines;
		
	//Splitting text file
	char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   int i,x;
   char s[count_lines+1];
   FILE *ptr_file,*ptr_file2;
	if(argv[1][1]=='l')
   	ptr_file = fopen(argv[3], "r");
	else
		ptr_file = fopen(argv[1], "r");
   char buf[1000];
	int c;
	c=0;											//Coumter to keep track of the number of lines written to a file 
   while(fgets(buf,1000,ptr_file)!=NULL)
    {
			
			if(c==split_num || c==0)		//Condition for creating new file
			{
				c=0;
				// Generate a random string for filename
       		for( i = 0; i < count_lines; ++i) 
				{
                 s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
            }
 			s[count_lines] = 0;
				ptr_file2 =fopen(s, "w");
			}
       	fprintf(ptr_file2,"%s",buf);
			c+=1;
			if(c==split_num)					//Condition for closing already open file 	
        		fclose(ptr_file2);
    }
    fclose(ptr_file);
	


}
