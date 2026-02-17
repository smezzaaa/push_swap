/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:22:02 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/02/16 11:51:45 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	tok_len(char const *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static size_t	str_counter(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!(s[i] == 0))
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**free_mat(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	*ft_cpy(const char *str, size_t len, char c)
{
	size_t		i;
	char		*dst;
	size_t		j;

	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (j < len)
				dst[j++] = str[i++];
			dst[j] = '\0';
			return (dst);
		}
		while (str[i] == c)
			i++;
	}
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**arr;

	i = -1;
	j = 0;
	if (s == NULL)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (str_counter(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
		{
			arr[j] = ft_cpy(&s[i], tok_len(&s[i], c), c);
			if (arr[j] == NULL)
				return (free_mat(arr));
			i += tok_len(&s[i], c) - 1;
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}
