/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:37:04 by mpetrosy          #+#    #+#             */
/*   Updated: 2023/02/26 18:03:33 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; av[i]; ++i)
		{
			for (int j = 0; av[i][j]; ++j)
				std::cout << (char)toupper(av[i][j]);
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}
