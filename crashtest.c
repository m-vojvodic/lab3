#include <stdio.h>
#include <sys/types.h>
#include <inttypes.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "ospfs.h"

int main(int argc, char **argv)
{
	char *file_name = "./test/ospfs_crash";
	int fd;
	long nwrites;
	long ioctl_retval;
	
	if(argc == 2)
	{
		nwrites = strtol(argv[1], &nwrites, 10);
	}
	else
	{
		fprintf(stderr, "Usage: Enter number value to assign to nwrites_to_crash.\n");
		return -1;
	}

	fd = open(file_name, O_RDONLY);
	if(fd == -1)
	{
		fprintf(stderr, "File could not be opened properly.\n");
		return -1;
	}

	ioctl_retval = ioctl(fd, SET_NWRITES, nwrites);

	close(fd);
	return ioctl_retval;
}
