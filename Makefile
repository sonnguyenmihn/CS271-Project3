mytests: mytests.o
	g++ -o mytests mytests.o
	./mytests

mytests.o: mytests.cpp customexceptions.hpp HashMap.hpp HashMapTree.hpp Set.hpp
	g++ -o mytests.o -c mytests.cpp

clean:
	rm *.o mytests
	clear