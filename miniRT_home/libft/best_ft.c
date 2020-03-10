//atoi
int	ft_atoi(const char *str)
{
	int				i;
	int				ret;
	unsigned long	result;

	i = 0;
	ret = 1;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ret = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)result * ret);
}

//bzero
void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && s)
	{
		((char*)s)[i] = 0;
		i++;
	}
}

//calloc
void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;
	size_t	i;

	i = 0;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(memory = malloc(count * size)))
		return (NULL);
	ft_bzero(memory, size * count);
	return (memory);
}

//memccpy
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!src)
		return (dest);
	if (!dest)
		return (NULL);
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
		if (((unsigned char*)src)[i - 1] == (unsigned char)c)
			return (&dest[i]);
	}
	return (NULL);
}

//memcpy
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	if (!src)
		return (dest);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < n && (dest || src))
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return (dest);
}

//memmove
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*t_src;
	char			*t_dest;
	size_t			i;

	if (!dest || !src)
		return (NULL);
	t_src = (char*)src;
	t_dest = (char*)dest;
	if (t_dest > t_src)
	{
		i = n;
		while (i > 0)
		{
			t_dest[i - 1] = t_src[i - 1];
			i--;
		}
	}
	else if (t_dest < t_src)
		ft_memcpy(t_dest, t_src, n);
	return (dest);
}

//memchr
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	ptr = (unsigned char*)s;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
		i++;
	}
	return (NULL);
}

//memcmp
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *t_s1;
	unsigned char *t_s2;

	t_s1 = (unsigned char*)s1;
	t_s2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	if (s1 && !s2)
		return (*t_s1);
	if (s2 && !s1)
		return (*t_s2 * -1);
	while (n > 1 && *t_s1 == *t_s2)
	{
		n--;
		t_s1++;
		t_s2++;
	}
	return (*t_s1 - *t_s2);
}

//memset
void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (b && i < len)
	{
		((unsigned char*)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

//strchr
char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return ((char*)&s[i]);
	return (NULL);
}

//strdup
char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0' && s1)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

//strncmp
int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	if (s1 && !s2)
		return (*s1);
	if (s2 && !s1)
		return (*s2 * -1);
	while (i < n - 1 &&
	((unsigned char*)s1)[i] == ((unsigned char*)s2)[i] && s1[i] && s2[i])
		i++;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}

//strnstr
static int	is_here(size_t i, size_t len, const char *hay, const char *needle)
{
	size_t j;

	j = 0;
	while (hay[i] == needle[j] && needle[j] && i < len)
	{
		i++;
		j++;
	}
	if (!(needle[j]))
		return (1);
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (!haystack && !needle)
		return (NULL);
	if (*needle == '\0')
		return ((char*)haystack);
	if (needle[0] == '\0' && needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		if (is_here(i, len, haystack, needle))
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}

//strrchr
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			ret = (char*)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		ret = (char*)&s[i];
	return (ret);
}