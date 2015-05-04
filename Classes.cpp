#include <iostream>
#include <fstream>
#include <vector>
#include "Classes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

Classes :: Classes(char quarter[]){
  
  numberOfCourses = 0;
  importSchedule(quarter);
  
  printScheduleTerminal();

   
  
  
}








void Classes :: importSchedule(char tq[]){

  ifstream incoming;
  incoming.open(tq, ios::in);
  if(incoming.is_open() == 0)
    cout << "ERROR: Failed to open the file! Check the file name!\n";

  char character;
  incoming.get(character);
  while (incoming.peek() != EOF && character != 0){
    
    string thisWord;
    vector<string> thisSentense;
    while (character != '\n' && incoming.peek() != EOF && character != 0 && character != '\t'){
      
      while (character == ' ')
	incoming.get(character);
      
      while (character != '\t' && character != '\n' //&& character != EOF 
	&& character != 0 && incoming.peek() != EOF){	
	thisWord += character;
	incoming.get(character);
      }
      
      if (thisWord.length() > 0){
	thisSentense.push_back(thisWord);
	thisWord.clear();
      }
      
      if (character == '\t')
	incoming.get(character);
           
    }


    if ( thisSentense.at(0).compare("I&C Sci") == 0)
      importScheduleTitleLine( thisSentense);
      
    else if ( thisSentense.at(0).compare("P1") == 0
      || thisSentense.at(0).compare("P2") == 0
      || thisSentense.at(0).compare("P3") == 0
      || thisSentense.at(0).compare("P4") == 0
    ){
      if ( thisSentense.at(0).compare("P1") == 0)
	importSchedulePreR( thisSentense, 1);
      if ( thisSentense.at(0).compare("P2") == 0)
	importSchedulePreR( thisSentense, 2);
      if ( thisSentense.at(0).compare("P3") == 0)
	importSchedulePreR( thisSentense, 3);
      if ( thisSentense.at(0).compare("P4") == 0)
	importSchedulePreR( thisSentense, 4);      
    }
    
    else if ( thisSentense.at(0).compare("C") == 0)
      importScheduleCorR( thisSentense);
    
    else if ( thisSentense.at(0).length() == 5)
      importScheduleClass( thisSentense);
    
    else if ( thisSentense.at(0).compare("Lec") == 0
      || thisSentense.at(0).compare("Dis") == 0
      || thisSentense.at(0).compare("Lab") == 0
      || thisSentense.at(0).compare("Le") == 0
      || thisSentense.at(0).compare("Di") == 0
      || thisSentense.at(0).compare("La") == 0)
      importScheduleSessions( thisSentense);     



    while (character == '\n'){
      thisSentense.clear();
      incoming.get(character);
    }
    
    
    
  
  
  
  }

  
}

void Classes :: importScheduleTitleLine( vector<string> sentense){
cout << "Title Line\n";
  
  course win;
  
  win.courseNo = sentense.at(1);		// initializing the new course
  win.courseName = sentense.at(2);
  win.lecture_required = false;
  win.discussion_required = false;
  win.lab_required = false;
  win.prereq1A = "NULL";
  win.prereq1B = "NULL";
  win.prereq1C = "NULL";
  win.prereq2A = "NULL";
  win.prereq2B = "NULL";
  win.prereq2C = "NULL";
  win.prereq3A = "NULL";
  win.prereq3B = "NULL";
  win.prereq3C = "NULL";
  win.prereq4A = "NULL";
  win.prereq4B = "NULL";
  win.prereq4C = "NULL";
  win.corereq = "NULL";
  
  coursesThisQuarter.push_back(win);
  ++numberOfCourses;  
  
}

