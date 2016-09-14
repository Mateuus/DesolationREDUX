all: redex.so.0
redex.so.0: redex.o uuid.o 
	g++ -shared -Wl,-soname,redex.so.0 -fPIC -std=c++11 -Wall -g -luuid -o redex.so.0 redex.o uuid.o 
redex.o: redex.cpp uuid.o
	g++ -fPIC -std=c++11 -Wall -g -c redex.cpp
uuid.o: uuid.cpp uuid.hpp
	g++ -fPIC -std=c++11 -Wall -g -c uuid.cpp
clean:
	rm -rf redex.o uuid.o redex.so.0