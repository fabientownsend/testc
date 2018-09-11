test:
	gcc lib/unity.c lib/unity_fixture.c tests/example.test.c -o main && ./main

build: test
	mkdir -p bin
	gcc src/main.c -o bin/main
