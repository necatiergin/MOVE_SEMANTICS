class MoveOnly {
public:
	MoveOnly();
	MoveOnly(MoveOnly&&);  //move ctor
	MoveOnly& operator=(MoveOnly&&);  //move assignment
	// copy ctor deleted
	// copy assignment deleted
};
