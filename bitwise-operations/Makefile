CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++17 -Iinclude

test: src/CustomBitset.cpp tests/test.cpp 
	$(CXX) $(CXXFLAGS) src/CustomBitset.cpp tests/test.cpp -o build/test

run: test
	./build/test

clean:	
	rm -f build/test