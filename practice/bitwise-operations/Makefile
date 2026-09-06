CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++17

test: CustomBitset.cpp test.cpp
	$(CXX) $(CXXFLAGS) CustomBitset.cpp test.cpp -o test

run: test
	./test

clean:	
	rm -f test