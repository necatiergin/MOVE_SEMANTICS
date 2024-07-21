#include <string>
#include <chrono>
#include <iostream>


class PersonClassic {
public:
	PersonClassic(const std::string& name, const std::string& surname)
		: m_name{ name }, m_surname{ surname } {}
private:
	std::string m_name;
	std::string m_surname;
};

class PersonInitMove {
public:
	PersonInitMove(std::string name, std::string surname)
		: m_name{ std::move(name) }, m_surname{ std::move(surname) } {}
private:
	std::string m_name;
	std::string m_surname;
};

class PersonInitOverload {
public:
	PersonInitOverload (const std::string& name, const std::string& surname)
		: first{ name }, last{ surname } {
	}
	PersonInitOverload (const std::string& name, std::string&& surname)
		: first{ name }, last{ std::move(surname) } {
	}
	PersonInitOverload (std::string&& name, const std::string& surname)
		: first{ std::move(name) }, last{ surname } {
	}
	PersonInitOverload (std::string&& name, std::string&& surname)
		: first{ std::move(name) }, last{ std::move(surname) } {
	}
	PersonInitOverload (const char* name, const char* surname)
		: first{ name }, last{ surname } {
	}
	PersonInitOverload (const char* name, const std::string& surname)
		: first{ name }, last{ surname } {
	}
	PersonInitOverload (const char* name, std::string&& surname)
		: first{ name }, last{ std::move(surname) } {
	}
	PersonInitOverload (const std::string& name, const char* surname)
		: first{ name }, last{ surname } {
	}
	PersonInitOverload (std::string&& name, const char* surname)
		: first{ std::move(name) }, last{ surname } {
	}
private:
	std::string first; 
	std::string last; 
};

//using Person = PersonClassic;
//using Person = PersonInitMove;
using Person = PersonInitOverload;

const char *pname	 = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char *psurname = "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy";

std::chrono::nanoseconds measure(int num)
{
	std::chrono::nanoseconds total_duration{};
	for (int i = 0; i < num; ++i) {
		std::string name(100, 'N');
		std::string surname(100, 'S');
		auto start = std::chrono::steady_clock::now();
		Person px{pname, psurname};
		Person p2{name, surname};
		Person p3{ std::move(name), std::move(surname) };
		auto end = std::chrono::steady_clock::now();
		total_duration += end - start;
	}
	return total_duration;
}


constexpr int n = 100'000;

int main()
{
	measure(20); //başlangıç maliyetlerini dikkate almamak için
	
	std::chrono::nanoseconds nanosecond_duration{ measure(n) };
	std::chrono::duration<double, std::milli> millisecond_duration{nanosecond_duration};

	std::cout << "test results for " << n << " iterations "
		<< millisecond_duration.count() << "ms\n";
	std::cout << "3 inits take on average: "
		<< nanosecond_duration.count() / n << "ns\n";
}
