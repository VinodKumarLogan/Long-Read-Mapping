//
//  cb_proj_reads.cpp
//  compbiohw3
//
//  Created by Pruthvi Madugundu on 12/11/17.
//  Copyright © 2017 Pruthvi Madugundu. All rights reserved.
//

#include "../../include/reads.hpp"
// a.out foldername numberoffiles readlen outputhashfilename

char foldername[256];
char path[512] = {"./"};
int numberoffiles;
int readlen;
int numberofread;
char outputhashfilename[256];

//S_IRUSR | S_IWUSR


void getdata(int r, int w, int w2, int len)
{
	//char buf[1000];
	int i = 0;
	char c[2];
	c[1] = '\0';
	int random = rand() % 1000000;


	lseek(r, random, SEEK_SET);
	while(i < len)
	{
		read(r, &c[0], 1);
		if(c[0] == 'A' || c[0] == 'C' || c[0] == 'G' || c[0] == 'T')
		{
			write(w, &c[0], 1);
			write(w2, &c[0], 1);
			i++;
		}
	}
	write(w2, "    ", 3);
	//close();
	return;
}

void readdata(int fd, int index, int outfd, int len)
{
	char name[256] = {"\0"};

	char c[2];
	c[0] = index + '0';
	c[1] = '\0';
	strcat(name, &c[0]);

	int f = open(name, O_RDONLY | O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(f < 0)
	{
		printf("readdata open error - %s \n", name);
		exit(1);
	}

	getdata(fd, f, outfd, len);

	close(f);

	return;
}

void create_read_files(char *fname, int nfiles, int nreads, int rlen, char *outfile)
{
	char newpath[512];

	srand(time(NULL));

	strcat(path, fname);
	strcat(path, "/");
	strcat(path, fname);

	int outfd = open(outfile, O_RDONLY | O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(outfd < 0)
	{
		printf(" create_read_files 1 open error - %s \n", outfile);
		exit(1);
	}
	for(int i = 0; i < nreads; i++)
	{
		int r = rand() % nfiles;

		char c[2];
		c[0] = r + '0';
		c[1] = '\0';
		strcat(&newpath[0], path);
		strcat(&newpath[0], &c[0]);

		int fd = open(newpath, O_RDONLY);
		if(fd < 0)
		{
			printf(" create_read_files 2 open error - %s \n", newpath);
			exit(1);
		}

		readdata(fd, i, outfd, rlen);

		write(outfd, fname, strlen(fname));
		write(outfd, &c[0], 1);
		write(outfd, "\n", 1);

		close(fd);
		newpath[0] = '\0';
	}

	close(outfd);
	return;
}

/*
int main(int argc, char* argv[])
{
	if(argc < 6)
	{
		printf(" usage : a.out foldername numberoffiles numberofread readlen outputhashfilename \n");
	    return 1;
	}

	strcpy(foldername, argv[1]);
	numberoffiles = atoi(argv[2]);
	numberofread = atoi(argv[3]);
	readlen = atoi(argv[4]);
	strcpy(outputhashfilename, argv[5]);

	create_read_files(foldername, numberoffiles, numberofread, readlen, outputhashfilename);
	//strcat(path, foldername);

	return 0;
}
*/