/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:33:52 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/19 14:39:26 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10

# endif

int		better_strlen(char *str);
char	*get_next_line(int fd);
int		check_for_nl(char *str);
void	update_buffer(char *buffer, int nlpos);
char	*update_line(char *s1, char *s2, int len);
char	*read_line(char *buffer, int fd, char *line);

#endif