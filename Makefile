CC = g++
CCC = g++
CFLAGS = -c -g
CCFLAGS = $(CFLAGS)
LDFLAGS = -g


O = course.o main.o


exe: $O
	$(CCC) $(LDFLAGS) $O -o exe

course.o: course.cpp course.hpp
	g++ $(CCFLAGS) course.cpp



