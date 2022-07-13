/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:00:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/31 09:26:21 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_itoa_len(int n)
{
	unsigned int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_sub_itoa(unsigned int sign, char *str, unsigned int *i, int *n)
{
	if (sign)
		*(str + (*i)--) = ((*n % 10) * -1) + '0';
	else
		*(str + (*i)--) = (*n % 10) + '0';
	*n /= 10;
}

char	*ft_itoa_printf(int n)
{
	char			*str;
	unsigned int	i;
	unsigned int	sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	str = malloc(sizeof(char) * (ft_itoa_len(n) + 1 + sign));
	str[ft_itoa_len(n) + sign] = '\0';
	i = ft_itoa_len(n) + sign - 1;
	if (n == 0)
		str[i--] = '0';
	while (n)
		ft_sub_itoa(sign, str, &i, &n);
	if (sign)
		str[i] = '-';
	return (str);
}
