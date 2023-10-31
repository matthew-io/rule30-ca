CC = g++ 
CFLAGS = -std=c++11 -Wall

TARGET = a.out
SOURCES = Helper.cpp CA.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)