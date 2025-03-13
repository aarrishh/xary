/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:15:52 by arimanuk          #+#    #+#             */
/*   Updated: 2025/01/10 22:40:40 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (c == '\0')
		return ((char*)str + i);
	i--;
	while (i >= 0)
	{
		if (str[i] != c)
			i--;
		else
			return ((char*)str + i);
	}
	return (NULL);
}
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%s\n", ft_strrchr("Vardan", '\0'));
	printf("dzery %s\n", strrchr("Vardan", '\0'));
}
