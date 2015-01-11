#ifndef INPUTCONTROLLER_HPP
# define INPUTCONTROLLER_HPP

class InputController
{
	public:
		InputController(InputController const & src);
		~InputController( void );
		InputController &	operator=(InputController const & rhs);

		void				readInput(char c);
		int					getInput(void);

	private:
		InputController( void );
		int					_input;
};

#endif /* INPUTCONTROLLER_HPP */
