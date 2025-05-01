all: echo_eof file_eof showchar1

echo_eof : echo_eof.c
	gcc echo_eof.c -o echo_eof

file_eof : file_eof.c
	gcc file_eof.c -o file_eof

showchar1: showchar1.c	
	gcc showchar1.c -o showchar1

clean:
	rm -f echo_eof
	rm -f file_eof
	rm -f showchar1