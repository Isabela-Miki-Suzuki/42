#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puttriple(char c1, char c2, char c3)
{
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
}

void	ft_put2bitnumber(int i)
{
	char	d;
	char	u;

	d = i / 10 + '0';
	u = i % 10 + '0';
	write(1, &d, 1);
	write(1, &u, 1);
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


void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		ft_putchar(c);
		c++;
	}
}

void	ft_print_reverse_alphabet_deprec(void)
{
	char	c;

	for (c = 'z'; c >= 'a'; c--)
	{
		write(1, &c, 1);
	}
}

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c >= 'a')
	{
		ft_putchar(c);
		c--;
	}
}

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		ft_putchar(c);
		c++;
	}
}

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		ft_putchar('N');
	}
	else
	{
		ft_putchar('P');
	}
}

void	ft_print_comb(void)
{
	char	c;
	char	d;
	char	u;

	c = '0';
	while (c <= '7')
	{
		d = c + 1;
		while (d <= '8')
		{
			u = d + 1;
			while (u <= '9')
			{
				if (!(c == '0' && d == '1' && u == '2'))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				ft_puttriple(c, d, u);
				u++;
			}
			d++;
		}
		c++;
	}
}

void	ft_print_comb2(void)
{
	int	int1;
	int	int2;

	int1 = 0;
	while (int1 < 99)
	{
		int2 = int1 + 1;
		while (int2 < 100)
		{
			if (!(int1 == 0 && int2 == 1))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			ft_put2bitnumber(int1);
			ft_putchar(' ');
			ft_put2bitnumber(int2);
			int2++;
		}
		int1++;
	}
}

int	main(void)
{
	ft_print_alphabet();
	write(1, "\n", 1);
	ft_print_reverse_alphabet();
	write(1, "\n", 1);
	ft_print_numbers();
	write(1, "\n", 1);
	ft_is_negative(-2147483647);
	write(1, "\n", 1);
	ft_print_comb();
	write(1, "\n", 1);
	ft_print_comb2();
	write(1, "\n", 1);
	ft_put2bitnumber(ft_find_number_of_digits_of_number(-2147483647));
	//ft_putnbr(-2147483647);
	write(1, "\n", 1);
	printf("%d\n", pow_base_10_positive_power_max9(9));
	write(1, "\n", 1);
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
