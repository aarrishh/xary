/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:02:45 by arimanuk          #+#    #+#             */
/*   Updated: 2024/11/07 18:31:41 by arimanuk         ###   ########.fr       */
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
			j = 0;
			while (argv[i][j])
			{
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				{
					if (argv[i][j] + 13 > 'z')
					{
						argv[i][j] = argv[i][j] - 13;
					}
					else
						argv[i][j] += 13;
				}
				else if (argv[i][j] >= 'A' && argv[i][j] <= 'Z')
				{
					if (argv[i][j] + 13 > 'Z')
						argv[i][j] -= 13;
					else
						argv[i][j] += 13;
				}
				write(1, &argv[i][j], 1);
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
}
