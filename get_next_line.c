/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:35:21 by kenakamu          #+#    #+#             */
/*   Updated: 2025/03/17 19:24:20y kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_fd(int fd, char *save)
{
	char	*tmp;
	ssize_t	bytes_read;
	
	dprintf(2, "read_fd start\n");
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	dprintf(1, "read_fd malloc sucsessed\n");
	while (1)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);//readで長さをssize_t型で得る 副作用的にtmpに内容が追加される
		if (bytes_read <= 0 || ft_strchr(save, '\n'))
		{
			dprintf(2, "break_now:%s\n", save);
			break;//bytes_readがエラーもしくは0の場合　save内に\nが含まれる時break
		}
	
		tmp[bytes_read] = '\0';//tmpにbytes_read番目のindexに終端文字を追加して(0indexのため+1分目を指す)文字列として閉じる
		save = ft_strjoin(save, tmp);//saveにtmpを追加するstrjoinによって終端は保証される
	}
	free(tmp);
	return (save);
}

static char	*get_line(char	*save)
{
	char		*rtn;
	const char	*s0 = save;
	size_t		r_len;
	
	if (!save)
		return (NULL);

	s0 = ft_strchr(s0, '\n');//strchrでs0に何も入っていない場合 最後に\nを含む場合を分岐させる
	if (s0)
		r_len = (s0 - save) + 1;
	else
		r_len = ft_strlen(save);
	rtn = malloc(sizeof(char) * (r_len + 1));
	if(!rtn)
		return (NULL);

	(void)ft_strlcpy(rtn, save, r_len + 1);
	return (rtn);
}

static char	*save_next(char *save)
{
	const char	*s0 = save;
	char	*re_save;
	size_t	len;
	
	s0 = ft_strchr(s0, '\n');
	if (s0)
		len = (s0 - save) + 1;
	else
		len = ft_strlen(save);
	re_save = malloc(sizeof(char) * (len + 1));
	if (!re_save)
		return (NULL);
	(void)ft_strlcpy(re_save, save, len + 1);
	free(save);
	return (re_save);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*save = NULL;

	dprintf(2, "get_next_line started\n");
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return(NULL);
	}
	save = read_fd(fd, save);//saveに
	dprintf(2, "read_fd_returned: p=%p s=%s\n", (void *)save, save);
	if (!save)
		return (NULL);//saveだけなぜ？　freeはしなくていいのか(safe_freeのような実装も考がえる)
	line = get_line(save);
	save = save_next(save);
	return (line);
}