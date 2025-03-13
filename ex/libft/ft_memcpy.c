/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:12:00 by arimanuk          #+#    #+#             */
/*   Updated: 2025/01/13 21:39:16 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*a;
	const unsigned char		*b;

	i = 0;
	a = (unsigned char *)dest;
	b = (const unsigned char *) src;
	if (a == NULL || b == NULL)
		return (NULL);
	while (b[i] && i < n)
	{
		a[i] = b[i];
		i++;
	}
	if (b[i] == '\0')
		a[i] = '\0';
	return (dest);
}
/*int main()
{
	//char  *aa = NULL;
	char aa[] = "Vardan";
	const char bb[] = "Ari\0sh";

	printf("%s\n", ft_memcpy(aa, bb, sizeof(bb)));
	printf("dzery %s", memcpy(aa, bb, sizeof(bb)));
}*/
