.SUFFIXES: .cpp .o

OBJECTS = vehicle.o car.o bike.o
MAIN = main.o $(OBJECTS)

CXX = g++

TARGET = test

$(TARGET) : $(MAIN)
	$(CXX) -o $(TARGET) $(MAIN)

clean :
	rm -rf $(MAIN) $(TARGET)

main.o : main.cpp

vehicle.o : vehicle.cpp

car.o : car.cpp

bike.o : bike.cpp