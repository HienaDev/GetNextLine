/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-l <arocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:17:46 by arocha-l          #+#    #+#             */
/*   Updated: 2022/02/09 13:43:50 by arocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_reading(int fd, char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *prefix, char *right);
size_t	ft_strlen(const char *s);
char	*ft_cutline(char *str);
char	*ft_keeper(char	*str);

#endif
