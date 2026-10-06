/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerriyag <eerriyag@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 15:37:57 by eerriyag          #+#    #+#             */
/*   Updated: 2025-02-16 15:37:57 by eerriyag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char value)
{
	write(1, &value, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		write(1, "2147483648", 10);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr);
		return ;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
	return ;
}
