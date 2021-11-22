/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spgibber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:06:17 by spgibber          #+#    #+#             */
/*   Updated: 2021/11/20 19:06:19 by spgibber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

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
