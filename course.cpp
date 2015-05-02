#include <iostream>
#include "course.hpp"


course::course(std::string t, courseDay d, courseType ty){
	title = t; 
	day = d; 
	type = ty; 
}

void course::printCourse(){
	std::cout << title << "\n"
			  << day << "\n"
			  << ty << "\n"; 
}