#include <stdexcept>
using std::runtime_error;


//Index out of bounds exception should be thrown by fuctions if an array exceeds its boundry.
class ElementNotFoundException :public runtime_error
{
public:
	//The constructor specifies default error message
	ElementNotFoundException::ElementNotFoundException()
		:runtime_error("ElementNotFoundException: The map doesn't contain the specified key"){
	}
};
