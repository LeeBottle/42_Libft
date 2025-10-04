/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: byeolee <byeolee@student.42gyeongsan.kr	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/09 18:24:32 by byeolee		   #+#	#+#			 */
/*   Updated: 2025/01/09 18:26:04 by byeolee		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static void	input_char(char *str, int n, int len, int check)
{
	if (!str)
		return ;
	if (check == 1)
	{
		str[0] = '-';
		len++;
	}
	str[len] = '\0';
	while (len > check)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

static char	*input_zero(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*input_underflow(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int				len;
	int				mi_pl;
	int				i;
	char			*ptr;

	len = 0;
	mi_pl = 0;
	if (n == 0)
		return (input_zero());
	else if (n == -2147483648)
		return (input_underflow());
	if (n < 0)
	{
		n = -n;
		mi_pl = 1;
	}
	i = n;
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	ptr = (char *)malloc(sizeof(char) * (len + mi_pl + 1));
	input_char(ptr, n, len, mi_pl);
	return (ptr);
}
