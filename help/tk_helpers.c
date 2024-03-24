#include "lumumbash.h"


int	ft_alphanum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	tmp = malloc(size * count);
	if (!tmp)
		return (NULL);
	return (ft_memset(tmp, 0, size * count));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while ((dst + i || src + i) && i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

// char	*ft_strdup(const char *s1)
// {
// 	char *s1cpy;
// 	size_t s1len;

// 	s1len = ft_strlen(s1);
// 	s1cpy = ft_calloc(s1len + 1, sizeof(char));
// 	if (!s1cpy)
// 		return (NULL);
// 	return (ft_memcpy(s1cpy, s1, s1len));
// }
