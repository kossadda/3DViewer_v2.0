#================================ PROJECT NAME =================================
PROJECT_NAME          := 3DViewer

#==================================== FLAGS ====================================
VALGRIND              := --leak-check=full

#=============================== DIRECTORY NAMES ===============================
BIN_DIR               := ../bin
TEST_BIN_DIR          := ./test_bin
SETTING_DIR           := ~/.config/3DViewer
DOCS_DIR              := ../docs
DIST_DIR              := ../dist

#================================== FILE LIST ==================================
EXCLUDE               := gif.h
ALL_FILES             := $(shell find . -type f \( -name "*.h" -o -name "*.cc" \) \
												 | grep -v '/$(EXCLUDE)')
ARCHIVE_NAME          := $(PROJECT_NAME).tar.gz

#=================================== TARGETS ===================================
all: install run

install: $(BIN_DIR)
	cd $(BIN_DIR) && cmake ../src && make

uninstall: clean
	rm -rf $(SETTING_DIR)
	rm -rf $(BIN_DIR)
	rm -rf $(DOCS_DIR)
	rm -rf $(DIST_DIR)

test: $(TEST_BIN_DIR)
	cd $(TEST_BIN_DIR) && cmake ../tests && make
	valgrind $(VALGRIND) ./$(TEST_BIN_DIR)/tests

clean:
	rm -rf $(TEST_BIN_DIR)

run:
	./$(BIN_DIR)/viewer

valgrind_run:
	valgrind $(VALGRIND) ./$(BIN_DIR)/viewer

#================================ STYLE CHECKS =================================
cpplint:
	cpplint $(ALL_FILES)

clang:
	clang-format -style=Google -i $(ALL_FILES)

#============================= CREATE DIRECTORIES ==============================
$(BIN_DIR):
	mkdir $(BIN_DIR)

$(TEST_BIN_DIR):
	mkdir -p $(TEST_BIN_DIR)

$(DOCS_DIR):
	mkdir $(DOCS_DIR)

$(DIST_DIR):
	mkdir $(DIST_DIR)

#=========================== GENERATE DOCUMENTATION ============================
dvi: $(DOCS_DIR)
	doxygen Doxyfile
	xdg-open $(DOCS_DIR)/html/index.html

#=================================== ARCHIVE ===================================
dist: clean $(DIST_DIR)
	tar -czvf $(DIST_DIR)/$(ARCHIVE_NAME) -C .. src README.md README_RUS.md LICENSE.txt
