mytests: mytests.o HashMap.o
	g++ -std=c++2a -o mytests mytests.o HashMap.o

mytests.o: mytests.cpp HashMap.hpp
	g++ -std=c++2a -c mytests.cpp -o mytests.o

HashMap.o: HashMap.cpp HashMap.hpp customexceptions.hpp
	g++ -std=c++2a -c HashMap.cpp -o HashMap.o

clean:
	rm -f *.o mytests
