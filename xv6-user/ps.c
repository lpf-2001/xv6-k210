#include "kernel/include/types.h"
#include "kernel/include/stat.h"
#include "xv6-user/user.h"
int
main(int argc, char *argv[])
{
	ps();
	exit(0);
}
