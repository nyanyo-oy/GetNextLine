/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line-utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:38:09 by kenakamu          #+#    #+#             */
/*   Updated: 2025/03/15 00:57:57by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlcpy(char *dst, const char *src, size_t size)//sizeは'\0'分を含む
{
	const char *s0 = src;

	if (size > 0)
	{
		while (--size && *src != '\0')
			*dst++ = *src++;	
		*dst = '\0';
	}
	while (*src++);
	return (src - s0 - 1);
}

size_t	ft_strlen(const char *s)
{
	const char	*s0 = s;

	if(!s)
		return (0);

	while (*s)
		s++;	
	return (s - s0);
}

char	*strchr_ns(const char *s, int c)
{
	if(!s)
		return (NULL);
	while(*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}


char	*ft_strjoin(const char *s1, const char *s2)
{
	char    *dst;
	char    *res;

	if (!s1 || !s2)
			return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
			return (NULL);
	res = dst;
	while (*s1)
			*dst++ = *s1++;
	while (*s2)
			*dst++ = *s2++;
	*dst = '\0';
	return (res);
}