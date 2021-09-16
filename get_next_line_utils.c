#include "get_next_line.h"

//  Функция strchr() находит первое вхождение 'c' (преобразованное в символ)
//  в строке, на которую указывает s. Завершающий нулевой символ считается
//  частью строки; поэтому, если 'c' равен "\0",
//  функции находят завершающий символ "\0"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if ((char)c == s[i])
		return ((char *)s + i);
	else
		return (NULL);
}

//  Выделяет (с помощью ft_malloc) и возвращает подстроку
//  из строки ’s’.
//  Подстрока начинается с индекса "start’ и имеет
//  максимальный размер "len".

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*src;
	size_t	i;

	str = malloc(len + 1);
	if (!str)
		return (0);
	src = (char *)s + start;
	i = 0;
	while (*src && i < len)
		str[i++] = *src++;
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// функция FT_STRJOIN создает новую string (x) 
// как результат конкатенации (s1) с (s2) 
// и добавление '\0 ' в конец (x).

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
