rin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp

bin/testBSTree: testBSTree.cpp BSTree.h
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp

bin/testHashTable: testHashTable.cpp Dict.h HashTable.h TableEntry.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp

clean:
	rm -rf *.o *.gch bin
