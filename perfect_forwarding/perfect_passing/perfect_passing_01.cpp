#include <iostream>
#include <string>

void foo(const std::string&) 
{
	std::cout << "foo(const std::string&)\n";
}

void foo(std::string&) 
{
	std::cout << "foo(std::string&)\n";
}

void foo(std::string&&) 
{
	std::cout << "foo(std::string&&)\n";
}


const std::string& ret_const_lvalue_ref(const std::string& str) 
{
	return str;
}

std::string& ret_lvalue_ref(std::string& str) 
{
	return str;
}

std::string&& ret_rvalue_ref(std::string&& str) 
{
	return std::move(str);
}

std::string ret_value(const std::string& str) 
{
	return str;
}

int main()
{
	foo(ret_const_lvalue_ref("tmp"));      // calls foo(const std::string&)

	std::string str{ "lvalue" };
	foo(ret_lvalue_ref(str));             // calls foo(std::string&)

	foo(ret_rvalue_ref("tmp"));           // calls foo(std::string&&)
	foo(ret_rvalue_ref(std::move(str)));  // calls foo(std::string&&)

	foo(ret_value("tmp"));          // calls foo(std::string&&)
}
