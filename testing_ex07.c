/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_ex07.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiki-su <imiki-su@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:00:28 by imiki-su          #+#    #+#             */
/*   Updated: 2023/06/07 10:48:57 by imiki-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	pow_base_10_positive_power_max9(int power)
{
	int	counter;
	int	result;

	counter = 0;
	result = 1;
	while (counter < power)
	{
		result *= 10;
		counter++;
	}
	return (result);
}

int	ft_find_number_of_digits_of_number(int number)
{
	int	number_of_digits;

	number_of_digits = 0;
	if (number == 0)
	{
		return (1);
	}
	while (number != 0)
	{
		number /= 10;
		number_of_digits++;
	}
	return (number_of_digits);
}

void	ft_put_positive_number(int number)
{
	int	number_of_digits;
	int	digit;

	number_of_digits = ft_find_number_of_digits_of_number(number);
	while (number_of_digits > 0)
	{
		digit = number / pow_base_10_positive_power_max9(number_of_digits - 1);
		ft_putchar(digit + '0');
		number = number % pow_base_10_positive_power_max9(number_of_digits - 1);
		number_of_digits--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		ft_put_positive_number(nb);
	}
}

int	main(void)
{
	ft_putnbr(8962);
	write(1, "\n", 1);
	ft_putnbr(-42);
	write(1, "\n", 1);
	ft_putnbr(8);
	write(1, "\n", 1);
	ft_putnbr(-1);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(-2147483647);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	return (0);
}
