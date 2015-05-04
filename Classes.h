#include <iostream>
#include <vector>
using namespace std;

class Classes {
  
public:
  
  Classes(char quarter[]);			// quarter == file name of schedule txt file to import
  
  void getCoursesOffered( vector<string> &courseCodes);
						// passes the available course codes to an
						// 	empty string vector
						// NOT IMPLEMENTED
  
  void getClassesOffered( vector<int> &classCodes, vector<string> &courseCodes);
						// passes the available class codes and their
						//	corresponding courses to empty vectors
						// NOT IMPLEMENTED
  
//  bool studentEligibility( Student &student, string courseCode);
						// returns true if the given student is eligibile 
						//	for the given class
						// NOT IMPLEMENTED
  
  void get_courses_offered_between_these_hours( int startTime, int endTime, vector<string> &courseCodes);
						// passes courses available between the given times
						//	to an empty string vector
  
  
  void enrollStudent(int classCode);		// increments the enrollment for the given class
						// NOT IMPLEMENTED
  
  
  void printScheduleTerminal();			// prints the entire schedule to the terminal
  
  void printScheduleTxt(char fileName[]);	// prints the entire schedule to the given file name
						// NOT IMPLEMENTED
  
  void printCourseInformationTerm(string courseCode);
						// prints the given course information to the terminal
						// NOT IMPLEMENTED
  
  void printCourseInformationTxt(char fileName[], string cour);	
						// prints the given course information to the given file name
						// NOT IMPLEMENTED
  
  void printClassInformationTerm(int classNumber);
						// prints the given class information to the terminal
						// NOT IMPLEMENTED
  
  void printClassInformationTxt(char fileName[], int classNumber);	
						// prints the given class information to the given file name
						// NOT IMPLEMENTED

  
  
  
private:
  
  struct classes {
    int class_code;
    string type;		// Lecture / Discussion / Lab
    int units;			// number of units for this class
    
    bool monday;		// 1 == there is class on Monday
    bool tuesday;
    bool wednesday;
    bool thursday;
    bool friday;
    
    int start_time;		// format hhmm using 24 hour clock
    int end_time;
    string place;		// location of the class
    int max_capacity;		// maximum capacity of the class room
    int enrolled;		// number of students enrolled in this class
        
  };  
  
  struct course {
    string courseNo;
    string courseName;
    bool lecture_required;
    bool discussion_required;
    bool lab_required;
    
    string prereq1A;		// 1A, 1B and 1C represents the "or" statements
    string prereq1B;		//    example: 1A == 22, 1B == 33, 1C == 44 would be read as
    string prereq1C;		//    "ICS 22 or ICS 33 or ICS 44"
    string prereq2A;		// 1A, 2A and 3A represents the "and statements
    string prereq2B;		//    example: 1A == 22, 2A == 55, 3A == 66 would be read as
    string prereq2C;		//    "ICS 22 and ICS 55 and ICS 66
    string prereq3A;		// Combined example:
    string prereq3B;		//    1A == 22, 1B == 33, 1C == 44, 2A == 55, 3A == 66, 3B == 77
    string prereq3C;		//    (ICS 22 or ICS 33 or ICS 44) and ICS 55 and (ICS 66 or ICS 77)
    string prereq4A;		// Unused == "NULL"
    string prereq4B;
    string prereq4C;
    
    string corereq;
    
    vector <classes> this_courses_classes;
  };
  
  vector <course> coursesThisQuarter;
  int numberOfCourses;
  
    
  void importSchedule(char tq[]);	// imports the schedule, tq == schedule file name
  void importScheduleTitleLine( vector<string> sentense);
  void importSchedulePreR( vector<string> sentense, int prNum);
  void importScheduleCorR( vector<string> sentense);
  void importScheduleClass( vector<string> sentense);
  void importScheduleSessions( vector<string> sentense);
  
  
  
};
