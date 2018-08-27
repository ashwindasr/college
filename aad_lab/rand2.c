//Program to sort a random file

#include <stdlib.h>
#include <stdio.h>
#define NUMELE 10

void main()
{
	int i,j,t;
	FILE *fpr;
	int a[NUMELE];
	for(i=0;i<NUMELE;i++)
		scanf("%d",&a[i]);
		
	
	int pos;
	
	for(i=0;i<NUMELE-1;i++){
        pos=i;
        for(j=i+1;j<NUMELE;j++){
            if(a[pos]>a[j]){
                pos=j;
            }
        }
        if(pos!=i){
            t=a[i];
            a[i]=a[pos];
            a[pos]=t;
        }
    }
    
    fpr=fopen("ascending.txt","w");
    for(i=0;i<NUMELE;i++)
		fprintf(fpr,"%d\n",a[i]);
	fclose(fpr);


    for(i=0;i<NUMELE-1;i++){
        pos=i;
        for(j=i+1;j<NUMELE;j++){
            if(a[pos]<a[j]){
                pos=j;
            }
        }
        if(pos!=i){
            t=a[i];
            a[i]=a[pos];
            a[pos]=t;
        }
    }
    
    fpr=fopen("descending.txt","w");
    for(i=0;i<NUMELE;i++)
		fprintf(fpr,"%d\n",a[i]);
	fclose(fpr);


    
}
