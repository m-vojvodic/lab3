#include <stdio.h>
#include <sys/types.h>
#include <inttypes.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "ospfs.h"

int main(int argc, char **argv)
{
	char *file_name = "./ospfs/";	//"./test/ospfs_crash";
	int fd;
	int nwrites;
	int ioctl_retval;
	
	if(argc == 2)
	{
		nwrites = (int)*argv[1];
	}
	else
	{
		fprintf(stderr, "Usage: Enter number value to assign to nwrites_to_crash.\n");
		return -1;
	}

	fd = open(file_name, O_RDWR);
	if(fd == -1)
	{
		fprintf(stderr, "File could not be opened properly.\n");
		return -1;
	}

	ioctl_retval = ioctl(fd, SET_NWRITES, nwrites);
	/*if(ioctl_retval == -EACCES || ioctl_retval == -EINVAL)
	{
		fprintf(stderr, "IOCTL returned Error!\n");
		return -1;
	}*/

	close(fd);
	return ioctl_retval;
}
