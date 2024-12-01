mytests: mytests.o
	g++ -std=c++20 -o mytests mytests.o
	./mytests

mytests.o: mytests.cpp customexceptions.hpp HashMap.hpp HashMapTree.hpp Set.hpp MyHashFunction.hpp RBTree.hpp RBTreeNode.hpp
	g++ -std=c++20 -o mytests.o -c mytests.cpp

clean:
	rm *.o mytests
	clear