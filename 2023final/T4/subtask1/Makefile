all: sample

sample: sample1 sample2

sample1: main_sample1.cpp MyDict.hpp HitStatsResult.hpp
	g++ main_sample1.cpp -o sample1 -D__SUBTASK1__ -O2 -std=c++14

sample2: main_sample2.cpp MyDict.hpp HitStatsResult.hpp
	g++ main_sample2.cpp -o sample2 -D__SUBTASK1__ -O2 -std=c++14

clean:
	rm sample1 sample2
