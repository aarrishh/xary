/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:01:13 by arimanuk          #+#    #+#             */
/*   Updated: 2025/03/18 22:19:56 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int j;
	int malloc_len;
	char*	res;

	j = 0;
	i = 0;
	while (str_join[i] && str_join[i] != '\n')
		i++;
	malloc_len = ft_strlen(str_join) - i;
	res = (char *)malloc((malloc_len) * sizeof(char));
	if (!res)
		return (NULL);
	i++;
	while (i < ft_strlen(str_join))
		res[j++] = str_join[i++];
	res[j] = '\0';
	return(res);
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
	static char*	result;
	char*			buffer;
	char*			str_join;
	char*			return_str;
	int 			count_bytes;

	buffer = NULL;
	str_join = NULL;
	count_bytes = 1;
	while (nl_exists(buffer) == 0 && count_bytes != 0)
	{	
		free(buffer);
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
		{
			free(buffer);
			return (NULL);
		}
		count_bytes = read(fd, buffer, BUFFER_SIZE);
		if (count_bytes == -1)
			return (NULL);
		buffer[count_bytes] = '\0';
		str_join = ft_strjoin(result, buffer);
		if (result)
		{
			free(result);
			result = NULL;
		}
		result = str_join;
	}
	if (*result == '\0' && count_bytes == 0)
	{
		free(buffer);
		free(str_join);
		free(result);
		result = NULL;
		return (NULL);
	}
	result = left_over(str_join);
	return_str = cur_line(str_join);
	free(str_join);
	free(buffer);
	return (return_str);
}

int main()
{
	int a;
	a = open("fiel.txt", O_RDWR);
	char *res = get_next_line(a);
	printf("ya zdzes->%s", res);
	free(res);
	char  *res1 =  get_next_line(a);
	char  *res2 =  get_next_line(a);
	char  *res3 =  get_next_line(a);


	printf("ya zdzes->%s", res1);
	printf("ya zdzes->%s",res2);
	printf("ya zdzes->%s",res3);
	// free(result);

	free(res1);
	free(res2);
	free(res3);

	
	// printf("ya zdzes->%s", get_next_line(a));
	// printf("ya zdzes->%s", get_next_line(a));
	// system("leaks gnl");
}