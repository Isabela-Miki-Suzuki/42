/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_ex08.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiki-su <imiki-su@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:54:25 by imiki-su          #+#    #+#             */
/*   Updated: 2023/06/07 11:02:54 by imiki-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

void	ft_put_positive_number(int number)
{
	int	number_of_digits;
	int	digit;

	number_of_digits = 0;
	if (number == 0)
	{
		number_of_digits = 1;
	}
	while (number != 0)
	{
		number /= 10;
		number_of_digits++;
	}
	while (number_of_digits > 0)
	{
		digit = number / pow_base_10_positive_power_max9(number_of_digits - 1);
		write(1, &digit, 1);
		number = number % pow_base_10_positive_power_max9(number_of_digits - 1);
		number_of_digits--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else
	{
		ft_put_positive_number(nb);
	}
}

void	ft_print_combn_recursive(int n, int initial_number, int prefix)
{
	int	new_prefix;
	int	counter;
	int	number;

	counter = initial_number;
	if (n == 1)
	{
		printf("counter: %d\n", counter);
		printf("n: %d\n", n);
		while (counter < n + 1)
		{
			number = 10 * prefix + counter;
			printf("deveria printar o num!\n");
			printf("number: %d\n", number);
			ft_putnbr(number);
			write(1, ",", 1);
			write(1, " ", 1);
			counter++;
		}
		ft_putnbr(prefix * 10 + counter);
	}
	while (counter < n)
	{
		new_prefix = prefix * 10 + counter;
		ft_print_combn_recursive(n - 1, initial_number + 1, new_prefix);
		counter++;
	}
}

void	ft_print_combn(int n)
{
	ft_print_combn_recursive(n, 0, 0);
}

int	main(void)
{
	ft_print_combn(2);
	write(1, "\n", 1);
	ft_print_combn(1);
	write(1, "\n", 1);
	ft_print_combn(10);
	write(1, "\n", 1);
	ft_print_combn(5);
	write(1, "\n", 1);
	ft_print_combn(3);
}