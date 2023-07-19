/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:29:43 by pmendez-          #+#    #+#             */
/*   Updated: 2023/07/19 20:13:06 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	contador;

	contador = 0;
	while (str[contador] != '\0')
	{
		contador++;
	}
	return (contador);
}

int	checkbase(char *base)
{
	int contador;
	int contador1;
	int	i;

	contador = 0;
	if ((base == NULL) || (ft_strlen(base) == 1))
	{
		return (0);
	}

	while (contador < ft_strlen(base))
	{
		contador1 = contador + 1;
		while (contador1 < ft_strlen(base))
		{
			if (base[contador] == base[contador1])
				return (0);			
		}
	}
	
	while (base[i] == "+" || base[i] == "-")
	   return (0);

	return (1);	

}

void	ft_putnbr_base(int nbr, char *base)
{
	int	num;
	int	res;

	res = 0;
	if (checkbase(base)  == 1)
	{
		num = ft_strlen(base);
		if (nbr < num)
			write(1 , &base[nbr], 1);	
		else
		{
			ft_putnbr_base(nbr/num ,base);
			ft_putnbr_base(nbr%num ,base);
		}
	}
}

int	main(void)
{
	 ft_putnbr_base(12, "0123456789ABCDEF");
}
