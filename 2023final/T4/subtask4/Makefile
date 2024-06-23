all: sample

sample: sample7 sample8

sample7: main_sample7.cpp MyDict.hpp HitStatsResult.hpp PopStrategy.hpp
	g++ main_sample7.cpp -o sample7 -D__SUBTASK4__ -O2 -std=c++14

sample8: main_sample8.cpp MyDict.hpp HitStatsResult.hpp PopStrategy.hpp
	g++ main_sample8.cpp -o sample8 -D__SUBTASK4__ -O2 -std=c++14

clean:
	rm sample7 sample8
