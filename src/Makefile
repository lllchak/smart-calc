CC_FLAGS=-Wall -Wextra -Werror -std=c11
FILES=backend/parser/*.c backend/stack/*.c backend/stack/clstack/*c backend/calculation/*.c
OBJ=*.o
OS=$(shell uname -s)

SRC_DIR= .
TEST_DIR=tests
INCLUDE_DIR := $(shell find $(SRC_DIR) -type d)
BUILD_DIR=build
GCOV_DIR=gcov_report
DOC_DIR=html

ifeq ($(OS), Darwin)
	TEST_FLAGS=-lcheck
else
	TEST_FLAGS=-lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
	CC_FLAGS+=-lm
endif

all: s21_smart_calc_v10.a

QT_PROJECT_NAME = ui
QT_PROJECT_FOLDER = ./$(QT_PROJECT_NAME)
QT_PRO = $(QT_PROJECT_NAME).pro
QT_MAKEFILE = $(QT_PROJECT_NAME)_Makefile
QT_BUILD_FOLDER = build
QT_APP_FOLDER = ../app
DIST_FOLDER_NAME = SmartCalc-1.0

generate_make:
	@qmake $(QT_PROJECT_FOLDER)/$(QT_PRO) -o ./$(QT_BUILD_FOLDER)/$(QT_MAKEFILE)
	@rm -rf .qmake.stash

install: generate_make
	@echo "Building application..."
	@cd ./$(QT_BUILD_FOLDER) && make -sf $(QT_MAKEFILE)
	@echo "Application builded."
	@echo -n "Moving application to folder \"$(QT_APP_FOLDER)\"..."
	@mkdir ./$(QT_APP_FOLDER)
ifeq ($(OS), Darwin)
	@mv ./$(QT_BUILD_FOLDER)/$(QT_PROJECT_NAME).app/Contents/MacOS/SmartCalc ./$(QT_APP_FOLDER)/$(QT_PROJECT_NAME).app
else
	@mv ./$(QT_BUILD_FOLDER)/$(QT_PROJECT_NAME) ./$(QT_APP_FOLDER)/$(QT_PROJECT_NAME)
endif
	@echo " Done."
	@echo -n "Deleting build folder..."
	@rm -rf $(QT_BUILD_FOLDER)
	@echo " Done."
	@echo "Installation complete!"

uninstall:
	@echo -n "Uninstalling application..."
	@rm -rf $(QT_APP_FOLDER)
	@echo " Done."

s21_smart_calc_v1.0.a: $(OBJ)
	ar rcs s21_smart_calc_v10.a $(OBJ)
	ranlib s21_smart_calc_v10.a
	rm -f *.o

$(OBJ):
	gcc -c $(CC_FLAGS) $(FILES)

tests: clean $(OBJ)
	gcc -c $(CC_FLAGS) tests/tests.c
	gcc $(CC_FLAGS) $(OBJ) $(TEST_FLAGS) -o tests.out 
	./tests.out
	rm -rf $(OBJ)

gcov_report:
	gcc $(CC_FLAGS) --coverage -o make_report.out tests/tests.c $(FILES) $(TEST_FLAGS)
	./make_report.out
	lcov -t "make_report" -o make_report.info -c -d .
	genhtml -o report make_report.info
	rm -f *.gcda *.gcno *.info *.out

leaks: test
	CK_FORK=no leaks --atExit -- ./tests.out

debug:
	gcc $(CC_FLAGS) -fsanitize=address $(FILES) backend/test.c -o debug.out
	@echo
	./debug.out
	@echo
	rm debug.out

clean: 
	rm -f *.gcda *.gcov *.o *.gcno
	rm -f s21_smart_calc.a
	rm -rf $(BUILD_DIR) $(GCOV_DIR)
	rm -rf *out *info
	rm -rf $(DOC_DIR) $(TAR_DIR) ../$(TAR_DIR).tgz
	rm -rf $(QT_APP_FOLDER)
