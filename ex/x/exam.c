/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:55:28 by arimanuk          #+#    #+#             */
/*   Updated: 2024/11/07 20:30:30 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	if (argc == 2)
	{
		while (argv[i])
		{
			j = 1;
			while (argv[i][j])
			{
				if (j % 3 == 0)
					argv[i][j] = '5';
				else if (j % 5 == 0)
					argv[i][j] = '3';
				else if (j % 3 == 0 && j % 5 == 0)
					argv[i][j] = '5';
				j++;
			}
			j = 0;
			while (argv[i][j])
				write(1, &argv[i][j++], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
