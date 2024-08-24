/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 09:30:38 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/11 23:06:16 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*ft_strjoin_(char const *s1, char const *s2);
char		*ft_substr_(char const *s, unsigned int start, size_t len);
char		*ft_strdup_(char *s);
size_t		ft_strlen_(const char *str);
char		*get_next_line(int fd);

#endif