void Classes :: importSchedulePreR( vector<string> sentense, int prNum){
cout << "Schedule PreR\n";
  
  if (prNum == 1){
    coursesThisQuarter.at(numberOfCourses-1).prereq1A = sentense.at(1);
    coursesThisQuarter.at(numberOfCourses-1).prereq1B = sentense.at(2);
    coursesThisQuarter.at(numberOfCourses-1).prereq1C = sentense.at(3);
  }
  
  else if (prNum == 2){
    coursesThisQuarter.at(numberOfCourses-1).prereq2A = sentense.at(1);
    coursesThisQuarter.at(numberOfCourses-1).prereq2B = sentense.at(2);
    coursesThisQuarter.at(numberOfCourses-1).prereq2C = sentense.at(3);
  }
  
  else if (prNum == 3){
    coursesThisQuarter.at(numberOfCourses-1).prereq3A = sentense.at(1);
    coursesThisQuarter.at(numberOfCourses-1).prereq3B = sentense.at(2);
    coursesThisQuarter.at(numberOfCourses-1).prereq3C = sentense.at(3);
  }
  
  else if (prNum == 4){
    coursesThisQuarter.at(numberOfCourses-1).prereq4A = sentense.at(1);
    coursesThisQuarter.at(numberOfCourses-1).prereq4B = sentense.at(2);
    coursesThisQuarter.at(numberOfCourses-1).prereq4C = sentense.at(3);
  }

  
    
}

void Classes :: importScheduleCorR( vector<string> sentense){
cout << "Schedule CorR\n";
  coursesThisQuarter.at(numberOfCourses-1).corereq = sentense.at(1);

}

void Classes :: importScheduleClass( vector<string> sentense){
cout << "Class\n";
  
  classes newClass;
  
  int newClassCode = atoi(sentense.at(0).c_str());
  int newUnits = atoi(sentense.at(2).c_str());
  int newStart_time = atoi(sentense.at(4).c_str());
  int newEnd_time = atoi(sentense.at(5).c_str());
  int newMax_capacity = atoi(sentense.at(7).c_str());
  
  newClass.class_code = newClassCode;
  newClass.type = sentense.at(1);
  newClass.units = newUnits;
  newClass.start_time = newStart_time;
  newClass.end_time = newEnd_time;
  newClass.place = sentense.at(6);
  newClass.max_capacity = newMax_capacity;
  newClass.enrolled = 0;
  
  newClass.monday = 0;
  newClass.tuesday = 0;
  newClass.wednesday = 0;
  newClass.thursday = 0;
  newClass.friday = 0;
  
  if (sentense.at(3).compare("M") == 0)
    newClass.monday = 1;
  else if (sentense.at(3).compare("Tu") == 0)
    newClass.tuesday = 1;
  else if (sentense.at(3).compare("W") == 0)
    newClass.wednesday = 1;
  else if (sentense.at(3).compare("Th") == 0)
    newClass.thursday = 1;
  else if (sentense.at(3).compare("F") == 0)
    newClass.friday = 1;
  else if (sentense.at(3).compare("MW") == 0){
    newClass.monday = 1;
    newClass.wednesday = 1;
  }
  else if (sentense.at(3).compare("TuTh") == 0){
    newClass.tuesday = 1;
    newClass.thursday = 1;
  }
  else if (sentense.at(3).compare("MWF") == 0){
    newClass.monday = 1;
    newClass.wednesday = 1;
    newClass.friday = 1;
  }
  
  coursesThisQuarter.at(numberOfCourses-1).this_courses_classes.push_back(newClass);
  
  


}

void Classes :: importScheduleSessions( vector<string> sentense){
cout << "Sessions\n";

    if (sentense.at(0).compare("Lec") == 0 || sentense.at(0).compare("Le") == 0
      || sentense.at(1).compare("Lec") == 0 || sentense.at(1).compare("Le") == 0
      || sentense.at(2).compare("Lec") == 0 || sentense.at(2).compare("Le") == 0
    )
      coursesThisQuarter.at(numberOfCourses-1).lecture_required = true;
      
    if (sentense.at(0).compare("Dis") == 0 || sentense.at(0).compare("Di") == 0
      || sentense.at(1).compare("Dis") == 0 || sentense.at(1).compare("Di") == 0
      || sentense.at(2).compare("Dis") == 0 || sentense.at(2).compare("Di") == 0
    )
      coursesThisQuarter.at(numberOfCourses-1).discussion_required = true;
      
    if (sentense.at(0).compare("Lab") == 0 || sentense.at(0).compare("La") == 0
      || sentense.at(1).compare("Lab") == 0 || sentense.at(1).compare("La") == 0
      || sentense.at(2).compare("Lab") == 0 || sentense.at(2).compare("La") == 0
    )
      coursesThisQuarter.at(numberOfCourses-1).lab_required = true;
 
}

