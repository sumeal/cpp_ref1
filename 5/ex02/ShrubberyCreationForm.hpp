#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

 #include "AForm.hpp"
 #include "iostream"
 #include "fstream"
 #include "string"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm& other);
		void	activity() const;
		std::string getTarget();
	private:
		std::string _target;
		ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);


};

#endif