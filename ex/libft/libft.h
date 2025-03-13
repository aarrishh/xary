/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:08:35 by arimanuk          #+#    #+#             */
/*   Updated: 2025/01/15 19:36:54 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h> /*heto khaness*/

int	ft_atoi(const char *str);
int	ft_isalpha(int argument);
int	ft_isalnum(int b);
int	ft_isascii(int c);
int	ft_isdigit(int a);
int	ft_isprint(int c);
int ft_strlen(char* c);
int	ft_tolower(int ch);
int	ft_toupper(int ch);
int ft_strncmp(char *s1,char *s2, int n);
char	*ft_strrchr(const char *str, int c);
char	*ft_strchr(const char *str, int ch);
void	*ft_memcpy(void* dest, const void* src, size_t n);
void *ft_memset(void *dest, int c, size_t n);

#endif
