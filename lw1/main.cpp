#include <iostream>
#include <memory>

#include "stack_utils.hpp"

int main() {
	try {
		std::unique_ptr<Node<float>> s;
		push(s, -1.f);
		
		std::cout << size(s) << " "; std::cout << top(s) << std::endl;
		push(s, -2.f);
		std::cout << size(s) << " "; std::cout << top(s) << std::endl;
		std::cout << std::endl;

		std::cout << size(s) << " "; std::cout << pop(s) << " "; std::cout << size(s) << std::endl;
		std::cout << size(s) << " "; std::cout << pop(s) << " "; std::cout << size(s) << std::endl;
		std::cout << std::endl;

		push(s, -1.f);
		push(s, -2.f);
		std::cout << size(s) << " "; std::cout << empty(s) << std::endl;
		clear(s);
		std::cout << size(s) << " "; std::cout << empty(s) << std::endl;
	}
	catch (std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
}
