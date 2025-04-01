//the importance of noexcept guarantee

#include <iostream>
#include <string>
#include <vector>

class Student {
public:
	Student(const char* name) : name_{ name } {}
	std::string getName() const
	{
		return name_;
	}

	Student(const Student& other) : name_{ other.name_ }
	{
		std::cout << "COPY " << name_ << '\n';
	}

	//Student(Student&& other) noexcept : name_{ std::move(other.name_) }
	Student(Student&& other) : name_{ std::move(other.name_) }
	{
		std::cout << "MOVE " << name_ << '\n';
	}
private:
	std::string name_;
};

int main()
{
	std::vector<Student> vec{
		"Omer Faruk Yesiltepe",
		"Seyfullah Karamehmetoglu",
		"Muzaffer Karabasan" };

	std::cout << "capacity: " << vec.capacity() << '\n';
	vec.push_back("Aysenur Nazligul Aybakan");
}
