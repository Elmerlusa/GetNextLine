/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:21:30 by javmarti          #+#    #+#             */
/*   Updated: 2022/09/18 19:21:30 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
