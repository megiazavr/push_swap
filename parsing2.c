/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:33:51 by megiazar          #+#    #+#             */
/*   Updated: 2025/12/03 16:23:33 by megiazar         ###   ########.fr       */
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
	int	word_flag;

	count = 0;
	word_flag = 0;
	while (*s)
	{
		if (!ft_isspace(*s) && !word_flag)
		{
			word_flag = 1;
			count++;
		}
		else if (ft_isspace(*s))
			word_flag = 0;
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
	if ((word_count(s) == 0))
		oopsie();
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
