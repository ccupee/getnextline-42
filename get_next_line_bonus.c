/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spgibber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:30:42 by spgibber          #+#    #+#             */
/*   Updated: 2021/11/22 13:30:44 by spgibber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		len;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
		newstr[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	free(s1);
	free(s2);
	return (newstr);
}

char	*make_default_line(char *line1)
{
	free(line1);
	line1 = (char *)malloc(2);
	line1[0] = '\n';
	line1[1] = '\0';
	return (line1);
}

char	*make_line(char *buf, char *line2, int *i, char *line1)
{
	int	j;

	j = 0;
	while (buf[(*i) + j] && buf[(*i) + j] != '\n')
		j++;
	line2 = (char *)malloc(j + 1 + (buf[(*i) + j] == '\n'));
	if (!line2)
	{
		free (line1);
		return (NULL);
	}
	j = 0;
	while (buf[*i] && buf[*i] != '\n')
		line2[j++] = buf[(*i)++];
	if (buf[*i] == '\n')
		line2[j++] = '\n';
	line2[j] = '\0';
	return (line2);
}

char	*get_next_line(int fd)
{
	static t_gnl	files[MAX_FD];	
	char			*line1;
	char			*line2;

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	line1 = NULL;
	line1 = make_first_line(line1);
	if (files[fd].buf[files[fd].i] == '\n' && \
			files[fd].buf[++(files[fd].i)] == '\n')
		line1 = make_default_line(line1);
	while (files[fd].buf[files[fd].i] == '\0' || \
			files[fd].buf[files[fd].i] != '\n')
	{
		if (files[fd].buf[files[fd].i] == '\0')
		{
			files[fd].count = read(fd, files[fd].buf, BUFFER_SIZE);
			if (files[fd].count <= 0)
				return (ft_if(line1));
			buffer(files[fd].buf, &(files[fd].i), &(files[fd].count));
		}
		line2 = make_line(files[fd].buf, line2, &(files[fd].i), line1);
		line1 = ft_strjoin(line1, line2);
	}
	return (ft_check(line1));
}
