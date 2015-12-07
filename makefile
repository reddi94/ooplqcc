clean:
	cd examples; make clean
	@echo
	cd exercises; make clean

config:
	git config -l

init:
	touch README
	git init
	git add README
	git commit -m 'first commit'
	git remote add origin git@github.com:gpdowning/ooplqcc.git
	git push -u origin master

pull:
	@rsync -r -t -u -v --delete             \
    --include "Hello.c++"                   \
    --include "Assertions.c++"              \
    --include "UnitTests1.c++"              \
    --include "UnitTests2.c++"              \
    --include "UnitTests3.c++"              \
    --include "Exceptions.c++"              \
    --include "Types.c++"                   \
    --include "Operators.c++"               \
    --include "Variables.c++"               \
    --include "Arguments.c++"               \
    --include "Consts.c++"                  \
    --include "Arrays.c++"                  \
    --exclude "*"                           \
    ../../../examples/c++/ examples
	@rsync -r -t -u -v --delete             \
    --include "IsPrime1.c++"                \
    --include "IsPrime1.h"                  \
    --include "IsPrime2.c++"                \
    --include "Incr.c++"                    \
    --include "Equal.c++"                   \
    --include "Copy.c++"                    \
    --include "Fill.c++"                    \
    --include "AllOf.c++"                   \
    --exclude "*"                           \
    ../../../exercises/c++/ exercises

push:
	make clean
	@echo
	git add .travis.yml
	git add examples
	git add exercises
	git add makefile
	git commit -m "another commit"
	git push
	git status

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

testx:
	cd examples; make testx
	@echo
	cd exercises; make testx

testy:
	cd examples; make testy
	@echo
	cd exercises; make testy

testz:
	cd examples; make testz
	@echo
	cd exercises; make testz
