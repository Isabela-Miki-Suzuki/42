/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_string_manipulation.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiki-su <imiki-su@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:15:24 by imiki-su          #+#    #+#             */
/*   Updated: 2023/06/15 16:47:28 by imiki-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char* dest, char* src)
{
	char*	ptr;

	ptr = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char*	ptr;

	ptr = dest;
	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	return (ptr);
}

int	ft_str_is_alpha(char *str)
{
	if (*str == '\0')
	{
		return (1);
	}
	while (*str != '\0')
	{
		if ((*str < 'A' || *str > 'Z') && (*str < 'a' || *str > 'z'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	ft_str_is_numeric(char *str)
{
	if (*str == '\0')
	{
		return (1);
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	ft_str_is_lowercase(char *str)
{
	if (*str == '\0')
	{
		return (1);
	}
	while (*str != '\0')
	{
		if (*str < 'a' || *str > 'z')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	ft_str_is_uppercase(char *str)
{
	if (*str == '\0')
	{
		return (1);
	}
	while (*str != '\0')
	{
		if (*str < 'A' || *str > 'Z')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	ft_str_is_printable(char *str)
{
	if (*str == '\0')
	{
		return (1);
	}
	while (*str != '\0')
	{
		if (*str < 32 || *str > 126)
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	main(void)
{
	printf("Testing ft_strcpy\n");
	char	source[] = "Hello, World!";
	char	destination[20];
	ft_strcpy(destination, source);
	printf("Source: %s\n", source);
	printf("Destination: %s\n", destination);
	printf("\n");
	printf("Testing ft_strncpy\n");
	ft_strncpy(destination, source, 5);
	printf("Source: %s\n", source);
	printf("Destination: %s\n", destination);
	printf("\n");
	printf("Testing ft_str_is_alpha\n");
	printf("%d\n", ft_str_is_alpha("Hello"));
	printf("%d\n", ft_str_is_alpha("Hello123"));
	printf("%d\n", ft_str_is_alpha(""));
	printf("\n");
	printf("Testing ft_str_is_numeric\n");
	printf("%d\n", ft_str_is_numeric("12345"));
	printf("%d\n", ft_str_is_numeric("Hello123"));
	printf("%d\n", ft_str_is_numeric(""));
	return (0);
}
