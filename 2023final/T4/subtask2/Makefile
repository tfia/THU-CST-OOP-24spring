all: sample

sample: sample3 sample4

sample3: main_sample3.cpp PopStrategy.hpp
	g++ main_sample3.cpp -o sample3 -D__SUBTASK2__ -O2 -std=c++14

sample4: main_sample4.cpp PopStrategy.hpp
	g++ main_sample4.cpp -o sample4 -D__SUBTASK2__ -O2 -std=c++14

clean:
	rm sample3 sample4
