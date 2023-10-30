/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:14:04 by iris              #+#    #+#             */
/*   Updated: 2023/10/29 21:59:18 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>
#include <cstring>
#include "PhoneBook.hpp"

// std::cin represents the standard input stream (keyboard input)
// std:getline is the function used to read an entire line of text from standard in
// cmd is the string with line of text in which input is stored

// std::endl used for output stream to add new line and flush output buffer


std::string PhoneBook::get_info(std::string info) {
    if (info.compare("") == 0)
        std::cout << "Please add missing information!" << std::endl;
    return (info);
}

Contact    PhoneBook::content(void)
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
}

void    PhoneBook::add(void)
{
    std::string cmd;
    std::getline(std::cin, cmd);
    if (!std::cin)
        exit(0);
    for(int i = 0; i <= 8; i++)
        contacts[i] = content();

}

void    PhoneBook::search()
{
    std::cout << " Index | First Name | Last Name | Nickname" << std::endl;

}