#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
char *ft_strdup(char *dest, char *src)
{
	int	i;

	if (!src)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
	
}

char    *ft_read_and_stash(int fd, char *stash)
{
	char	*buf;
	int		count_char;

	count_char = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(stash, '\n') && count_char != 0)
	{
		count_char = read(fd, buf, BUFFER_SIZE);
		if (count_char == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[count_char] = '\0';
		if (!stash)
			stash = ft_strdup(stash, buf);
		else
			stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return(stash);
}

char    *ft_stash_to_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char    *ft_clean_stash(char *stash)
{
	char	*res;
	int		i;
	int		j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	res = malloc(sizeof(char) * ((ft_strlen(stash) - i) + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (stash[i])
		res[j++] = stash[i++];
	res[j++] = '\0';
	return (res);
}

char    *get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	stash = ft_read_and_stash(fd, stash);
	line = ft_stash_to_line(stash);
	stash = ft_clean_stash(stash);
	if (line[0] == '\0')
	{
		free(stash);
		stash = NULL;
		free(line);
		return(NULL);
	}
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*res;

	fd = open("file.txt", O_RDONLY);
	printf("%d\n", fd);
	while ((res = get_next_line(fd)))
	{
		printf("%s", res);
		free(res);
	}
	close(fd);
	return (0);
}