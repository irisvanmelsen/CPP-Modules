#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm's Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm's Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    _target = obj._target;
    return *this;
}

// ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) {
//     *this = obj;
// }

void 	ShrubberyCreationForm::execute()  const{
	std::fstream _file;
    std::string _filename;
    _filename = _target + "_shrubbery";
	_file.open(_filename.c_str(), std::ios::trunc | std::ios::out);
	if (!_file)
		std::cout << "Error: File not created!" << std::endl;
	else {
		_file << "         &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _";
		_file.close();
	}
}