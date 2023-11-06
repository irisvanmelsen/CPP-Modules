
#include "sed.hpp"

//  std::ifstream: You can use std::istringstream to read data from a string as if 
// were coming from an input stream. It's often used to parse and extract values from a string

// std::ofstream: It allows you to open and write to files, making it useful for creating,
// writing, and appending data to text files, binary files, and more.

// find(): It's used to search for the first occurrence of a specified substring within the calling string.
// It returns the position (index) of the first character of the found substring or std::string::npos if the substring is not found.

// replace(): It's used to replace a portion of the string with another string or characters.
// It takes the starting position (index) in the string where replacement should begin, 
// the length of the substring to replace, and the string to replace it with.

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Incorrect amount of arguments" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream input_file(filename);
    if (!input_file)
    {
        std::cerr << "Can't open input file!" << std::endl;
        return (1);
    }
    std::ofstream out_file(filename + ".replace");
    if (!out_file)
    {
        std::cout << "Failed to open file " << filename + ".replace" << std::endl;
        return (1);
    }
    std::string line;
    while (std::getline(input_file, line))
    {
        size_t position = 0;
        while ((position = line.find(s1, position)) != std::string::npos)
        {
            line.replace(position, s1.length(), s2);
            position = position + s2.length();
        }
        out_file << line << std::endl;
    }
    input_file.close();
    out_file.close();
    std::cout << "File copied succesfully!" << std::endl;
    return(0);
}