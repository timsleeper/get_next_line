/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu <ftadeu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:44:13 by ftadeu            #+#    #+#             */
/*   Updated: 2021/03/06 19:11:00 by ftadeu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void     ft_strdel(char **str)
{
        if(*str && str)
        {
            free(*str);
            *str == NULL;
        }
}

static int      return_line(int rd, char ** heap, char ** line)
{
    int     i;
    char    *tmp;

    i = 0;
    if(rd < 0)
        return(GNL_FAILURE);
    else if (rd == 0 && *heap[0] == '\0')
    {
        *line = ft_strdup(STR_EMPTY);
        ft_strdel(heap);
        return(GNL_EOF);
    }
    while ((*heap)[i] != LBREAK && (*heap)[i] != '\0')
        i++;
    *line = ft_substr(*heap, 0, i);
    if ((*heap)[i] == LBREAK)
    {
        tmp = ft_strdup(*heap + i + 1);
        free(*heap);
        (*heap) = tmp;
        return (GNL_SUCCESS);
    }
    ft_strdel(heap);
    return(GNL_EOF);
}

int         get_next_line(int fd, char **line)
{
    int         fd;
    char        *tmp;
    char        *buffer;
    static char *heap[OPEN_MAX];

    if (fd < 0 || !line || buffer_size < 1)
        return (GNL_FAILURE);
    if(!(heap[fd]))
    {
        if(!(heap[fd] = ftstrdup(STR_EMPTY)))
            return (GNL_FAILURE);
    }
    if(!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer))))
        return (GNL_FAILURE);
    while ((rd = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[fd] = '\0';
        tmp = ft_strjoin(heap[fd], buffer);
        ft_strdel(&heap[fd]);
        heap[fd] = tmp;
        if(ft_strchr(buffer, LBREAK))
            break;
    }
    free(buffer);
    return (return_line(rd, &(heap[fd]), line));
}