#include <iostream>
#include "course.hpp"



void course::printCourse(){
	std::cout << title << "\n"
			  << day << "\n"
			  << ty << "\n"; 
}