CC = g++
CCC = g++
CFLAGS = -c -g
CCFLAGS = $(CFLAGS)
LDFLAGS = -g


O = course.o main.o


exe: $O
	$(CCC) $(LDFLAGS) $O -o exe

main.o: main.cpp 
	g++ $(CCFLAGS) main.cpp 

course.o: course.cpp
	g++ $(CCFLAGS) course.cpp



