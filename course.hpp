#ifndef COURSE_H
#define COURSE_H

#include <string>



class course
{	
	public:
		enum CourseDay{MWF, MW, TuTH};
		 enum CourseType {Lecture, Discussion, Lab};
		std::string title;
		CourseDay day; 
		CourseType type;

		course(std::string t, CourseDay d, CourseType ty){
			title = t; 
			day = d; 
			type = ty; 
		};
		~course();
 

	void printCourse();
	// courseType setCourseType(courseType ty);
	// courseDay setCourseDay(courseDay d); 
};

#endif // COURSE_H