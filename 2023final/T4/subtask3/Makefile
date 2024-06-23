all: sample

sample: sample5 sample6

sample5: main_sample5.cpp MyDict.hpp HitStatsResult.hpp PopStrategy.hpp
	g++ main_sample5.cpp -o sample5 -D__SUBTASK3__ -O2 -std=c++14

sample6: main_sample6.cpp MyDict.hpp HitStatsResult.hpp PopStrategy.hpp
	g++ main_sample6.cpp -o sample6 -D__SUBTASK3__ -O2 -std=c++14

clean:
	rm sample5 sample6
