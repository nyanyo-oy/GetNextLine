/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:35:28 by kenakamu          #+#    #+#             */
/*   Updated: 2025/04/15 14:54:43 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

static char	*read_fd(int fd, char *save)
{
	char	*tmp;
	char	*update_save;
	ssize_t	bytes_read;

	dprintf(2, "\nread_fd starts\n");

	if (!save){
		save = malloc(1);
		if (!save)
			return (NULL);
		save[0] = '\0';
	}

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	dprintf(1, "read_fd malloc success\n");

	while (1)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);

		if (bytes_read < 0){
			dprintf(2, "read error occured\n");
			free (save);
			free (tmp);
			return (NULL);//bytes_readが0の場合　
		}

		if (bytes_read == 0){
			dprintf(2, "bytes_read is 0\n");
			break;
		}

		tmp[bytes_read] = '\0';//tmpにbytes_read番目のindexに終端文字を追加して(0indexのため+1分目を指す)文字列として閉じる
		update_save = ft_strjoin(save, tmp);//saveにtmpを追加するstrjoinによって終端は保証される
		free (save);
		save = update_save;

		if (strchr_ns(save, '\n')){
			dprintf(2, "\\n found\n");
			break;//save内に\nが含まれる時break
		}
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

	s0 = strchr_ns(s0, '\n');//strchrでs0に何も入っていない場合 最後に\nを含む場合を分岐させる
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

	s0 = strchr_ns(s0, '\n');
	if (s0){
		s0++;
		len = ft_strlen(s0);
		re_save = malloc(sizeof(char) * (len + 1));
		if (!re_save)
			return (NULL);
		(void)ft_strlcpy(re_save, s0, len + 1);
		free(save);
		return (re_save);
	}else{
		free(save);
		return(NULL);
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	dprintf(2, "\nget_next_line starts");
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return(NULL);
	}
	save = read_fd(fd, save);//saveに
	// dprintf(2, "read_fd_returned: p=%p s=%s\n", (void *)save, save);
	if (!save)
		return (NULL);//saveだけなぜ？　freeはしなくていいのか(safe_freeのような実装も考がえる)
	line = get_line(save);
	save = save_next(save);
	// dprintf(2, "save_next:%s", save);
	return (line);
}
