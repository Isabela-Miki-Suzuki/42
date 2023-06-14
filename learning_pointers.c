/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiki-su <imiki-su@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:30:06 by imiki-su          #+#    #+#             */
/*   Updated: 2023/06/07 17:07:25 by imiki-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

void	ft_ultimate_ft(int	*********nbr)
{
	*********nbr = 42;
}

void	ft_swap(int *a, int *b)
{
	int	auxiliar;

	auxiliar = *a;
	*a = *b;
	*b = auxiliar;
}

void	testing_ex00(void)
{
	int	a;
	int	*ptr;

	a = 498;
	ptr = &a;
	printf("a before ft_ft: %d\n", a);
	ft_ft(ptr);
	printf("a after ft_ft: %d\n", a);
}

void	testing_ex01(void)
{
	int	a;
	int	*ptr1;
	int	**ptr2;
	int	***ptr3;
	int	****ptr4;
	int	*****ptr5;
	int	******ptr6;
	int	*******ptr7;
	int	********ptr8;
	int	*********ptr9;

	a = 5;
	printf("a before ft_ultimate_ft: %d\n", a);
	ptr1 = &a;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;
	ft_ultimate_ft(ptr9);
	printf("a after ft_ultimate_ft: %d\n", a);
}

void	testing_ex02(void)
{
	int a = 1;
	int b = 42;
	int	*ptr1;
	int *ptr2;

	ptr1 = &a;
	ptr2 = &b;
	printf("a before ft_swap: %d\n", a);
	printf("b before ft_swap: %d\n", b);
	ft_swap(ptr2, ptr1);
	printf("a after ft_swap: %d\n", a);
	printf("b after ft_swap: %d\n", b);
}

int	main(void)
{
	testing_ex00();
	testing_ex01();
	testing_ex02();
	return (0);
}
