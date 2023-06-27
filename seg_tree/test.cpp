#include "segtree.h"
#include <catch2/catch_test_macros.hpp>
#include <numeric>
TEST_CASE("seg tree range sum", "[Segment Tree]") {
    vector<int> v = {0, 13, 14, 4, 13, 1, 5, 7};
    SegTreeLazyRangeSet<int> segTree(v);
    REQUIRE(segTree.range_sum(0, 1) == 13);
    REQUIRE(segTree.range_sum(0, v.size()-1) == std::accumulate(v.begin(), v.end(), 0));
}

TEST_CASE("seg tree range set", "[Segment Tree]") {
    SegTreeLazyRangeSet<int> segTree({0, 13, 14, 4, 13, 1, 5, 7});
    segTree.range_set(0, 1, 20);
    REQUIRE(segTree.range_sum(0, 1) == 40);
}
