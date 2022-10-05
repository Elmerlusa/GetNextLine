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

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	if (line == NULL)
		return (NULL);
	index = 0;
	while (read(fd, &buff[index], 1) > 0)
	{
		if (buff[index] == '\n')
			break ;
		if (index++ == BUFFER_SIZE - 2)
		{
			buff[index] = '\0';
			line = ft_strjoin(line, buff);
			index = 0;
		}
	}
	if (buff[index] == '\n')
		buff[++index] = '\0';
	else
		buff[index] = '\0';
	line = ft_strjoin(line, buff);
	if (ft_strlen(line) == 0)
		return (NULL);
	return (line);
}

int	main(void)
{
	char *filename = "file.txt";
	// char *filename = "emptyfile.txt";
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	char *line = " ";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	printf("%s", get_next_line(1));
	return (0);
}