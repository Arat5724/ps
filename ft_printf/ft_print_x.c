/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongble <jeongble@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:50:38 by jeongble          #+#    #+#             */
/*   Updated: 2022/07/11 20:57:31 by jeongble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_x(t_info *info, va_list *ap)
{
	unsigned long	x;
	char			temp[50];
	int				len;

	x = (unsigned long)va_arg(*(ap), unsigned int);
	len = 0;
	if (x)
		dtoh(x, temp, &len, 0);
	else if (!(info->dot && !info->percision))
		temp[len ++] = '0';
	if (x && info->hash)
	{
		len += 2;
		info->percision += 2;
	}
	info->len = len;
	if (!info->dot && !info->left && info->filled == '0')
		info->percision = info->width - !(!(info->sign));
	if (len > info->percision)
		info->percision = len;
	else if (info->sign)
		info->percision += 1;
	return (p_x_return(info, x, temp, 0));
}

int	p_xu(t_info *info, va_list *ap)
{
	unsigned long	x;
	char			temp[50];
	int				len;

	x = (unsigned long)va_arg(*(ap), unsigned int);
	len = 0;
	if (x)
		dtoh(x, temp, &len, 1);
	else if (!(info->dot && !info->percision))
		temp[len ++] = '0';
	if (x && info->hash)
	{
		len += 2;
		info->percision += 2;
	}
	info->len = len;
	if (!info->dot && !info->left && info->filled == '0')
		info->percision = info->width - !(!(info->sign));
	if (len > info->percision)
		info->percision = len;
	else if (info->sign)
		info->percision += 1;
	return (p_x_return(info, x, temp, 1));
}

int	p_x_return(t_info *info, unsigned long x, char *temp, int option)
{
	int		result1;
	int		result2;

	if (info->left)
	{
		result1 = p_x_value(info, x, temp, option);
		result2 = p_x_filled(info);
	}
	else
	{
		result1 = p_x_filled(info);
		result2 = p_x_value(info, x, temp, option);
	}
	if (result1 == -1 || result2 == -1)
		return (-1);
	else
		return (result1 + result2);
}

int	p_x_value(t_info *info, unsigned long x, char *temp, int option)
{
	int			result;
	int			i;
	int			tmp;

	result = 0;
	if (x && info->hash)
		return (p_x_value2(info, temp, option));
	else
	{
		i = -1;
		while (++i < info->percision - info->len)
		{
			tmp = write(1, "0", 1);
			if (tmp == -1)
				return (-1);
			result += tmp;
		}
		tmp = write(1, temp, info->len);
		if (tmp == -1)
			return (-1);
		result += tmp;
	}
	return (result);
}

int	p_x_filled(t_info *info)
{
	int	result;
	int	i;
	int	temp;

	result = 0;
	i = -1;
	while (++i < info->width - info->percision)
	{
		temp = write(1, " ", 1);
		if (temp == -1)
			return (-1);
		result += temp;
	}
	return (result);
}
