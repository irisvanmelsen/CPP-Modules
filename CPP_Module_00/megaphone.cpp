/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:24:02 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/10/17 17:25:28 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>
#include <cstring>

// iostream is used to tell the compiler to copy the code from the iostream
// file and paste it in our source file. Allows stdin and stdout operations
// such sa writing

// std::cout identifies the standard console output device
// << indicates that what follows is inserted into std::cout

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++){
		size_t length = std::strlen(argv[i]);
		for (size_t j = 0; j < length; j++){
            	argv[i][j] = std::toupper(argv[i][j]);
		}
		std::cout << argv[i];
	}
	return 0;
}