CC_FLAGS=-Wall -Wextra -Werror -std=c11
FILES=backend/parser/*.c backend/stack/*.c backend/stack/clstack/*c backend/calculation/*.c
OBJ=*.o
OS=$(shell uname -s)

ifeq ($(OS), Darwin)
	TEST_FLAGS=-lcheck
else
	TEST_FLAGS=-lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
	CC_FLAGS+=-lm
endif

all: s21_smart_calc_v10.a

rebuild: clean all

generate_make:
	@qmake $(QT_PROJECT_FOLDER)/$(QT_PRO) -o ./$(QT_BUILD_FOLDER)/$(QT_MAKEFILE)
	@rm -rf .qmake.stash

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
	rm -rf *.o *.gch *.out *.gcno *.gcda *.info *.gcov *cfg *.a
	rm -rf report/
	rm -rf temp/
