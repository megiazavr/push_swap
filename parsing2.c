/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:33:51 by megiazar          #+#    #+#             */
/*   Updated: 2025/12/02 21:28:48 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
	oopsie();
}

char	*word(const char *s, int start, int end)
{
	int		len;
	char	*word;
	int		i;

	i = 0;
	len = end - start;
	word = malloc(len + 1);
	if (!word)
		oopsie();
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

int	word_count(const char *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!ft_isspace(*s) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (ft_isspace(*s))
			in_word = 0;
		s++;
	}
	return (count);
}

char	**split(char *s)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	i = 0;
	k = 0;
	arr = malloc((word_count(s) + 1) * sizeof(char *));
	if (!arr)
		oopsie();
	while (s[i])
	{
		while (ft_isspace((unsigned char)s[i]))
			i++;
		j = i;
		while (s[i] && !ft_isspace((unsigned char)s[i]))
			i++;
		if (i > j)
			arr[k++] = word(s, j, i);
	}
	arr[k] = NULL;
	return (arr);
}

char	**parse_args_part(int argc, char *argv[])
{
	char	*joined;
	char	**tokens;

	if (argc > 2)
		joined = list(argc, argv, 0);
	else
		joined = argv[1];
	tokens = split(joined);
	if (argc > 2)
		free(joined);
	return (tokens);
}
