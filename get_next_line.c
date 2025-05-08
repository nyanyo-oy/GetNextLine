/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:07:55 by kenakamu          #+#    #+#             */
/*   Updated: 2025/05/08 19:08:17 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char	*read_minus(char *s1, char *s2)
{
	free (s1);
	free (s2);
	return (NULL);
}

static char	*read_fd(int fd, char *save)
{
	char	*tmp;
	char	*update_save;
	ssize_t	bytes_read;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (read_minus (save, tmp));
		if (bytes_read == 0)
			break ;
		tmp[bytes_read] = '\0';
		update_save = ft_strjoin(save, tmp);
		free (save);
		save = update_save;
		if (strchr_ns(save, '\n'))
			break ;
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
	s0 = strchr_ns(s0, '\n');
	if (s0)
		r_len = (s0 - save) + 1;
	else
		r_len = ft_strlen(save);
	rtn = malloc(sizeof(char) * (r_len + 1));
	if (!rtn)
		return (NULL);
	(void)ft_strlcpy(rtn, save, r_len + 1);
	return (rtn);
}

static char	*save_next(char *save)
{
	const char	*s0 = save;
	char		*re_save;
	size_t		len;

	s0 = strchr_ns(s0, '\n');
	if (s0)
	{
		s0++;
		len = ft_strlen(s0);
		re_save = malloc(sizeof(char) * (len + 1));
		if (!re_save)
			return (NULL);
		(void)ft_strlcpy(re_save, s0, len + 1);
		free(save);
		return (re_save);
	}
	else
	{
		re_save = malloc(1);
		if (!re_save)
			return (NULL);
		re_save[0] = '\0';
		free(save);
		return (re_save);
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
	{
		save = malloc(1);
		if (!save)
			return (NULL);
		save[0] = '\0';
	}
	save = read_fd(fd, save);
	if (!save || save[0] == '\0')
	{
		free (save);
		save = NULL;
		return (NULL);
	}
	line = get_line(save);
	save = save_next(save);
	return (line);
}
