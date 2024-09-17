#================================ PROJECT NAME =================================
PROJECT_NAME          := 3DViewer

#================================== COMPILER =================================== 
CXX                   := g++

#==================================== FLAGS ====================================
CXXFLAGS              := -Wall -Wextra -Werror -std=c++17 -pedantic
LDFLAGS               := -lgtest
COVERAGE_FLAGS        := -fprofile-arcs -ftest-coverage
VALGRIND              := --tool=memcheck --leak-check=yes


#============================== LIBRARY BUILDING ===============================
MODEL_LIB             := model.a
MODEL_GCOVR_LIB       := model_gcovr.a

#=============================== DIRECTORY NAMES ===============================
BIN_DIR               := ../bin
INCLUDE_DIR           := ./include
MODEL_DIR             := ./model
OBJ_DIR               := ./obj
OBJ_DIR_COV           := ./obj_cov
TESTS_DIR             := ./tests
REPORT_DIR            := ./report

#=============================== COVERAGE REPORT ===============================
GCOVR_EXCLUDES        := --exclude='.*tests/.*|.*include/.*'
GCOVR_HTML            := -r . $(GCOVR_EXCLUDES) --html --html-details -o $(REPORT_DIR)/coverage.html 
GCOVR_TXT             := -r . $(GCOVR_EXCLUDES) --txt -o $(REPORT_DIR)/coverage.txt 

#================================== FILE LIST ==================================
MAIN                  := $(PROJECT_NAME).cc
MAIN_TEST             := $(TESTS_DIR)/main_test.cc

#==================================== MODEL ====================================
MODEL_CC              := $(shell find $(MODEL_DIR) -type f -name "*.cc")
MODEL_H               := $(shell find $(INCLUDE_DIR)/model -type f -name "*.h")
MODEL_O               := $(MODEL_CC:$(MODEL_DIR)/%.cc=$(OBJ_DIR)/model/%.o)
MODEL_O_COV           := $(MODEL_CC:$(MODEL_DIR)/%.cc=$(OBJ_DIR_COV)/model/%.o)

#==================================== TESTS ====================================
TESTS_CC              := $(shell find $(TESTS_DIR)/modules -type f -name "*.cc")
TESTS_H               := $(shell find $(TESTS_DIR) -type f -name "*.h")
TESTS_O               := $(TESTS_CC:$(TESTS_DIR)/%.cc=$(OBJ_DIR)/tests/%.o)

ALL_FILES             := $(shell find . -type f \( -name "*.h" -o -name "*.cc" \))

#============================== OBJECTIVE TARGETS ==============================
$(OBJ_DIR)/model/%.o: $(MODEL_DIR)/%.cc $(MODEL_H)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR_COV)/model/%.o: $(MODEL_DIR)/%.cc $(MODEL_H)
	$(CXX) $(CXXFLAGS) $(COVERAGE_FLAGS) -c -o $@ $<

$(OBJ_DIR)/tests/modules/%.o: $(TESTS_DIR)/modules/%.cc $(TESTS_H)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#=================================== TARGETS ===================================
test: $(OBJ_DIR)/tests/modules $(TESTS_O) $(MODEL_LIB)
	$(CXX) $(MAIN_TEST) $(MODEL_LIB) $(LDFLAGS) -o $@
	./$@

gcov_report: $(REPORT_DIR) $(OBJ_DIR)/tests/modules $(TESTS_O) $(MODEL_GCOVR_LIB)
	$(CXX) $(MAIN_TEST) $(TESTS_O) $(MODEL_GCOVR_LIB) $(LDFLAGS) $(COVERAGE_FLAGS) -o $(OBJ_DIR_COV)/report
	./$(OBJ_DIR_COV)/report
	gcovr $(GCOVR_HTML)
# gcovr $(GCOVR_TXT)
	@echo
	@echo
# @cat $(REPORT_DIR)/coverage.txt
	make report_open

report_open:
	xdg-open $(REPORT_DIR)/coverage.html

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_DIR_COV)
	rm -f $(MODEL_LIB)
	rm -f $(MODEL_GCOVR_LIB)
	rm -f test
	rm -rf $(REPORT_DIR)

#=========================== STATIC LIBRARY BUILDING ===========================
$(MODEL_LIB): $(OBJ_DIR)/model $(MODEL_O)
	ar rcs $@ $(MODEL_O)
	ranlib $@

$(MODEL_GCOVR_LIB): $(OBJ_DIR_COV)/model $(MODEL_O_COV)
	ar rcs $@ $(MODEL_O_COV)
	ranlib $@

#================================ STYLE CHECKS =================================
cpplint:
	cpplint $(ALL_FILES)

clang:
	clang-format -style=Google -i $(ALL_FILES)

#============================= CREATE DIRECTORIES ==============================
$(BIN_DIR):
	mkdir $(BIN_DIR)

$(OBJ_DIR)/model:
	mkdir -p $(OBJ_DIR)/model

$(OBJ_DIR_COV)/model:
	mkdir -p $(OBJ_DIR_COV)/model

$(OBJ_DIR)/tests/modules:
	mkdir -p $(OBJ_DIR)/tests/modules

$(REPORT_DIR):
	mkdir -p $(REPORT_DIR)
