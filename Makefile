test:
	gcc test.c helloworld.c -o test -lcunit
	./test
	rm ./test

install_c_unit:
	sudo apt install libcunit1 libcunit1-doc libcunit1-dev
