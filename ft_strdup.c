/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <kbarkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:04:08 by kbarkan           #+#    #+#             */
/*   Updated: 2024/11/16 02:23:15 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_allocated_str;
	size_t	new_str_size;
	size_t	i;

	new_str_size = ft_strlen(s1);
	new_allocated_str = malloc(new_str_size + 1);
	if (new_allocated_str == NULL)
		return (NULL);
	i = 0;
	while (i < new_str_size)
	{
		new_allocated_str[i] = s1[i];
		i++;
	}
	new_allocated_str[i] = '\0';
	return (new_allocated_str);
}
