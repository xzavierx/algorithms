#include "st.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("find range correctly", "[Sparse Table]") {
    SparseTable<int> st({0, 13, 14, 4, 13, 1, 5, 7});
    // REQUIRE(st.query(0, 1) == 13);
    REQUIRE(st.query(1, 2) == 14);
    SparseTable<int> stt({1, 2, 3, 4, 5, 6});
    stt.print();
    REQUIRE(stt.query(0, 5) == 6);
}
