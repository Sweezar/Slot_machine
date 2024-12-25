CC = g++
CFLAGS = -g -std=c++17 -Wall -Wextra
LDFLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system 
SOURCES = *.cpp fsm/*.cpp
TARGET = game

CMAKE_BUILD_DIR = build

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
	rm -rf build

install:
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $(TARGET)

clang:
	clang-format -style=google -i $(SOURCES) *.h fsm/*.h

valgrind_check:
	valgrind --leak-check=full ./$(TARGET)