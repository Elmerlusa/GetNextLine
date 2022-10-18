/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:25:08 by javmarti          #+#    #+#             */
/*   Updated: 2022/10/18 19:25:08 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	index;

	if (s == 0)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	substr = (char *)ft_calloc(len + 1, sizeof (char));
	if (substr == 0)
		return (0);
	if (len == 0)
		substr[0] = '\0';
	else
	{
		index = 0;
		while (index < len && s[index])
		{
			substr[index] = s[index];
			index++;
		}
		substr[index] = '\0';
	}
	return (substr);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	len;
	size_t	index;

	len = count * size;
	if (len && len / count != size && count != 0)
		return (NULL);
	mem = malloc(len);
	if (mem == NULL)
		return (NULL);
	index = 0;
	while (index < len)
		((unsigned char *)mem)[index++] = '\0';
	return (mem);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*s3;
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	index1;
	unsigned int	index2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (s3 == NULL)
		return (NULL);
	index1 = -1;
	while (++index1 < len1 && s1[index1])
		s3[index1] = s1[index1];
	index2 = -1;
	len1 += len2;
	while (index1 + ++index2 < len1 && s2[index2])
		s3[index1 + index2] = s2[index2];
	s3[index1 + index2] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char *)(s + index));
		index++;
	}
	if (s[index] == (char)c)
		return ((char *)(s + index));
	return (NULL);
}
