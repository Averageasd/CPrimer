all: ptr_traverse ptr_order_testing zippo1 one_dim_arr_rev

ptr_traverse : ptr_traverse.c
	gcc -o ptr_traverse ptr_traverse.c

ptr_order_testing : ptr_order_testing.c
	gcc -o ptr_order_testing ptr_order_testing.c

zippo1: zippo1.c
	gcc -o zippo1 zippo1.c

one_dim_arr_rev : one_dim_arr_rev.c
	gcc -o one_dim_arr_rev one_dim_arr_rev.c

clean:
	rm -f ptr_traverse
	rm -f ptr_order_testing
	rm -f zippo1
	rm -f one_dim_arr_rev