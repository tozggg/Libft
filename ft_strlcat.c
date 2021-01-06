/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:58:50 by taejkim           #+#    #+#             */
/*   Updated: 2020/12/27 07:55:15 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t d_len;
	size_t s_len;
	size_t i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	while (src[i] && ((d_len + i + 1) < dstsize))
	{
		dst[d_len + i] = src[i];
		++i;
	}
	dst[d_len + i] = 0;
	if (d_len > dstsize)
		return (s_len + dstsize);
	else
		return (s_len + d_len);
}
