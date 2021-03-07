/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu <ftadeu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:58:47 by ftadeu            #+#    #+#             */
/*   Updated: 2021/03/06 19:10:59 by ftadeu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define GNL_SUCCESS 1
#define GNL_FAILURE -1
#define GNL_EOF     0

#define LBREAK  '\n'
#define STR_EMPTY ""

// #define OPEN_MAX 16
// #define BUFFER_SIZE 1024

int         get_next_line(int fd, char ** line);
char	    *ft_strdup(const char *s1);
char	    *ft_strchr(const char *s, int c);
char	    *ft_strjoin(char const *s1, char const *s2);
char	    *ft_substr(char const *s, unsigned int start, size_t len);
size_t      ft_strlen(const char *s);

#endif