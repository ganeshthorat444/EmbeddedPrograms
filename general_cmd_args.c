#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

/*struct option  {
               const char *name ;
               int         has_arg;
               int        *flag;
               int         val;
           };*/


static struct option const longopts[] =
{
  {"no-create",required_argument, 0, 'c'},
  {"create",required_argument, 0, 'a'},
  {NULL, 0, NULL, 0}
};

int main(int argc, char* argv[])
{
	int c;
	while ((c = getopt_long(argc, argv, "c:a:", longopts, NULL)) != -1)
	{
		switch (c)
		{
			case 'a':
				printf("%c Name1 = %s\r\n", c, optarg);
				break;

			case 'c':
				printf("%c Name2 = %s\r\n", c, optarg);
				break;


			default:
				printf("Default\r\n");
				break;
		}
	}
	return 0;	
	printf("EXIT\r\n");
}


