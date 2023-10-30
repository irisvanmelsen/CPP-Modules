/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:59:41 by iris              #+#    #+#             */
/*   Updated: 2023/10/30 18:12:03 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::print_contacts(){
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nick_name << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << dark_secret << std::endl;
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