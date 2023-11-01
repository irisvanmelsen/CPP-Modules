/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:49:11 by iris              #+#    #+#             */
/*   Updated: 2023/11/01 17:39:21 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

// ADD: save a new contact
// SEARCH: display a specific contact
// EXIT: program quits and contacts are lost forever

// string literals have type const char* so you can compare them

int main (void) {
    PhoneBook phonebook;
	int	i;
	int	count;
    std::string command;

	i = 0;
	count = 0;
    std::cout << "Would you like to ADD, SEARCH or EXIT?" << std::endl;
    while (1)
    {
        getline(std::cin, command);
		if (command.empty())
			continue;
        if (command == "ADD")
		{
            phonebook.add();
			if (count < 8)
				count++;
		}
        else if (command == "SEARCH")
		{
			if (!count)
			{
				std::cout << "No Contacts in Phonebook!" << std::endl;
			}
			else
            	phonebook.search(count);
		}
        else if (command == "EXIT")
            break;
        else
		{
            std::cout << "Please enter a valid command" << std::endl;
			continue;
		}
    }
    std::cout << "exiting, contacts will be lost forever" << std::endl;
}

