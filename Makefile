CXX = g++
CXXFLAGS = -std=c++17

waf: $(wildcard *.cpp)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

clean:
	rm -f sandbox_tester sandbox_test.txt
