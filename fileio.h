#pragma once
#ifndef FILEIO_H
#define FILEIO_H
#define CALL_CMD() (system("cmd.exe"))
#include <stdio.h>
#include <stdlib.h>

#define MAX_PATH_LEN 200

int create(char *path)
{
	
	FILE *file  = fopen(path,"a");
	fclose(file);
	return EXIT_SUCCESS;
}

int write(char path[MAX_PATH_LEN],char *mess)
{
    FILE *fp;
    if((fp= fopen(path, "w"))==NULL)
    {
        perror("Error occured while opening file");
        return EXIT_FAILURE;
    }
    
    fprintf(fp,"%s",mess);
    fclose(fp);
    return EXIT_SUCCESS;
}

int  read(char path[MAX_PATH_LEN])
{
	FILE *file ;
	char c;

    if((file= fopen(path, "r"))==NULL)
    {
        perror("Error occured while opening file");
        return EXIT_FAILURE;
    }
    
    while((c = getc(file))!= EOF)
    {
	
        printf("%c", c);
    }
     
    fclose(file);
    return EXIT_SUCCESS;
}

int append(char path[MAX_PATH_LEN],char *mess)
{
	
	FILE *file = fopen(path,"a");
     fprintf(file,"%s",mess);
	fclose(file);
	return EXIT_SUCCESS;
}
int appendn(char *path,char *mess)
{
	FILE *file = fopen(path,"a");
   
    fprintf(file,"%s\n",mess);
	fclose(file);
	return 0;
}

#endif /*FILEIO_H*/
