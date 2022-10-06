/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:44:46 by javmarti          #+#    #+#             */
/*   Updated: 2022/10/03 18:44:46 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*join_line(char *line, char *buff, int index);

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE];
	char	*line;
	int		index;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	if (line == NULL)
		return (NULL);
	printf("LINE > %p\n", line);
	index = 0;
	while (read(fd, &buff[index], 1) > 0)
	{
		if (buff[index] == '\n')
			break ;
		if (index == BUFFER_SIZE - 2)
		{
			line = join_line(line, buff, index + 1);
			if (line == NULL)
				return (NULL);
			index = -1;
		}
		index++;
	}
	return (join_line(line, buff, index));
}

static char	*join_line(char *line, char *buff, int index)
{
	char	*new_line;

	if (buff[index] == '\n')
		index++;
	buff[index] = '\0';
	new_line = ft_strjoin(line, buff);
	free(line);
	if (new_line == NULL || ft_strlen(new_line) == 0)
	{
		free(new_line);
		return (NULL);
	}
	return (new_line);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	len;

	len = ft_strlen(src);
	if (dstsize <= 0 || dst == 0)
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	src_len;
	size_t	dst_len;

	if (dst == 0 && dstsize == 0)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	index = 0;
	while (dst_len + index < dstsize - 1 && src[index])
	{
		dst[dst_len + index] = src[index];
		index++;
	}
	dst[dst_len + index] = '\0';
	return (src_len + dst_len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*s3;
	unsigned int	len;

	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = (char *)ft_calloc(len, sizeof(char));
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, s2, ft_strlen(s3) + ft_strlen(s2) + 1);
	return (s3);
}

int	main(void)
{
	char *filename = "file.txt";
	// filename = "emptyfile.txt";
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	char *line = " ";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	printf("---------------\n");
	line = get_next_line(1);
	printf("%s", line);
	free(line);
	free(NULL);
	// system("leaks -q a.out");
	return (0);
}