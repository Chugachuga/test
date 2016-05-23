/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:58:25 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/20 19:31:48 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
	int fd;
	int ret;
	int a;
	char *line;

	a = 0;
	if (ac > 1)
	{
		if ((fd = open(av[1], O_RDONLY)) > 0)
		{
			while ((ret = get_next_line(fd, &line)) > 0) 
			{
				ft_putnbr(ret);
				ft_putchar('.');
				ft_putnbr(a);
				ft_putstr(">");
				ft_putstr(line);
				ft_putstr("<");
				ft_putchar('\n');
				a++;
			}
		}
	}
	return (0);
}
