#================================ PROJECT NAME =================================
PROJECT_NAME          := 3DViewer

#================================== COMPILER =================================== 
CXX                   := g++

#==================================== FLAGS ====================================
CXXFLAGS              := -Wall -Wextra -Werror -std=c++17 -pedantic
LDFLAGS               := -lgtest
COVERAGE_FLAGS        := -fprofile-arcs -ftest-coverage
VALGRIND              := --tool=memcheck --leak-check=yes

ALL_FILES             := $(shell find . -type f \( -name "*.h" -o -name "*.cc" \))


cpplint:
	cpplint $(ALL_FILES)

clang:
	clang-format -style=Google -i $(ALL_FILES)

1:
	@echo $(ALL_FILES)