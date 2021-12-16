#include <stdio.h>
#include "get_next_line.h"
//int	main(int ac, char **av)
//{
//	int	fd;
//	char *line;
//
//	if (ac != 2)
//		return (0);
//	fd = open(av[1], O_RDONLY);
//	while (1)
//	{
//		line = get_next_line(fd);
//		if (!line)
//			return (0);
//		printf("%s", line);
//		free(line);
//	}
//	close(fd);
//	return (0);
//}

//int	main(int ac, char **av)
//{
//	int		fd1;
//	int		fd2;
//	int		i;
//	char	*line1;
//	char	*line2;
//
//	i = 0;
//	line1 = 0;
//	line2 = 0;
//	if (ac != 3)
//		return (0);
//	fd1 = open(av[1], O_RDONLY);
//	fd2 = open(av[2], O_RDONLY);
//	while (++i)
//	{
//		if ((i % 2) == 0)
//			line1 = get_next_line(fd1);
//		else
//			line2 = get_next_line(fd2);
//		if (!line1 && !line2)
//			return (0);
//		if ((i % 2) == 0 && line1)
//		{
//			printf("%s", line1);
//			free(line1);
//		}
//		else if ((i % 2) != 0 && line2)
//		{
//			printf("%s", line2);
//			free(line2);
//		}
//	}
//	close(fd1);
//	close(fd2);
//	return (0);
//}
//