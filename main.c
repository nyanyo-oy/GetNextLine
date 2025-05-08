#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	fd;
	char	*line = NULL;
	size_t count=0;

	//fd = open("example", O_RDONLY);
	//if(fd == -1)
	//{
	//	dprintf(2, "fd_errored\n");
	//	return (1);
	//}


	fd=0;
	while(1)
	{
		count++;
		printf("%zu\n",count);
		printf("-----------------------------------------------------\n");
		line = get_next_line(fd);
		if(!line)
			break;
		printf("[%s]", line);
		free(line);
	}

	close(fd);
	return(0);
}

