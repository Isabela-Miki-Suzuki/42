/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiki-su <imiki-su@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:54:25 by imiki-su          #+#    #+#             */
/*   Updated: 2023/06/06 17:11:08 by imiki-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int pow_base_10_positive_power_max9(int power)
{
    int counter;
    int result;

    counter = 0;
    result = 1;
    while (counter < power)
    {
        result *= 10;
        counter++;
    }
    return (result);
}

void    ft_put_positive_number(int number)
{
    int number_of_digits;
    int digit;

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
        printf("Integer: %d\n", digit);
        write(1, &digit, 1);
        printf("Era para estar duplicado!\n");

        number = number % pow_base_10_positive_power_max9(number_of_digits - 1);
        number_of_digits--;
    }
}

void    ft_putnbr(int nb)
{
    //printf("Entrou no ft_putnbr!\n");
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

void    ft_print_combn_recursive(int n, int initial_number, int prefix)
{
    //printf("Entrou no recursivo!\n");
    //printf("Integer: %d\n", n);
    int new_prefix;
    int counter;
    int number;

    counter = initial_number;
    if (n == 1)
    {
        while (counter < 10 - n + 1)
        {
            //printf("Entrou no caso base!\n");
            number = 10 * prefix + counter;
            ft_putnbr(number);
            write(1, ",", 1);
            write(1, " ", 1);
            counter++;
        }
        ft_putnbr(prefix * 10 + counter);
    }
    while (counter < 10-n+1)
    {
        new_prefix = prefix * 10 + counter;
        ft_print_combn_recursive(n - 1, initial_number + 1, new_prefix);
        counter++;
    }
}

void    ft_print_combn(int n)
{
    ft_print_combn_recursive(n, 0, 0);
}


int main(void)
{
    ft_print_combn(2);
    return (0);
}
