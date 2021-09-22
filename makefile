CCC=g++
CFLAGS=-std=c++17 -Wall -Wextra -pedantic -Weffc++ -Wold-style-cast -Woverloaded-virtual -g

main: test_main.o time_test.o Time.o
	$(CCC) $(CFLAGS) test_main.o time_test.o Time.o

check: test_main.o time_test.o Time.o
	$(CCC) $(CFLAGS) test_main.o time_test.o Time.o
	./a.out 

test_main.o: test_main.cc
	$(CCC) $(CFLAGS) -c test_main.cc

Time.o: Time.cc Time.h
	$(CCC) $(CFLAGS) -c Time.cc

time_test.o: time_test.cc
	$(CCC) $(CFLAGS) -c time_test.cc

clean: 
	\rm *.o a.out

