/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <kbarkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:56:19 by kbarkan           #+#    #+#             */
/*   Updated: 2024/11/01 20:06:15 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*new_s1;
	const unsigned char	*new_s2;
	size_t				index;

	index = 0;
	new_s1 = (const unsigned char *)s1;
	new_s2 = (const unsigned char *)s2;
	while (index < n)
	{
		if (new_s1[index] != new_s2[index])
		{
			return (new_s1[index] - new_s2[index]);
		}
		index++;
	}
	return (0);
}
