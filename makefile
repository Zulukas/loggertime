RM = rm -rf

a.out: driver.o loggertime.o stringfunctions.h
	g++ -o a.out driver.o loggertime.o stringfunctions.h

driver.o: driver.cpp loggertime.h
	g++ -c driver.cpp

stringfunctions.o: stringfunctions.h stringfunctions.cpp
	g++ -c stringfunctions.cpp

loggertime.o: loggertime.h loggertime.cpp
	g++ -c loggertime.cpp

clean: 
	$(RM) *.o *~ a.out
	make a.out