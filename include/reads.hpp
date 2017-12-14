#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>	

void create_read_files(char *fname, int nfiles, int nreads, int rlen, char *outfile);
