CC = g++				# Define the compiler to use
CFLAGS = -Wall	# Option tells the compiler to display all warnings
TARGET = main		# Define the target executable file
OBJS = main.o 	# Defines the object files

# $(TARGET) depends on $(OBJS), and to build $(TARGET), the $(CC) compiler should be used with the $(CFLAGS) and $(OBJS) files. The result of this rule is the target executable file, $(TARGET).
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# The rule says that main.o depends on main.cpp, and to build main.o, the $(CC) compiler should be used with the $(CFLAGS) and main.cpp file. The result of this rule is the object file, main.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

# Define a clean target to remove the generated files
clean:
	rm -f $(TARGET) $(OBJS)