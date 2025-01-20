# Compiler settings
CXX = g++
CXXFLAGS = -fsanitize=address -O1 -fno-omit-frame-pointer -g -Wall -Wshadow \
           -std=c++20 -Wno-unused-result -Wno-sign-compare

# Generic rule for any .cpp file
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean built files
clean:
	find . -type f -executable -not -name "*.*" -delete
	rm -f *.o

# Phony targets
.PHONY: clean
