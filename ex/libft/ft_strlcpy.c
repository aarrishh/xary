/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:49:05 by arimanuk          #+#    #+#             */
/*   Updated: 2025/01/15 22:48:37 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	src_len;

	i = -1;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (n == 0)
		return (src_len);
	if (src_len >= n)
	{
		while (++i < n)
			dst[i] = src[i];
		return (src_len);
	}
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}


int main()
{
    char a[12] = "Arishokkkkk";
    char b[11] = "";
    printf("%lu\n", ft_strlcpy(b, a, 5));
    printf("%lu\n", strlcpy(b, a, 5));
}