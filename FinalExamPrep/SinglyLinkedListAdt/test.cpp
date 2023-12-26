#include "heapADT.cpp"
#include "gtest/gtest.h"

TEST(MinHeapTest, InsertAndExtractMin) {
    minHeap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.insert(60);
    h.insert(70);
    h.insert(80);
    h.insert(90);
    h.insert(100);
    h.insert(110);

    EXPECT_EQ(h.extractMin(), 10);
    EXPECT_EQ(h.extractMin(), 20);
    EXPECT_EQ(h.extractMin(), 30);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}