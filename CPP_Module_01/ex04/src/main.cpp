
#include "sed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
        std::cout << "Incorrect amount of arguments" << std::endl;
        return (0);
    std::ifstream input_file(argv[1]);
    if (input_file.is_open())
        std::string line;
    input_file.close();
}