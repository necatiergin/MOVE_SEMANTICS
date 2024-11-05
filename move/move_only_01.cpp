class MoveOnly {
public:
	Moveonly();
	Moveonly(MoveOnly&&);  //move ctor
	MoveOnly& operator=(MoveOnly&&);  //move assignment
	// copy ctor deleted
	// copy assignment deleted
};
