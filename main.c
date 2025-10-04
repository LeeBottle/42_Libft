#include <stdio.h>
#include <stdlib.h>

static int	str_in_charset(char *str, char c)
{
	if (*str == c)
		return (1);
	return (0);
}

static int	txt_size(char *str, char c)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		while (str_in_charset(str, c) == 1)
			str++;
		if (*str == '\0')
			break ;
		while (*str != '\0' && str_in_charset(str, c) == 0)
			str++;
		count++;
	}
	return (count);
}

static void	txt_len(char *str, char c, char **arr, int size)
{
	int	arr_loc;
	int	arr_size;

	arr_loc = 0;
	while (arr_loc < size && *str != '\0')
	{
		arr_size = 0;
		while (str_in_charset(str, c) == 1)
			str++;
		while (*str != '\0' && str_in_charset(str++, c) == 0)
			arr_size++;
		if (arr_size == 0)
			break ;
		arr[arr_loc] = (char *)malloc(sizeof(char) * (arr_size + 1));
		if (arr[arr_loc] == NULL)
		{
			while (arr_loc-- > 0)
				free(arr[arr_loc]);
			free(arr);
			return ;
		}
		arr_loc++;
	}
	arr[arr_loc] = NULL;
}

static void	txt_input(char *str, char c, char **arr, int size)
{
	int	arr_1st_di;
	int	arr_2nd_di;

	arr_1st_di = 0;
	while (arr_1st_di < size)
	{
		arr_2nd_di = 0;
		while (str_in_charset(str, c) == 1)
			str++;
		while (*str != '\0' && str_in_charset(str, c) == 0)
		{
			arr[arr_1st_di][arr_2nd_di] = *str;
			arr_2nd_di++;
			str++;
		}
		arr[arr_1st_di][arr_2nd_di] = '\0';
		arr_1st_di++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**arr;
	int		i;

	if (s == NULL)
		return (NULL);
	size = txt_size((char *)s, c);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (arr == NULL)
		return (NULL);
	txt_len((char *)s, c, arr, size);
	i = 0;
	while (i < size)
	{
		if (arr[i] == NULL)
		{
			while (i > 0)
				free(arr[i--]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	txt_input((char *)s, c, arr, size);
	return (arr);
}
void print_and_free(char **result)
{
    if (!result)
    {
        printf("NULL returned from ft_split\n");
        return;
    }
    
    int i = 0;
    while (result[i])
    {
        printf("result[%d]: %s\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);
}

int main()
{
    // Test case 1: Basic string split
    printf("Test 1: Basic split\n");
    char **res1 = ft_split("Hello World! This is a test.", ' ');
    print_and_free(res1);

    // Test case 2: String with multiple delimiters in a row
    printf("\nTest 2: Multiple consecutive delimiters\n");
    char **res2 = ft_split("Hello,,World!!This,is,a,test", ',');
    print_and_free(res2);

    // Test case 3: String that starts with delimiters
    printf("\nTest 3: Leading delimiters\n");
    char **res3 = ft_split(",,Hello,World", ',');
    print_and_free(res3);

    // Test case 4: String that ends with delimiters
    printf("\nTest 4: Trailing delimiters\n");
    char **res4 = ft_split("Hello,World,,", ',');
    print_and_free(res4);

    // Test case 5: Empty string
    printf("\nTest 5: Empty string\n");
    char **res5 = ft_split("", ',');
    print_and_free(res5);

    // Test case 6: String with only delimiters
    printf("\nTest 6: Only delimiters\n");
    char **res6 = ft_split(",,,", ',');
    print_and_free(res6);

    // Test case 7: String with no delimiters
    printf("\nTest 7: No delimiters\n");
    char **res7 = ft_split("HelloWorld", ',');
    print_and_free(res7);

    // Test case 8: NULL input
    printf("\nTest 8: NULL input\n");
    char **res8 = ft_split(NULL, ',');
    print_and_free(res8);

    // Test case 9: Char is NULL
    printf("\nTest 9: Char is NULL\n");
    char **res9 = ft_split("Hello,,World!!This,is,a,test", NULL);
    print_and_free(res9);
    return 0;
}
