#include "MyProject/myheader.h"
#include <iostream>
#include <spdlog/spdlog.h>

/// @namespace MyProject
namespace MyProject {

    /**
     * @brief Prints a hello message to the user
     * @param name Name of the user
     *
     * This function logs the greeting using spdlog and also
     * prints it to the console.
     */
    void say_hello(const std::string& name) {
        spdlog::info("Saying hello to {}", name);
        std::cout << "Hello, " << name << "!\n";
    }

}
