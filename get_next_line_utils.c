/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:59:32 by javmarti          #+#    #+#             */
/*   Updated: 2022/10/06 19:00:55 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	len;

	len = count * size;
	if (len && len / count != size)
		return (0);
	mem = malloc(len);
	if (mem == 0)
		return (0);
	ft_bzero(mem, len);
	return (mem);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;

	if (len == 0)
		return (b);
	index = 0;
	while (index < len)
		((unsigned char *)b)[index++] = (unsigned char)c;
	return (b);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s1) + 1;
	if (len == 0 || s1 == 0)
		return (NULL);
	cpy = (char *)ft_calloc(len, sizeof(char));
	if (cpy == 0)
		return (0);
	ft_strlcpy(cpy, s1, len);
	return (cpy);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
