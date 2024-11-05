#include <utility>

class MoveOnly {
public:
	MoveOnly();
	MoveOnly(const MoveOnly&) = delete;
	MoveOnly& operator=(const MoveOnly&) = delete;

	MoveOnly(MoveOnly&&);  
	MoveOnly& operator=(MoveOnly&&);    
	//...	
};

int main()
{
	MoveOnly m1;

	//MoveOnly m2 = m1; //error - copy ctor deleted
	MoveOnly m3 = std::move(m1); //valid
	//m1 = m3;  //error - copy assignmentdeleted
	m1 = std::move(m1);  //valid
}
