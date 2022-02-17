/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-l <arocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:39:26 by arocha-l          #+#    #+#             */
/*   Updated: 2022/01/27 16:54:57 by arocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_keeper(char	*str)
{
	int		i;
	int		n;
	char	*buff;

	i = 0;
	n = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	buff = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!buff)
		return (NULL);
	while (str[++i])
	{
		buff[n] = str[i];
		n++;
	}
	buff[n] = '\0';
	free(str);
	return (buff);
}

char	*ft_cutline(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	if (str[i] == '\n')
	{
		line [i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_reading(int fd, char *str)
{
	char	buff[BUFFER_SIZE + 1];
	int		x;

	x = 1;
	while (x != 0 && !ft_strchr(str, '\n'))
	{
		x = read(fd, buff, BUFFER_SIZE);
		if (x == -1)
			return (NULL);
		buff[x] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*sentence;

	if (fd < 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_reading(fd, str);
	if (!str)
		return (NULL);
	sentence = ft_cutline(str);
	str = ft_keeper(str);
	return (sentence);
}
/*
int	main()
{
	int fd;
	int	fdb;
	int	fdd;
	char *buff;
	
	fd = open("/Users/arocha-l/Documents/curso/gnl/hi.txt", O_RDONLY);
	fdb = open("/Users/arocha-l/Documents/curso/gnl/banana.txt", O_RDONLY);
	fdd = open("/Users/arocha-l/Documents/curso/gnl/dados.txt", O_RDONLY);
	
	printf("hi: %i\nbanana: %i\ndados: %i\n", fd, fdb, fdd);
	
	buff = get_next_line(fd);
	printf("%s%s","Risultato finale: \n", buff);
	buff = get_next_line(fdb);
	printf("\n%s%s","Risultato finale: \n", buff);
	buff = get_next_line(fdd);
	printf("\n%s%s","Risultato finale: \n", buff);
	buff = get_next_line(fd);
	printf("\n%s%s","Risultato finale: \n", buff);
	buff = get_next_line(fdb);
	printf("\n%s%s","Risultato finale: \n", buff);
	buff = get_next_line(fdd);
	printf("\n%s%s","Risultato finale: \n", buff);
}
*/
