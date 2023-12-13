/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:52:47 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/13 19:12:02 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <bsd/string.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

long int	ft_atoi(const char *str);
char		*ft_strcpy(char *dest, const char *src);
char		**ft_split(char *str, char separator);
int			ft_strlen(const char *s);
int			ft_arrlen(char **arr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
int			ft_strchr_sign(const char *s, int c);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strcpy(char *dest, const char *src);


#endif
