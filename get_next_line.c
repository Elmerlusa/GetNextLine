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
char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE];
	char	*line;
	size_t	index;

	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, &buff[index], 1) <= 0)
		return (NULL);
	if (buff[index] == '\n')
		return (ft_strdup("\n"));
	line = ft_strdup("");
	if (line == NULL)
		return (NULL);
	index = 0;
	while (read(fd, &buff[++index], 1) > 0)
	{
		if (buff[index] == '\n')
			break ;
		if (index == BUFFER_SIZE - 2)
		{
			buff[index + 1] = '\0';
			line = ft_strjoin(line, buff);
			index = -1;
		}
	}
	if (buff[index] == '\n')
		buff[index + 1] = '\0';
	else
		buff[index] = '\0';
	line = ft_strjoin(line, buff);
	printf("%s", line);
	return (line);
}

int	main(void)
{
	char *filename = "file.txt";
	// char *filename = "emptyfile.txt";
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd) != NULL)
		continue ;
	return (0);
}