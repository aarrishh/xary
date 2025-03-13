/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:40:19 by arimanuk          #+#    #+#             */
/*   Updated: 2025/03/10 22:25:48 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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


int	nl_exists(char *buffer)
{
	int i;

	i = 0;
	if (buffer == NULL)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*left_over(char *str_join)
{
	int i;

	i = 0;
	while (str_join[i] && str_join[i] != '\n')
		i++;
	return(str_join + i + 1);
}

char	*cur_line(char *str_join)
{
	int i;

	i = 0;
	while (str_join[i] && str_join[i] != '\n')
		i++;
	return (ft_substr(str_join, 0, i + 1));
}


char	*get_next_line(int fd)
{
	char*	buffer = NULL;
	static char*	result;
	int 	count_bytes = 1;
	char	*str_join = NULL;

	while (nl_exists(buffer) == 0 &&  count_bytes != 0)
	{
		printf("fff\n");
		free(buffer);// 
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return (NULL);
		count_bytes = read(fd, buffer, BUFFER_SIZE);
		if (count_bytes == -1)
			return (NULL);
		buffer[count_bytes] = '\0';
		str_join = ft_strjoin(result, buffer);
		// if (result)
		// 	free(result);//vat mitqa
		result = str_join;//leak ka,mincehv es free ara buffer-@/arishs
	}
	if (*result == '\0' && count_bytes == 0)
		return (NULL);
	result = left_over(str_join);
	char *return_str = cur_line(str_join);
	
	free(buffer);
	return (return_str);
}

int main()
{
	int a;
	
	a = open("fiel.txt", O_RDWR);
	char *res = get_next_line(a);
	printf("ya zdzes->%s", res);
	// free(res);
	printf("ya zdzes->%s", get_next_line(a));
	printf("ya zdzes->%s", get_next_line(a));
	// printf("ya zdzes->%s", get_next_line(a));
	// printf("ya zdzes->%s", get_next_line(a));
	system("leaks a.out");
}