#include <string>
#include "course_day.hpp"
#include "course_type.hpp"


class course
{
public:
	course();
	~course();
	std::string title;
	courseDay day; 
	courseType type; 

	void printCourse();
	// courseType setCourseType(courseType ty);
	// courseDay setCourseDay(courseDay d); 
};