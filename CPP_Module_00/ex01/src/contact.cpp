/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:59:41 by iris              #+#    #+#             */
/*   Updated: 2023/10/31 13:54:58 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
//std::setw sets the field width to be used on output operations.
//std::right sets the adjustfield format flag for the str stream to right.

void Contact::print_contacts(){
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nick_name << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << dark_secret << std::endl;
}

void print_dot(std::string info)
{
	if (info.length() > 10)

		std::cout << std::setw(9) << std::right << info.substr(0,9) << ".|";
	else
		std::cout << std::setw(10) << std::right << info.substr(0, 10) << "|";
}

void Contact::print_blocks()
{
	print_dot(first_name);
	print_dot(last_name);
	print_dot(nick_name);
    std::cout << std::endl;
}

std::string	Contact::get_firstname()
{
	return (first_name);
}

std::string	Contact::get_lastname()
{
	return (last_name);
}

std::string	Contact::get_nickname()
{
	return (nick_name);
}


//CONSTRUCTORS

Contact::Contact(void)
	:	first_name(),
		last_name(),
		nick_name(),
		phone_number(),
		dark_secret()
{ }

Contact::Contact(std::string &new_first, std::string &new_last, \
				 std::string &new_nick, std::string &new_phone, \
				 std::string &new_secret)
	:	first_name(new_first),
		last_name(new_last),
		nick_name(new_nick),
		phone_number(new_phone),
		dark_secret(new_secret)
{ }