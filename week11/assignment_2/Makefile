.SUFFIXES: .cpp .o

OBJECTS = Integer.o Float.o Complex.o

TEST = test.o $(OBJECTS)

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(TEST)
	$(CXX) -o $(TARGET) $(TEST)

clean :
	rm -rf $(TEST) $(TARGET)