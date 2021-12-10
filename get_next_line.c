/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:33:29 by teambersaw        #+#    #+#             */
/*   Updated: 2021/12/10 14:46:19 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str, char *tmp)
{
	free(str);
	free(tmp);
	return (NULL);
}

int	ft_empty(char *str)
{
	while (str && *str)
		if (*(str++) != 127)
			return (0);
	return (1);
}

char	*ft_parse(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] == 127)
		j++;
	while (str[j + i] != '\n' && str[j + i])
		i++;
	if (str[j + i] == '\n')
		i++;
	line = ft_substr(str, j, i);
	if (!line)
		return (NULL);
	printf("%d\n", i);
	i = j + i;
	while (j < i)
	{
		str[j] = 127;
		j++;
	}
	return (line);
}

char	*ft_memory(int fd, char *str)
{
	char	*tmp;
	int		byte;

	byte = 1;
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	*tmp = '\0';
	while (ft_strchr(tmp, '\n') == NULL && byte != 0)
	{
		byte = read(fd, tmp, BUFFER_SIZE);
		if (byte < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[byte] = '\0';
		str = ft_strjoin(str, tmp);
	}
	if (!byte && ft_empty(str))
		if (ft_free(str, tmp) == NULL)
			return (NULL);
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_memory(fd, str);
	if (!str)
		return (NULL);
	line = ft_parse(str);
	return (line);
}

int main(int ac, char **av)
{
    int fd;
    char    *line;

    if (ac != 2)
        return (0);
    fd = open(av[1], O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            return(0);
       // printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}

