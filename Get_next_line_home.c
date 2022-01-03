/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:20:32 by teambersaw        #+#    #+#             */
/*   Updated: 2022/01/03 19:04:00 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char  *str)
{
    int i;

    i = 0;
    if (str)
    {
        while (str[i])
            i++;
    }
    return (i);
}

void    ft_newcpy(char  *new, char  *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
}

char    *ft_memcpy(char *str, char  *line)
{
    char    *new;
    int     len_line;
    int     len_str;

    len_line = ft_strlen(line);
    len_str = ft_strlen(str);
    new = malloc(sizeof(char) * ((len_str - len_line) + 1));
    if (!new)
        return (NULL);
    ft_newcpy(new, str + len_line);
    free(str);
    return (new);
}

char    *ft_parse(char  *str)
{
    char    *line;
    int     i;
    int     j;

    j = -1;
    i = 0;
    while (str[i] != '\n' && str[i])
        i++;
    if (str[i] == '\n')
        i++;
    line = malloc(sizeof(char) * (i + 1));
    if (!line)
        return (NULL);
    while (++j < i)
        line[j] = str[j];
    line[j] = '\0';
    return (line);
}

char    *ft_strjoin(char *str, char *tmp)
{
    char    *tab;
    int     i;
    int     j;

    i = -1;
    j = 0;
    tab = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(tmp) + 1));
    if (!tab)
        return (NULL);
    if (str)
        while (str[++i])
            tab[j++] = str[i];
    i = -1;
    if (tmp)
        while (tmp[++i])
            tab[j++] = tmp[i];
    tab[j] = '\0'; 
    free(str);
    return (tab);
}

int ft_strchr(char  *tmp, char c)
{
    int i;

    i = 0;
    if (tmp)
    {
        while(tmp[i])
        {
            if (tmp[i] == c)
                return (1);
            i++;
        }
    }
    return (0);
}

char    *ft_memory(char *str, int fd)
{
    char    *tmp;
    int     byte;

    byte = 1;
    tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!tmp)
        return (NULL);
    *tmp = '\0';
    while (ft_strchr(tmp, '\n') == 0 && byte != 0)
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
    if (!*str && !byte)
    {
        free(str);
        free(tmp);
        return (NULL);
    }
    free(tmp);
    return(str);
}

char    *get_next_line(int fd)
{
    static char     *str;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = ft_memory(str, fd);
    if (!str)
        return (NULL);
    line = ft_parse(str);
    str = ft_memcpy(str, line);
    return (line);    
}
