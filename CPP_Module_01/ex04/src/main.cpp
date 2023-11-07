
#include "sed.hpp"

//  std::ifstream: You can use std::istringstream to read data from a string as if 
// were coming from an input stream. It's often used to parse and extract values from a string

// std::ofstream: It allows you to open and write to files, making it useful for creating,
// writing, and appending data to text files, binary files, and more.

// find(): It's used to search for the first occurrence of a specified substring within the calling string.
// It returns the position (index) of the first character of the found substring or std::string::npos if the substring is not found.

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
        input_file.close();
        return (1);
    }
    std::string line;
while (std::getline(input_file, line))
{
    size_t pos = 0;
    while (true)
    {
        size_t found = line.find(s1, pos); /* returns position of 1st occurence of s1 in line*/
        if (found == std::string::npos)
        {
            out_file << line.substr(pos) << '\n'; /* no more occurences of s1 in line */
            break;
        }
        out_file << line.substr(pos, found - pos) << s2; /* another occurence, append until position then adds s2*/
        pos = found + s1.length(); /* pos is now after occurence of s1 replaced by s2*/
    }
}
    input_file.close();
    out_file.close();
    std::cout << "File copied succesfully!" << std::endl;
    return(0);
}