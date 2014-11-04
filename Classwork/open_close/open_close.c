#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  if (argc!=2)
  {
    fprintf(stderr,"Invalid count of arguments\n");
    fprintf(stderr,"Usage: open close <filename>\n");
    return 1;
  }
  int fd=open("/dev/zero",O_RDONLY);
  if (fd<0)
  {
    fprintf(stderr,"Can't recreate file %s\n",argv[1]);
    return 1;
  }
  double result=0;
  for (int i=0;i<10;++i)
  {
     read(fd,&result,sizeof(double));
     fprintf(stdout,"%.10g\n",result);
  } 
  if (close(fd)!=0) 
  {
    fprintf(stderr,"Can'tclose file %s\n",argv[1]);
    return 1;
  } 
  return 0;
}
