//explicit argument for universal reference params

#include <string>

template <typename T>
void func(T&&);

int main()
{
	using std::string;

	string name{ "necati" };

	//func<string>(name); //error
	func<string>(string{ "ergin" }); //valid
	func<string&>(name); //valid
	//func<string&>(string{ "ergin" }); //error
	//func<string&&>(name); //error
	func<string&&>(string{ "ergin" }); //valid
}
