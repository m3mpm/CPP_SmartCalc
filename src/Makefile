.PHONY : all build install uninstall dvi dist tests gcov_report clang cppcheck leaks valgrind clean
CC = g++ -std=c++17
CFLAGS = -Wall -Werror -Wextra
CPPCHECKFLAGS = --enable=all --language=c++ --std=c++17 --suppress=missingIncludeSystem --suppress=unusedFunction --suppress=passedByValue --suppress=unmatchedSuppression --suppress=missingInclude

OS = $(shell uname)
ifeq ($(OS),Darwin)
	CHECKFLAGS = -lgtest
	GCOVFLAGS = --coverage
else
	CHECKFLAGS = -lgtest -lpthread -lrt -lm
	GCOVFLAGS = -fprofile-arcs -ftest-coverage
endif

SOURСES :=Controller/controller.cpp \
	Model/model.cc \
	Model/credit.cc \
	Model/deposit.cc \
	main.cpp \
	mainwindow.cpp 
SOURСES_H :=Controller/controller.h \
	Model/model.h \
	Model/credit.h \
	Model/deposit.h \
	mainwindow.h

all: clean build

build:
	mkdir ./build/; cd ./build/; qmake ../; make;

# install: clean uninstall build
# 	mkdir $(HOME)/Desktop/SmartCalc/
# 	cp -rf ./build/SmartCalc.app $(HOME)/Desktop/SmartCalc/
# 	make clean
# 	@open $(HOME)/Desktop/SmartCalc/

install: clean uninstall build
	mkdir ../SmartCalc/
	cp -rf ./build/SmartCalc.app ../SmartCalc/
	make clean
	@open ../SmartCalc/

uninstall:
	rm -rf ../SmartCalc/
# rm -rf $(HOME)/Desktop/SmartCalc/

dvi:
	makeinfo --html Documentation.texi
	open ./Documentation/index.html

dist:
	@ rm -rf SmartCalcZip
	mkdir SmartCalcZip; mkdir SmartCalcZip/src
	cp -rf Model/ SmartCalcZip/src/Model/
	cp -rf Controller/ SmartCalcZip/src/Controller
	cp *.h *.cpp *.ui *.pro *.pro.user Makefile Documentation.texi SmartCalcZip/src
	tar -cvzf SmartCalcZip.tar.gz SmartCalcZip/
	mv SmartCalcZip.tar.gz $(HOME)/Desktop/
	@ rm -rf SmartCalcZip/
	@ open $(HOME)/Desktop/

tests: test.cc Model/model.cc
	$(CC) $(CFLAGS) test.cc Model/model.cc $(CHECKFLAGS) -o a.out
	./a.out

gcov_report: test.cc Model/model.cc
	$(CC) $(CFLAGS) $(GCOVFLAGS) test.cc Model/model.cc $(CHECKFLAGS) -o gcov_rep.out
	./gcov_rep.out
	lcov -t "gcov_rep" --no-external --output-file=coverag.info --capture --directory .
	genhtml -o ./report coverag.info
	@ open report/index.html


clang:
	@cp ../materials/linters/.clang-format ./
	@clang-format -i Controller/*
	@clang-format -i Model/*
	@clang-format -i main.cpp
	@clang-format -i mainwindow.cpp
	@clang-format -i mainwindow.h
	@clang-format -i test.cc

	clang-format -n Controller/*
	clang-format -n Model/*
	clang-format -n main.cpp
	clang-format -n mainwindow.cpp
	clang-format -n mainwindow.h

	@rm .clang-format

cppcheck:
	cppcheck $(CPPCHECKFLAGS) $(SOURСES)
	cppcheck $(CPPCHECKFLAGS) $(SOURСES_H)
	cppcheck $(CPPCHECKFLAGS) main.cpp
	cppcheck $(CPPCHECKFLAGS) mainwindow.cpp
	cppcheck $(CPPCHECKFLAGS) mainwindow.h
	cppcheck $(CPPCHECKFLAGS) test.cc

leaks:
	CK_FORK=no leaks --atExit -- ./a.out

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./a.out

clean:
	rm -f *.o *.a *.gcno *.gcda *.info *.out
	rm -rf ./report
	rm -rf ./build
	rm -rf ./Documentation
