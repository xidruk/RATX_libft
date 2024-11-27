/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <kbarkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:11:46 by kbarkan           #+#    #+#             */
/*   Updated: 2024/11/13 07:40:47 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_allocated_size(int nn, int sg)
{
	int	size;

	size = 0;
	if (nn == 0)
		return (1);
	if (nn < 0)
		nn = -nn;
	while (nn > 0)
	{
		size++;
		nn /= 10;
	}
	if (sg < 0)
		return (size + 1);
	return (size);
}

static	char	*underflow_handler(void)
{
	char	*underflow;
	int		index;
	char	undf_value[12];

	ft_strlcpy(undf_value, "-2147483648", sizeof(undf_value));
	underflow = malloc(12 * sizeof(char));
	if (!underflow)
		return (NULL);
	index = 0;
	while (undf_value[index] != '\0')
	{
		underflow[index] = undf_value[index];
		index++;
	}
	underflow[index] = '\0';
	return (underflow);
}

static	char	*cast_int_value(int num_value, int sign)
{
	int		size;
	char	*new_str;
	int		index;

	size = count_allocated_size(num_value, sign);
	new_str = malloc((size + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[size] = '\0';
	if (sign < 0)
	{
		new_str[0] = '-';
		num_value = -num_value;
	}
	index = size - 1;
	while (num_value > 0)
	{
		new_str[index--] = (num_value % 10) + '0';
		num_value /= 10;
	}
	return (new_str);
}

char	*ft_itoa(int n)
{
	int		num_sign;
	char	*zero_case;

	if (n == -2147483648)
		return (underflow_handler());
	if (n > 0)
		num_sign = 1;
	else if (n < 0)
		num_sign = -1;
	else
	{
		zero_case = malloc(2 * sizeof(char));
		if (!zero_case)
			return (NULL);
		zero_case[0] = '0';
		zero_case[1] = '\0';
		return (zero_case);
	}
	return (cast_int_value(n, num_sign));
}
