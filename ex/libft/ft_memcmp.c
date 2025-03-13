/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:07:37 by arimanuk          #+#    #+#             */
/*   Updated: 2025/01/15 19:37:08 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *src, const void *dest, size_t n)
{
    size_t          i;
    unsigned char   *a;

    i = 0;
    a = (unsigned char *)src;
    while (i < n)
    {
        if (a[i] == ((unsigned char *)dest)[i])
            i++;
        else
            return (a[i] - ((unsigned char *)dest)[i]);
    }
    return (a[i] - ((unsigned char *)dest)[i]);
}

int main()
{
    char a[7] = "Arishik";
    char b[7] = "Arishik";
    printf("mery->%d\n", ft_memcmp(a, b, 9));
    printf("dzery->%d\n", memcmp(a, b, 9));
}