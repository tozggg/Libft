/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:07:02 by taejkim           #+#    #+#             */
/*   Updated: 2020/12/28 13:15:25 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	if (!(ptr = malloc(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		++i;
	}
	ptr[i] = 0;
	return (ptr);
}
