make: driver

driver: driver.o Complex.o
	g++ -o driver driver.o Complex.o
	
driver.o: driver.cpp Complex.h
	g++ -c driver.cpp
	
Complex.o: Complex.cpp Complex.h
	g++ -c Complex.cpp
	
