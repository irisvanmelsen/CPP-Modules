/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:53:00 by iris              #+#    #+#             */
/*   Updated: 2023/11/01 18:32:21 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <ctype.h>
# include <string>
# include <stdlib.h>

// when a PhoneBook object is created, its index member will be set to 0 by default.

class PhoneBook
{
    public:
		PhoneBook(){
			index = 0;
		}
        void    add(void);
        void    search(int count);   
        std::string get_info(std::string info);
		std::string	enter_entry(std::string info, int i);
    private:
		int			index;
        Contact     contacts[8];
};

#endif