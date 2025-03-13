/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:22:24 by arimanuk          #+#    #+#             */
/*   Updated: 2025/01/16 22:14:13 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t n)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    if (needle == NULL)
        return ((char *)haystack);
    while (j < n && haystack[j] && needle[i])
    {
        if (needle[i] == haystack[j])
        {
            i++;
            j++;
        }
        else
        {
            if (i != 0 && needle[i - 1] == haystack[j - 1])
            {
                i = 0;
                continue ;
            }
            j++;
            i = 0;
        }
    }
    printf("i = %zu\n", i);
    if (needle[i] == '\0' && j < n)
        return ((char*)haystack + j - i);
    printf("j = %zu\n", j);
    // if (needle[i] != '\0' && !haystack[j])
    //     return ((char*)haystack - j);
    return (NULL);
}

int main()
{
    char ari[10] = "babbabnik";
    char ira[7] = "babnik";
    printf("mery->%s\n", ft_strnstr(ari, ira, 11));
    printf("dzery->%s\n", strnstr(ari, ira, 11));
}