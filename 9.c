#include<stdio.h>
#include<time.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
	if(argc<2)
	{
		printf("Specify the file.\n");
		return 0;
	}
	struct stat s;
	int x = stat(argv[1],&s);
	if(x<0)
	{
		perror("File doesn't exist.\n");
		return 0;
	}
	printf("Inode number is: %ju\n", s.st_ino);
	printf("Number of hard links: %ju\n", s.st_nlink);
	printf("Uid is: %u\n",s.st_uid);
	printf("Gid is: %u\n",s.st_gid);
	printf("File size is: %jd bytes\n", s.st_size);
	printf("Size of the block is: %jd bytes\n", s.st_blksize);
	printf("Number of blocks are: %jd\n", s.st_blocks);
	printf("Time of last access is: %s\n", ctime(&s.st_atime));
	printf("Time of last modification: %s\n", ctime(&s.st_mtime));
	printf("Time of last change: %s\n", ctime(&s.st_ctime));
	return 0;
}
