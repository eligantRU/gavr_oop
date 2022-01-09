#include <iostream>

#include "Stack.hpp"

int main() {
	try {
		Stack<float> s;
		s.push(-1.f);
		std::cout << s.size() << " "; std::cout << s.top() << std::endl;
		s.push(-2.f);
		std::cout << s.size() << " "; std::cout << s.top() << std::endl;
		std::cout << std::endl;

		std::cout << s.size() << " "; std::cout << s.pop() << " "; std::cout << s.size() << std::endl;
		std::cout << s.size() << " "; std::cout << s.pop() << " "; std::cout << s.size() << std::endl;
		std::cout << std::endl;

		s.push(-1.f);
		s.push(-2.f);
		std::cout << s.size() << " "; std::cout << s.empty() << std::endl;
		s.clear();
		std::cout << s.size() << " "; std::cout << s.empty() << std::endl;
	}
	catch (std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
}
