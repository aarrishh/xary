/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:01:13 by arimanuk          #+#    #+#             */
/*   Updated: 2025/03/10 21:48:32 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	s_len;
	size_t	malloc_len;
	
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start > s_len)
		malloc_len = 0;
	else if (start + len > s_len)
		malloc_len = s_len - start;
	else
		malloc_len = len;
	a = (char *)malloc((malloc_len + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i < malloc_len)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		i;
	int		j;
	int		s_len;

	i = 0;
	j = 0;
	s_len = (ft_strlen(s1) + ft_strlen(s2));
	a = (char *)malloc((s_len + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		a[i + j] = s2[j];
		j++;
	}
	a[i + j] = '\0';
	// free((char *)s1);
	return (a);
}
