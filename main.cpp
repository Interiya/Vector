#include <iostream>
#include "Vector.h"
#include "gtest/gtest.h"
using namespace std;

TEST(Vector,EQ){
    Vector<int> a(5);
    Vector<int> b(5);
    a.pushBack(1);
    b.pushBack(1);
    ASSERT_EQ(a,b);
};

int main(int argc, char *argv[]){

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}