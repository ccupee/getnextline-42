/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spgibber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:05:08 by spgibber          #+#    #+#             */
/*   Updated: 2021/11/20 19:05:10 by spgibber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(char *buf, int *i, int fd, char *line1)
{
	long	count;

	count = read(fd, buf, BUFFER_SIZE);
	if (count <= 0)
	{
		if (line1[0] == '\0')
			return (1);
		else
		{
			free(line1);
			return (-1);
		}
	}
	buf[count] = '\0';
	*i = 0;
	return (1);
}

char	*make_first_line(char *line1)
{
	line1 = (char *)malloc(1);
	if (!line1)
		return (NULL);
	line1[0] = '\0';
	return (line1);
}

char	*ft_check(char *line1)
{
	if (line1[0])
		return (line1);
	return (NULL);
}

char	*ft_if(char *line1)
{
	if (line1[0])
		return (line1);
	else
	{
		free (line1);
		return (NULL);
	}
}

void	buffer(char *buf, int *i, long *count)
{
	buf[*count] = '\0';
	*i = 0;
}
