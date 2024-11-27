/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <kbarkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:02:02 by kbarkan           #+#    #+#             */
/*   Updated: 2024/11/20 03:43:20 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_str;
	size_t			index;

	index = 0;
	new_str = (unsigned char *)s;
	while (index < n)
	{
		if (new_str[index] == (unsigned char)c)
		{
			return ((void *)&new_str[index]);
		}
		index++;
	}
	return (NULL);
}
