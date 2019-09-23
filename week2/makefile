.SUFFIXES: .cpp .o

OBJECTS = main.o print.o student_id.o

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean :
	rm -rf $(OBJECTS) $(TARGET)

main.o : main.cpp
print.o : print.cpp
student_id.o : student_id.cpp

#####################################

# 시프 Makefile

# CC = gcc
# CFLAGS = -W -Wall
# TARGET = diary

# OBJECTS = memo.o calendar.o main.o

# .SUFFIXES : .o .c

# %.o : %.c
# 	$(CC) $(CFLAGS) -c $^

# all : $(TARGET)

# $(TARGET) : $(OBJECTS)
# 	$(CC) $(CFLAGS) -o $@ $^

# clean : 
# 	rm -rf *.o
# 	rm -rf *.out

# # memo.o : memo.c
# # 	$(CC) $(CFLAGS) -c -o $@ $^

# # calendar.o : calendar.c
# # 	$(CC) $(CFLAGS) -c -o $@ $^

# # main.o : main.c
# # 	$(CC) $(CFLAGS) -c -o $@ $^