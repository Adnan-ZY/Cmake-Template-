#include <iostream>
#include <spdlog/spdlog.h>
#include "MyProject/myheader.h"

int main() {
    spdlog::info("Hello from MyProject using Ninja + MSVC + vcpkg!");
    MyProject::say_hello("User");
    return 0;
}
