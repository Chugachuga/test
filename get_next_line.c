/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:26:09 by gvilmont          #+#    #+#             */
/*   Updated: 2016/03/10 17:38:20 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_txt(char **str, int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*s;

	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	buf[ret] = '\0';
	s = *str;
	*str = ft_strjoin(*str, buf);
	free(s);
	return (ret);
}

static int	ft_putinline(char **str, char **line, char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (*s == '\n')
		i = 1;
	*s = 0;
	*line = ft_strjoin("", *str);
	tmp = ft_strjoin(s + 1, "");
	free(*str);
	*str = tmp;
	if (**line)
		return (1);
	return (i);
}

int			get_next_line(int const fd, char **line)
{
	static char	*str;
	char		*s;
	int			ret;

	if (str == 0)
		str = ft_strdup("");
	if (!line || BUFF_SIZE < 1 || fd < 0)
		return (-1);
	ret = BUFF_SIZE;
	while (1)
	{
		s = str;
		while (*s || ret < BUFF_SIZE)
		{
			if (*s == '\n' || *s == '\0' || *s == -1)
				return (ft_putinline(&str, line, s));
			s++;
		}
		ret = ft_read_txt(&str, fd);
		if (ret == -1)
			return (-1);
	}
}
