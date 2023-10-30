/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:27:22 by iris              #+#    #+#             */
/*   Updated: 2023/10/30 15:18:25 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <cstring>
# include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string dark_secret;
    public:
		Contact(void);
        Contact(Contact &list);
		Contact(std::string &new_first, std::string &new_last, \
		std::string &new_nick, std::string &new_number, std::string &new_secret);
        
		void    print_contacts(void);
};

#endif