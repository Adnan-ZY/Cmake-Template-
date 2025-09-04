#include <gtest/gtest.h>
#include "MyProject/myheader.h"

TEST(SayHelloTest, ExecutesWithoutError) {
    // Call function with some test names
    EXPECT_NO_THROW(MyProject::say_hello("Alice"));
    EXPECT_NO_THROW(MyProject::say_hello("Bob"));
}
