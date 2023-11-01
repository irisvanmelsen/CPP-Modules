/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:14:04 by iris              #+#    #+#             */
/*   Updated: 2023/11/01 14:47:10 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>
#include <cstring>
#include <cstdio>
#include "PhoneBook.hpp"

// std::cin represents the standard input stream (keyboard input)
// std:getline is the function used to read an entire line of text from standard in
// cmd is the string with line of text in which input is stored

// std::endl used for output stream to add new line and flush output buffer

// this is a pointer to the current instance of the class. You can use it to
// access member variables and functions of the class.

std::string PhoneBook::get_info(std::string info) {
    if (info.compare("") == 0)
        std::cout << "Please add missing information!" << std::endl;
    return (info);
}

void    PhoneBook::add(void)
{
    std::string first_name, last_name, nick_name, phone_number, dark_secret;

    std::cout << "Please enter the following information to add a new contact " << std::endl;
    std::cout << "First Name: ";
    std::getline(std::cin, first_name);
        first_name = get_info(first_name);
        if (first_name.empty())
            return ;
    std::cout << "Last Name: ";
    std::getline(std::cin, last_name);
        last_name = get_info(last_name);
        if (last_name.empty())
            return ;
    std::cout << "Nickname: ";
    std::getline(std::cin, nick_name);
        nick_name = get_info(nick_name);
        if (nick_name.empty())
            return ;
    std::cout << "Phone Number: ";
    std::getline(std::cin, phone_number);
        phone_number = get_info(phone_number);
        if (phone_number.empty())
            return ;
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, dark_secret);
        dark_secret = get_info(dark_secret);
        if (dark_secret.empty())
            return ;
	Contact new_contact(first_name, last_name, nick_name, phone_number, dark_secret);
	contacts[index] = new_contact;
	std::cout << "New Contact Created " << this->index + 1 << std::endl;
	this->index++;
	if (this->index > 7)
		this->index = 0;
}

void PhoneBook::search(void)
{
    std::string index;
    int i;
	int id;

	id = 0;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::cout << "|   Index  | Firstname| Lastname | Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (i = 0; i < 8; i++)
    {
        std::cout << "|" << std::setw(10) << i + 1 << "|";
        contacts[i].print_blocks();
    }
	while (1)
	{
		std::cout << "Enter Index: ";
		std::cin >> index;
		if (!index.empty())
		{
			try
			{
				id = std::stoi(index);
			}
			catch (std::invalid_argument)
			{
				std::cout << "Invalid argument" << std::endl;
				return;
			}
		}
		if (!(id >= 1 && id <= 8))
			std::cout << id << "this is not a valid index" << std::endl;
		else
			break;
	}
    if (id >= 1)
    {
        std::cout << " Index: " << id << std::endl;
        std::cout << " First Name: " << contacts[id - 1].get_firstname() << std::endl;
        std::cout << " Last Name: " << contacts[id - 1].get_lastname() << std::endl;
        std::cout << " Nickname: " << contacts[id - 1].get_nickname() << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Incorrect Index" << std::endl;
    }
}