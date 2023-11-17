/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:05:47 by fbock             #+#    #+#             */
/*   Updated: 2023/11/10 09:14:33 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(unsigned long number, t_pf_data *data)
{
	if (number < 10)
		ft_putchar_pf_fd('0' + number, 1, data);
	else
		ft_putchar_pf_fd('a' + number - 10, 1, data);
}

static void	get_bytes(t_pf_data *data, unsigned long pointer)
{
	if (!pointer || data->error)
		return ;
	get_bytes(data, pointer / 16);
	print_hex(pointer % 16, data);
	data->letter_count++;
}

void	ft_print_ptr(t_pf_data *data)
{
	unsigned long	pointer;

	ft_putstr_pf_fd("0x", 1, data);
	if (data->error)
		return ;
	data->letter_count += 2;
	data->string_position++;
	pointer = (unsigned long)va_arg(*(data->arguments), void *);
	if (!pointer)
	{
		ft_putchar_pf_fd('0', 1, data);
		data->letter_count++;
	}
	else
		get_bytes(data, pointer);
}

/* int main()
{
	int		x;

	x = 42;
	print_ptr(&x);
	return (0);
} */
