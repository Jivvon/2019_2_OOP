.SUFFIXES: .cpp .o

OBJECTS = arr2d.o block.o big_block.o color_block.o cross_block.o fold_block.o tree_block.o

MAIN = main.o $(OBJECTS)

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(MAIN)
	$(CXX) -o $(TARGET) $(MAIN)

clean :
	rm -rf $(MAIN) $(TARGET)