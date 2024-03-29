/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:54:36 by houazzan          #+#    #+#             */
/*   Updated: 2022/03/03 18:46:14 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_wor(char *r_s, char c, size_t size)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (r_s[i] != c && r_s[i] != '\0')
		word++;
	if (r_s[i] != c && r_s[size - 1] == c)
		word++;
	while (r_s[i])
	{
		if ((r_s[i] == c && r_s[i + 1] != c && r_s[i + 1] != '\0'))
		{
			word++;
			r_s[i] = '\0';
		}
		if (r_s[i] == c)
			r_s[i] = '\0';
		i++;
	}
	return (word);
}

char	**ft_print(int n_words, char *r_s, char **split, size_t size)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < size && j < n_words)
	{
		if (r_s[i] != '\0')
		{
			split[j] = ft_strdup(&r_s[i]);
			if (!split[j++])
			{
				while (j >= 0)
					free(split[j--]);
				free(split);
				return (NULL);
			}
			while (r_s[i] != '\0')
				i++;
		}
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*r_s;
	int		n_words;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	r_s = ft_strdup((char *)s);
	if (!r_s)
		return (NULL);
	if ((c == 0 && *r_s) || ft_strchr(s, c) == NULL)
		n_words = 1;
	else
		n_words = ft_wor(r_s, c, size);
	split = (char **)ft_calloc(n_words + 1, sizeof(char *));
	if (split)
		split = ft_print(n_words, r_s, split, size);
	free(r_s);
	return (split);
}
