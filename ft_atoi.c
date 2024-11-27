/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <kbarkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:06:01 by kbarkan           #+#    #+#             */
/*   Updated: 2024/11/22 07:53:46 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(unsigned long nbr, int new_digit, int sign)
{
	if (sign == 1)
	{
		if (nbr > 922337203685477580
			|| (nbr == 922337203685477580 && new_digit > 7))
			return (-1);
	}
	else if (sign == -1)
	{
		if (nbr > 922337203685477580
			|| (nbr == 922337203685477580 && new_digit > 8))
			return (0);
	}
	return (1);
}

static int	check_spaces(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *str)
{
	unsigned long	result;
	int				sign_value;
	int				index;
	int				overflow;

	index = 0;
	result = 0;
	sign_value = 1;
	while (check_spaces(str[index]))
		index++;
	if (str[index] == '-')
		sign_value = -1;
	if (str[index] == '+' || str[index] == '-')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		overflow = check_overflow(result, (str[index] - '0'), sign_value);
		if (overflow != 1)
			return (overflow);
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	return (result * sign_value);
}
