/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <kbarkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:29:03 by kbarkan           #+#    #+#             */
/*   Updated: 2024/11/13 08:58:43 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	des_len;
	size_t	src_len;
	size_t	des_c;
	size_t	c;

	src_len = ft_strlen(src);
	if (!dst && src && !dstsize)
		return (src_len);
	des_len = ft_strlen(dst);
	if (dstsize <= des_len)
		return (dstsize + src_len);
	des_c = des_len;
	c = 0;
	while (src[c] && des_c + 1 < dstsize)
	{
		dst[des_c] = src[c];
		c++;
		des_c++;
	}
	dst[des_c] = 0;
	return (des_len + src_len);
}
