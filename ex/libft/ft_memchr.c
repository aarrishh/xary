/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:08:11 by arimanuk          #+#    #+#             */
/*   Updated: 2025/01/13 22:38:11 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t 			i;
	const unsigned char	*a;

	i = 0;
	a = (unsigned char *)s;
	while (i < n)
	{
		if (a[i] != (unsigned char)c)
			i++;
		else
			return ((void *)(s + i));
	}
	return (NULL);
}

int main()
{
	char a[7] = "VArdan";
	printf("%s\n", ft_memchr(a, 66, 4));
}
