OBJECTS = human.o student.o shared_ref.o smart_obj.o weak_pointer.o

TEST_FILE = test.o $(OBJECTS)

CXX = g++

TEST = test

$(TEST) : $(TEST_FILE)
	
	$(CXX) -o $(TEST) $(TEST_FILE)

clean :
	rm -rf $(TEST) $(TEST_FILE)