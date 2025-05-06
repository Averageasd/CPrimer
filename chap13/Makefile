all : count partial-read-write read-line-from-file

count : count.c
	gcc -o count count.c

partial-read-write: partial-read-write.c
	gcc -o partial-read-write partial-read-write.c

read-line-from-file : read-line-from-file.c
	gcc -o read-line-from-file read-line-from-file.c

clean:
	rm -f count
	rm -f partial-read-write
	rm -f read-line-fromm-file