CXX=g++
CFLAGS= -Wall -Wextra -std=c++20 -Iinclude

test: src/bounded-buffer.cpp test/test.cpp
	$(CXX) $(CFLAGS) src/bounded-buffer.cpp test/test.cpp -o build/test

run:
	./build/test
	
clean:	
	rm -f build/test
