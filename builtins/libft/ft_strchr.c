/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:20:01 by amben-ha          #+#    #+#             */
/*   Updated: 2023/11/29 17:40:43 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	str = (char *)s;
	i = 0;
	if (!str[0] && !c)
		return (0);
	if (!*str)
		return (0);
	while (str[i] != (unsigned char)c)
	{
		if (str[i] == '\0' && c != '\0')
			return (0);
		i++;
	}
	return (1);
}
