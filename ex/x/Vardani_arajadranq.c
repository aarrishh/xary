/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vardani_arajadranq.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:36:23 by arimanuk          #+#    #+#             */
/*   Updated: 2024/11/07 19:19:36 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include<stdio.h>
int main(int argc, char **argv)
{
	int i;
	int j;
	int len;

	i = 1;
	len = 0;
	if (argc == 2)
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				j++;
				len++;
			}
			j = 0;
			while (j < len / 2)
			{
				if(argv[i][j] == argv[i][len - 1 - j])
					j++;
				else
					break ;
			}
			if (j >= len / 2)
			{
				j = 0;
				while (argv[i][j])
					write(1, &argv[i][j++], 1);
			}
			i++;
		}
	}
	write(1,"\n",1);
}
