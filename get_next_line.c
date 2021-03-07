/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu <ftadeu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:44:13 by ftadeu            #+#    #+#             */
/*   Updated: 2021/03/07 15:07:36 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

static void		ft_strdel(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
}

static int		return_line(int rd, char ** heap, char **line)
{
	int		i;
	char	*tmp;
	
	i = 0;
	if (rd < 0)
		return (-1);
    else if (rd == 0 && *heap[0] == '\0')
    {
        *line = ft_strdup(STR_EMPTY);
        ft_strdel(heap);
        return (0);
    }
    while ((*heap)[i] != LBREAK && (*heap)[i] != '\0')
        i++;
    *line = ft_substr(*heap, 0, i);
    if ((*heap)[i] == LBREAK)
    {
        tmp = ft_strdup(*heap + i + 1);
        free(*heap);
        *heap = tmp;
        return (1);
    }
    ft_strdel(heap);
    return (0);
}

int				get_next_line(int fd, char **line)
{
    int         rd;
    char        *tmp;
    char        *buffer;
    static char *heap[OPEN_MAX];

    if ((fd < 0) || !line || BUFFER_SIZE < 1 || (read(fd, NULL, 0) < 0))
        return (-1);
    if (!(heap[fd]))
    {
        if (!(heap[fd] = ft_strdup(STR_EMPTY)))
            return (-1);
    }
    if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer))))
        return (-1);
    while ((rd = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[rd] = '\0';
        tmp = ft_strjoin(heap[fd], buffer);
        ft_strdel(&heap[fd]);
        heap[fd] = tmp;
        if (ft_strchr(buffer, LBREAK))
            break;
    }
    free(buffer);
    return (return_line(rd, &(heap[fd]), line));
}
