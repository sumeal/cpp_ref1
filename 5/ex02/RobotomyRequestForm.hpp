#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

 #include "AForm.hpp"
 #include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm& other);
		void	activity() const;
		std::string getTarget();
	private:
		std::string _target;
		RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

};

#endif