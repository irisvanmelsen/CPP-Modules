/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:14:04 by iris              #+#    #+#             */
/*   Updated: 2023/11/02 10:46:45 by iris             ###   ########.fr       */
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

bool	is_phone_numeric(std::string &phone_number)
{
	int i;

	i = 0;
	while (i < (int)phone_number.length())
	{
		if (std::isdigit((int)phone_number[i]) == false)
		{
			std::cout << "Please add a valid phone number" << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

std::string	PhoneBook::enter_entry(std::string info, int i)
{
	std::string entry;
	int count;
	int allspaces;
	int	j;
	
	count = 0;
	j = 0;
	while (1)
	{
		allspaces = 0;
		count = 0;
		std::cout << info;
		std::getline(std::cin, entry);
		entry = get_info(entry);
		while (entry[j])
		{
			if (isspace(entry[i]) != 0)
				count++;
			j++;
		}
		if (count == (int) entry.length())
		{
			std::cout << "Please enter alphabetic characters" << std::endl;
			allspaces++;
		}
		if (!entry.empty() && i < 1 && allspaces == 0)
			return(entry);
		if (i > 0 && allspaces == 0)
		{
			if (is_phone_numeric(entry) == true)
				return (entry);
		}
	}
}


void    PhoneBook::add(void)
{
    std::string first_name, last_name, nick_name, phone_number, dark_secret;

    std::cout << "Please enter the following information to add a new contact " << std::endl;
    first_name = enter_entry("First Name: ", 0);
	last_name = enter_entry("Last Name: ", 0);
	nick_name = enter_entry("Nickname: ", 0);
	phone_number = enter_entry("Phone Number: ", 1);
	dark_secret = enter_entry("Darkest Secret: ", 0);
	Contact new_contact(first_name, last_name, nick_name, phone_number, dark_secret);
	contacts[index] = new_contact;
	std::cout << "New Contact Created " << this->index + 1 << std::endl;
	this->index++;
	if (this->index > 7)
		this->index = 0;
}

void PhoneBook::search(int count)
{
    std::string index;
    int i;
	int id;

	id = 0;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::cout << "|   Index  | Firstname| Lastname | Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (i = 0; i < count; i++)
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
			catch (std::exception)
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
        std::cout << "Index: " << id << std::endl;
        std::cout << "First Name: " << contacts[id - 1].get_firstname() << std::endl;
        std::cout << "Last Name: " << contacts[id - 1].get_lastname() << std::endl;
        std::cout << "Nickname: " << contacts[id - 1].get_nickname() << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Incorrect Index" << std::endl;
    }
}