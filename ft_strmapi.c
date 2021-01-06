/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:39:38 by taejkim           #+#    #+#             */
/*   Updated: 2021/01/04 16:08:13 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		size;
	int		i;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		++i;
	}
	ptr[i] = 0;
	return (ptr);
}
