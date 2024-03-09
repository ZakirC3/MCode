all:
	gcc private/test/test.c -o private/test/test1
	gcc app/src/main.c -o app/out/main
	g++ app/src/main.cpp -o app/out/cmain
	g++ private/test/test.cpp -o private/test/ctest1

test:
	gcc private/test/test.c -o private/test/test1
ctest:
	g++ private/test/test.cpp -o private/test/ctest1
c:
	gcc app/src/main.c -o app/out/main
cpp:
	g++ app/src/main.cpp -o app/out/cmain
cc:
	gcc app/src/main.c -o app/out/main
	g++ app/src/main.cpp -o app/out/cmain
cct:
	gcc private/test/test.c -o private/test/test1
	g++ private/test/test.cpp -o private/test/ctest1