#include "push_swap.h"

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

char	**split(const char *s)
{
	int	i;
	int j;
	int	k;
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

int	*parse_args(int argc, char **argv, int *count)
{
	(void)argc;
	char **tokens;
	int  *vals;
	int   i;

	tokens = split(argv[1]);
	areyoudig(tokens);
	*count = 0;
	while (tokens[*count])
		(*count)++;
	vals = malloc(sizeof(int) * (*count));
	if (!vals)
		oopsie();
	i = 0;
	while (i < *count)
	{
		vals[i] = (int)maximini(tokens[i]);
		i++;
	}
	dduupplliiccaattee(vals, *count);
	return (vals);
}
