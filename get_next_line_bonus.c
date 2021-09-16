#include "get_next_line_bonus.h"

static char	*ft_ending(int fd, char *line, char **text)
{
	int		i;
	int		j;
	char	*tmp;

	if (!text[fd])
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	free(line);
	if (!ft_strchr(text[fd], '\n'))
	{
		line = ft_substr(text[fd], 0, ft_strlen(text[fd]));
		free(text[fd]);
		text[fd] = NULL;
		return (line);
	}
	i = ft_strlen(text[fd]);
	j = ft_strlen(ft_strchr(text[fd], '\n'));
	line = ft_substr(text[fd], 0, i - j + 1);
	tmp = text[fd];
	text[fd] = ft_substr(ft_strchr(text[fd], '\n'), 1, j - 1);
	free(tmp);
	return (line);
}

static void	ft_bufferization(int fd, char *buff, char **text)
{
	int		i;
	char	*tmp;

	if (!text[fd] || !ft_strchr(text[fd], '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		while (i > 0)
		{
			buff[i] = '\0';
			if (!text[fd])
				text[fd] = ft_substr(buff, 0, i);
			else
			{
				tmp = text[fd];
				text[fd] = ft_strjoin(text[fd], buff);
				free(tmp);
			}
			if (ft_strchr(buff, '\n'))
				break ;
			i = read(fd, buff, BUFFER_SIZE);
		}
	}
	free(buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*text[OPEN_MAX];

	buff = malloc(BUFFER_SIZE + 1);
	line = malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE < 1 || fd < 0 || !line || !buff
		|| read(fd, buff, 0) == -1)
	{
		free(line);
		free(buff);
		line = NULL;
		return (NULL);
	}
	ft_bufferization(fd, buff, text);
	return (ft_ending(fd, line, text));
}
