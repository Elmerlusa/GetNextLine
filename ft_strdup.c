/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:22:07 by javmarti          #+#    #+#             */
/*   Updated: 2022/09/18 19:22:07 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s1) + 1;
	if (len == 0 || s1 == 0)
		return (0);
	cpy = (char *)ft_calloc(len, sizeof(char));
	if (cpy == 0)
		return (0);
	ft_strlcpy(cpy, s1, len);
	return (cpy);
}
