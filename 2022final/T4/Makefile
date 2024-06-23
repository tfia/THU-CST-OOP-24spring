CC := g++
override CFLAGS += -std=c++14 -O3
TARGET := main_int main_point main_int2 main_point2

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp)
SRCS := $(filter-out $(wildcard main_*.cpp), $(SRCS))
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all:
	@make main_int main_point main_int2 main_point2 CFLAGS+="-DSUBTASK1 -DSUBTASK2 -DSUBTASK3"
subtask1:
	@make main_int main_point main_int2 main_point2 CFLAGS+="-DSUBTASK1"
subtask2:
	@make main_int main_point main_int2 main_point2 CFLAGS+="-DSUBTASK1 -DSUBTASK2"
subtask3:
	@make main_int main_point main_int2 main_point2 CFLAGS+="-DSUBTASK1 -DSUBTASK2 -DSUBTASK3"

main_int: main_int.o $(OBJS)
	$(CC) -o $@ $^
main_int2: main_int2.o $(OBJS)
	$(CC) -o $@ $^
main_point: main_point.o $(OBJS)
	$(CC) -o $@ $^
main_point2: main_point2.o $(OBJS)
	$(CC) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(TARGET) *.o

.PHONY: all clean subtask1 subtask2 subtask3
