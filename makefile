RM=rm -rf

PROG_NAME = a.out

a.out: stringfunctions.o loggertime.o driver.o
	g++ -std=c++11 stringfunctions.o loggertime.o driver.o

driver.o: driver.cpp loggertime.h stringfunctions.h
	g++ -c driver.cpp

loggertime.o: loggertime.h loggertime.cpp stringfunctions.h
	g++ -c loggertime.cpp

stringfunctions.o: stringfunctions.h stringfunctions.cpp loggertime.h
	g++ -c -std=c++11 stringfunctions.cpp

clean: 
	@echo --Rebuild completely from source--
	$(RM) *.o *~ $(PROG_NAME)
	make a.out