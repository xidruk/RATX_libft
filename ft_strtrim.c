/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <kbarkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:21:44 by kbarkan           #+#    #+#             */
/*   Updated: 2024/11/14 20:38:17 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_valid(char str_c, char const *set)
{
	while (*set)
	{
		if (str_c == *set)
			return (1);
		set++;
	}
	return (0);
}

static	char	*string_validator(char const *ss1, char const *sset)
{
	if (!*ss1 || !*sset)
		return (ft_strdup(""));
	return (NULL);
}

static	char	*get_trimmed_string(char const *s1, size_t start, size_t end)
{
	char	*new_string;
	size_t	i;

	new_string = malloc(sizeof(char) * (end - start + 2));
	if (!new_string)
	{
		return (NULL);
	}
	i = 0;
	while (start <= end)
	{
		new_string[i++] = s1[start++];
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(""));
	if (!*set)
		return (ft_strdup(s1));
	result = string_validator(s1, set);
	if (result)
		return (result);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && is_valid(s1[start], set))
		start++;
	if (start > end)
		return (ft_strdup(""));
	while (end > start && is_valid(s1[end], set))
		end--;
	return (get_trimmed_string(s1, start, end));
}
