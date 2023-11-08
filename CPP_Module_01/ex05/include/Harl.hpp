#ifndef HARL_HPP
#define HARL_HPP

# include <iostream>

// The using keyword is used in C++ to create aliases or define type aliases.
// It allows you to give a new often shorter, name to a data type, a complex type,
// or a function pointer type. 

class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

        using MemberFunctionPtr = void (Harl::*)();
        MemberFunctionPtr levels[4] = {
            &Harl::debug,
            &Harl::info,
            &Harl::warning,
            &Harl::error};

    public:
        void complain(std::string level);
};

#endif  