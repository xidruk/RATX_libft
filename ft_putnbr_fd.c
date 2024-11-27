/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <kbarkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 05:08:57 by kbarkan           #+#    #+#             */
/*   Updated: 2024/11/19 23:00:33 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	print_number(int number, int fd)
{
	int		index;
	char	nh[20];

	index = 0;
	while (number > 0)
	{
		nh[index++] = (number % 10) + '0';
		number /= 10;
	}
	while (index > 0)
	{
		write(fd, &nh[--index], 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	print_number(n, fd);
}
