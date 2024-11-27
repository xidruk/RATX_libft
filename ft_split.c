/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <kbarkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:45:02 by kbarkan           #+#    #+#             */
/*   Updated: 2024/11/20 03:07:11 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	free_faild_ss(char **result, int i)
{
	while (i > 0)
	{
		free(result[--i]);
	}
	free(result);
}

static	int	count_words(const char *str, char delimiter)
{
	int	word_count;
	int	in_word;

	word_count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != delimiter && !in_word)
		{
			word_count++;
			in_word = 1;
		}
		else if (*str == delimiter)
		{
			in_word = 0;
		}
		str++;
	}
	return (word_count);
}

static	char	*create_word(const char *start, int length)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((length + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < length)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static	char	*get_next_word(const char **str, char delimiter)
{
	const char	*start;
	int			length;

	length = 0;
	while (**str && **str == delimiter)
		(*str)++;
	start = *str;
	while (**str && **str != delimiter)
	{
		(*str)++;
		length++;
	}
	if (length > 0)
		return (create_word(start, length));
	else
		return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	char	*word;
	int		count_word;

	if (!s)
		return (NULL);
	count_word = count_words(s, c);
	result = malloc((count_word + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count_word)
	{
		word = get_next_word(&s, c);
		if (!word)
		{
			free_faild_ss(result, i);
			return (NULL);
		}
		result[i++] = word;
	}
	result[i] = (NULL);
	return (result);
}
