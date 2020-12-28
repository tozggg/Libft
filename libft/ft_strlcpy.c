/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:09:04 by taejkim           #+#    #+#             */
/*   Updated: 2020/12/28 15:57:15 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t res;
	size_t i;

	res = ft_strlen(src);
	if (dstsize == 0)
		return (res);
	i = 0;
	while (i < (dstsize - 1))
	{
		if (src[i] == 0)
			break ;
		dst[i] = src[i];
		++i;
	}
	dst[i] = 0;
	return (res);
}
