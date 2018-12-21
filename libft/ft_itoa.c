/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:54:47 by iruban            #+#    #+#             */
/*   Updated: 2018/11/02 14:54:49 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		len(long long  nb)
{
    int		len;

    len = 0;
    if (nb < 0)
    {
        nb = nb * -1;
        len++;
    }
    while (nb > 0)
    {
        nb = nb / 10;
        len++;
    }
    return (len);
}

char	*ft_itoa(long long nb)
{
    char *str;
    long long	int n;
    int		i;

    n = nb;
    i = len(n);
    if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    str[i--] = '\0';
    if (n == 0)
    {
        str[0] = 48;
        return (str);
    }
    if (n < 0)
    {
        str[0] = '-';
        n = n * -1;
    }
    while (n > 0)
    {
        str[i] = 48 + (n % 10);
        n = n / 10;
        i--;
    }
    return (str);
}
