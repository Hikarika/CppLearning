CXX = g++
#CXXFLAGS = -O3 -march=native
#CXXFLAGS = -std=c++11 
CXXFLAGS = -std=c++11 -pthread -Wl,--no-as-needed
LIBRARIES = -lpthread 
#-pthread -std=c++11 -Wl,--no-as-needed
.PHONY: default run
default: run

run:
	${CXX} ${CXXFLAGS} *.cpp ${LIBRARIES} -o program 
	
clean:
	rm -f *.o program
