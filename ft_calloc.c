/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:01:40 by bmakhama          #+#    #+#             */
/*   Updated: 2024/06/02 11:09:44 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned char	*ptr2;

	ptr2 = (unsigned char *) ptr;
	while (len > 0)
	{
		*ptr2 = c;
		ptr2++;
		len--;
	}
	return (ptr);
}

void	ft_bzero(void *ptr, size_t len)
{
	ft_memset(ptr, '\0', len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((size > 0) && (count > 0) && (count > (SIZE_MAX / size)))
		return (0);
	if ((count == INT_MAX) && (size == INT_MAX))
		return (0);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
