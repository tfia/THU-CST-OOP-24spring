#pragma once
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

class HitStatsResult {
private:
    std::vector<int> hitCount, missCount;
    int depth;
public:
    // For subtask 1, 3
    HitStatsResult (int _hit, int _miss):hitCount({_hit}), missCount({_miss}), depth(1) {}

    // For subtask 4
    HitStatsResult (std::vector<int> _hitCount, std::vector<int> _missCount):
        hitCount(_hitCount), missCount(_missCount), depth(_hitCount.size()) {
            assert(depth == missCount.size());
        }
    friend HitStatsResult operator+(const HitStatsResult& a, const HitStatsResult& b) {
        std::vector<int> retHitCount(a.hitCount), retMissCount(a.missCount);
        retHitCount.insert(retHitCount.end(), b.hitCount.begin(), b.hitCount.end());
        retMissCount.insert(retMissCount.end(), b.missCount.begin(), b.missCount.end());
        return HitStatsResult(retHitCount, retMissCount);
    }

    // For output
    friend std::ostream& operator<<(std::ostream& out, const HitStatsResult& res);
};

std::ostream& operator<<(std::ostream& out, const HitStatsResult& res) {
    for (int i = 0; i < res.depth; ++i) {
        out << "(level-" << i + 1 << ") hit = " << res.hitCount[i] 
            << ", miss = " << res.missCount[i];
        if (i < res.depth - 1) {
            out << "; ";
        }
    }
    return out;
}

