#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

 #include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm& other);
		void	activity() const;
		std::string getTarget();
	private:
		std::string _target;
		PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

};

#endif