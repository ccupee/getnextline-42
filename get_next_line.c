#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

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

char	*ft_free(char *line)
{
	if (!line)
	{
		free (line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];//!
	static int	i;//!
	int			j;
	char		*line1;
	char		*line2;
	long		count;
	
	// if (fd < 0 || BUFFER_SIZE <= 0)
	// 	return (NULL);
	line1 = (char *)malloc(1);
	if (!line1)
		return (NULL);
	line1[0] = '\0';
	if (buf[i] == '\n')
		i++;
	j = 0;
	while (buf[i] == '\0' || buf[i] != '\n')
	{
		//считываем новый буфер
		if (buf[i] == '\0')
		{
			count = read(fd, buf, BUFFER_SIZE);
			if (count <= 0)
			{
				if (line1[0])
					return (line1);
				else
					free (line1);
					return (NULL);
			}
			buf[count] = '\0';
			i = 0;
		}

		///////////////////////////////////////////////////////////
		j = 0;
		while (buf[i + j] && buf[i + j] != '\n')
			j++;
		line2 = (char *)malloc(j + 1 + (buf[i + j] == '\n'));
		if (!line2)
		{
			free (line1);
			return (NULL);
		}
		///////////////////////////////////////////////////////////

		//////////////////////////////////////////////////
		j = 0;
		while (buf[i] && buf[i] != '\n')
			line2[j++] = buf[i++];
		if (buf[i] == '\n')
			line2[j++] = '\n';
		line2[j] = '\0';
		//////////////////////////////////////////////////
		
		
		line1 = ft_strjoin(line1, line2);
	}
	if (line1[0])
		return (line1);
	return (NULL);
}

int main()
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close (fd);
	// fd = 0;
	// char* line;
	// line = get_next_line(fd);
	// while (line)
	// {
	// 	printf("%s", line);
	// 	line = get_next_line(fd);
	// }
	return (0);
}