/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:08:20 by arimanuk          #+#    #+#             */
/*   Updated: 2025/01/12 21:58:05 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		a[i] = c;
		i++;
	}
	return (dest);
}
/*#include <stdio.h>
int main()
{
	unsigned char str[51] = "vardannnnnnnnnn";
	printf("%s\n", ft_memset(str, '1', 0));
}*/
