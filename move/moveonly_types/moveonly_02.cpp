class MoveOnly {
public:
	MoveOnly();
	MoveOnly(const MoveOnly&) = delete;
	MoveOnly& operator=(const MoveOnly&) = delete;

	MoveOnly(MoveOnly&&);  
	MoveOnly& operator=(MoveOnly&&);    
	//...	
};
