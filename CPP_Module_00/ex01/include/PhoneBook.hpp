/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:53:00 by iris              #+#    #+#             */
/*   Updated: 2023/10/29 21:57:32 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <ctype.h>
# include <cstring>

class PhoneBook
{
    public:
        void    add(void);
        void    search(void);
    private:
        Contact     contacts[8];
        Contact     content(void);      
        std::string get_info(std::string info);
        void        content(void);
};

#endif