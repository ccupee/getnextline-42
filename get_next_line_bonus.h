/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spgibber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:30:54 by spgibber          #+#    #+#             */
/*   Updated: 2021/11/22 13:30:56 by spgibber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 256

typedef struct s_gnl
{
	int		i;
	char	buf[BUFFER_SIZE + 1];
	long	count;
}				t_gnl;

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*make_line(char *buf, char *line2, int *i, char *line1);
int		ft_read(char *buf, int *i, int fd, char *line1);
char	*make_first_line(char *line1);
char	*ft_check(char *line1);
char	*ft_if(char *line1);
void	buffer(char *buf, int *i, long *count);
char	*make_default_line(char *line1);

#endif