void Classes :: printScheduleTerminal(){

  cout << "\n";
  int counter1 = 0;
  vector<course>::iterator pos1;
  for (pos1 = coursesThisQuarter.begin(); pos1 != coursesThisQuarter.end(); ++pos1){
    
    cout << "\n\nCourse Number: " << coursesThisQuarter.at(counter1).courseNo
      << " === Course Name: " << coursesThisQuarter.at(counter1).courseName
      << " === Lecture: " << coursesThisQuarter.at(counter1).lecture_required
      << " === Discussion: " << coursesThisQuarter.at(counter1).discussion_required
      << " === Lab: " << coursesThisQuarter.at(counter1).lab_required
      << "\nPrerequisites: " << coursesThisQuarter.at(counter1).prereq1A
      << " or " << coursesThisQuarter.at(counter1).prereq1B
      << " or " << coursesThisQuarter.at(counter1).prereq1C
      << "\n       and     " << coursesThisQuarter.at(counter1).prereq2A
      << " or " << coursesThisQuarter.at(counter1).prereq2B
      << " or " << coursesThisQuarter.at(counter1).prereq2C
      << "\n       and     " << coursesThisQuarter.at(counter1).prereq3A
      << " or " << coursesThisQuarter.at(counter1).prereq3B
      << " or " << coursesThisQuarter.at(counter1).prereq3C
      << "\nCorerequisite: " << coursesThisQuarter.at(counter1).corereq;
      
    int counter2 = 0;
    vector<classes>::iterator pos2;
    for (pos2 = coursesThisQuarter.at(counter1).this_courses_classes.begin();
	  pos2 != coursesThisQuarter.at(counter1).this_courses_classes.end();
	  ++pos2){
      cout << "\n --- Class Code: " << coursesThisQuarter.at(counter1).this_courses_classes.at(counter2).class_code
	<< "\n --- Type of Class: " << coursesThisQuarter.at(counter1).this_courses_classes.at(counter2).type
	<< "\n --- # of Units: " << coursesThisQuarter.at(counter1).this_courses_classes.at(counter2).units
	<< "\n --- Monday: " << coursesThisQuarter.at(counter1).this_courses_classes.at(counter2).monday
	<< " --- Tuesday: " << coursesThisQuarter.at(counter1).this_courses_classes.at(counter2).tuesday
	<< " --- Wednesday: " << coursesThisQuarter.at(counter1).this_courses_classes.at(counter2).wednesday
	<< " --- Thursday: " << coursesThisQuarter.at(counter1).this_courses_classes.at(counter2).thursday
	<< " --- Friday: " << coursesThisQuarter.at(counter1).this_courses_classes.at(counter2).friday
	<< "\n --- Start Time: " << coursesThisQuarter.at(counter1).this_courses_classes.at(counter2).start_time
	<< " --- End Time: " << coursesThisQuarter.at(counter1).this_courses_classes.at(counter2).end_time
	<< "\n --- Place: " << coursesThisQuarter.at(counter1).this_courses_classes.at(counter2).place
	<< "\n --- Maximum Capacity: " << coursesThisQuarter.at(counter1).this_courses_classes.at(counter2).max_capacity
	<< " --- Number Enrolled: " << coursesThisQuarter.at(counter1).this_courses_classes.at(counter2).enrolled;

      
      cout << "\n";
      ++counter2;
    }    
    ++counter1;
  } 
  cout << "\n\n";  
}

void Classes :: printScheduleTxt(char fileName[]){
}
