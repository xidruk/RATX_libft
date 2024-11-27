/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <kbarkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:31:58 by kbarkan           #+#    #+#             */
/*   Updated: 2024/11/12 09:08:20 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hs_index;
	size_t	ndl_index;

	if (!haystack && !len)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	hs_index = 0;
	while (haystack[hs_index] != '\0' && hs_index < len)
	{
		if (haystack[hs_index] == needle[0])
		{
			ndl_index = 0;
			while (haystack[hs_index + ndl_index] == needle[ndl_index]
				&& (hs_index + ndl_index) < len)
			{
				if (needle[ndl_index + 1] == '\0')
					return ((char *)&haystack[hs_index]);
				ndl_index++;
			}
		}
		hs_index++;
	}
	return (NULL);
}
