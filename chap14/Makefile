all : book person func_ptr exercise4 book-lib

book: book.c
	gcc -o book book.c

person: person.c
	gcc -o person person.c

func_ptr : func_ptr.c
	gcc -o func_ptr func_ptr.c

exercise4: exercise4.c
	gcc -o exercise4 exercise4.c

book-lib: book-lib.c
	gcc -o book-lib book-lib.c

clean:
	rm -f book
	rm -f person
	rm -f func_ptr
	rm -f exercise4
	rm -f book-lib