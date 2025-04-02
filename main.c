#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	fd;
	char	*res = NULL;

	dprintf(2, "main開始\n");
	fd = open("example.txt", O_RDONLY);
	dprintf(2, "file_opened:fd=%d\n", fd);
	if(fd == -1)
	{
		dprintf(2, "fd_errored\n");
		return (-1);
	}
	res = get_next_line(fd);	
	dprintf(2, "gnl_returned:p=%p\n", (void *)res);
	printf("%s\n", res);
	free(res);
	close(fd);

	return(0);
}

//int	main(void)
//{
//	int		fd[2];
//	char	*line;
//	size_t	i;
//	size_t	j;
	
//	fd[0]= open("test1.txt", O_RDONLY);
//	fd[1]= open("test2.txt", O_RDONLY);
//	i=0;
//	while(i<10)
//	{
//		j=0;	
//		printf("test%zu.text:\n",j);
//		line = get_next_line(fd[0]);
//		printf("> %s", line);
//		free(line);
//			printf("\n\n");

//		j=1;
//		printf("test%zu.text:\n",j);
//		line = get_next_line(fd[j]);
//		printf("> %s", line);
//		free(line);
//			printf("\n\n");	
//		i++;
//	}
		
//	j=0;
//	while(j < 2)
//	{
//		close(fd[j]);
//	}
//	return (0);
//}
