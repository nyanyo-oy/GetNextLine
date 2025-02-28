/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:53:33 by kenakamu          #+#    #+#             */
/*   Updated: 2025/02/28 17:52:48 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static void	*free_all(**str)
{
	
}
char	*find_next_line(char *str)
{
	
}
char	*put_into_str(char *res)
{

}
static void read_and_tmp(int fd)
{
	char	*buff;
	ssize_t		bytesRead;

	buff = malloc(sizeof(char)) * (BUFFER_SIZE + 1);
	if (!buff)
		return(-1);
	bytesRead = (read(fd, buff, BUFFER_SIZE));
	if (fd < 0)
	return ();
}

static int	
char	*get_next_line(int fd)
{
	static char	*tmp[FD_SETSIZE] = {NULL};//why static
	char		*res;	

	if (fd < 0 | fd >= FD_SETSIZE | BUFFER_SIZE <= 0)
		return(NULL);
		
	find_next_line(fd, );
	read_and_tmp
	
}