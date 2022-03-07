select: my_select.o my_select2.o
	gcc -o my_select.out my_select.o
	gcc -o my_select2.out my_select2.o
poll: my_poll.o
	gcc -o my_poll.out my_poll.o
epoll : my_epoll.o async_epoll.o
	gcc -o my_epoll.out my_epoll.o
clean:
	rm -f *.o
	rm -f *.out