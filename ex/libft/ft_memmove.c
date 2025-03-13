/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:19:33 by arimanuk          #+#    #+#             */
/*   Updated: 2025/01/14 22:40:09 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t          i;
    unsigned char   *a;

    i = 0;
	a = (unsigned char *)dest;
	if (src > dest)
	{
		printf("%s\n",  "aaaaa");
		while (n > 0)
		{
			a[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
		return (dest);
	}
	else
	{
		printf("%s\n", "bbbbbbb");
		i = 0;
		while (i < n)
		{
			a[i] = ((unsigned char *)src)[i];
			i++;
		}
		return (dest);	
	}
}

int main()
{
    char a[9] = "1234abcd";
    char b[7] = "34abcd";
    printf("%s\n", ft_memmove(b, a, 4));
}