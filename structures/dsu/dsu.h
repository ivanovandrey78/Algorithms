#pragma once

#include <vector>

class Dsu {
private:
    std::vector<int> parent_;
    std::vector<int> rank_;

public:
    explicit Dsu(int n) {
        parent_.resize(n);
        rank_.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent_[i] = i;
        }
    }

    int Find(int x) {
        if (parent_[x] != x) {
            parent_[x] = Find(parent_[x]);
        }
        return parent_[x];
    }

    void Unite(int x, int y) {
        int root_x = Find(x);
        int root_y = Find(y);
        if (root_x == root_y) return;

        if (rank_[root_x] < rank_[root_y]) {
            parent_[root_x] = root_y;
        } else if (rank_[root_x] > rank_[root_y]) {
            parent_[root_y] = root_x;
        } else {
            parent_[root_y] = root_x;
            rank_[root_x]++;
        }
    }

    bool Same(int x, int y) { return Find(x) == Find(y); }
};