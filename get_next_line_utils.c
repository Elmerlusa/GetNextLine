/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:19:54 by javmarti          #+#    #+#             */
/*   Updated: 2022/10/10 13:19:54 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;

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
		ft_strlcpy(substr, s + start, len + 1);
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

	len = count * size;
	if (len && len / count != size && count != 0)
		return (NULL);
	mem = malloc(len);
	if (mem == NULL)
		return (NULL);
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

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	if (dst == NULL && dstsize == 0)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
	return (src_len + dst_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	len;

	len = ft_strlen(src);
	if (dstsize <= 0 || dst == NULL)
		return (len);
	index = 0;
	while (index < dstsize - 1 && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*s3;
	unsigned int	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = (char *)ft_calloc(len, sizeof(char));
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, s2, ft_strlen(s3) + ft_strlen(s2) + 1);
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
