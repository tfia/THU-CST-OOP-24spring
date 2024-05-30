CC := g++
override CFLAGS += -std=c++11
TARGET := main

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

subtask1:
	@make main CFLAGS="-D _SUBTASK_1_"
subtask2:
	@make main CFLAGS="-D _SUBTASK_2_"
subtask3:
	@make main CFLAGS="-D _SUBTASK_3_"
subtask4:
	@make main CFLAGS="-D _SUBTASK_4_"

$(TARGET): $(OBJS)
	$(CC) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(TARGET) *.o

.PHONY: clean subtask1 subtask2 subtask3 subtask4