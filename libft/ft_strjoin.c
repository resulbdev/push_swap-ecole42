/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resulbozdemir <resulbozdemir@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:12:46 by rbozdemi          #+#    #+#             */
/*   Updated: 2022/10/20 19:22:36 by resulbozdem      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		x;

	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	x = -1;
	while (s1[++x])
	{
		str[i] = s1[x];
		i++;
	}
	x = -1;
	while (s2[++x])
	{
		str[i] = s2[x];
		i++;
	}
	str[i] = '\0';
	return (str);
}
