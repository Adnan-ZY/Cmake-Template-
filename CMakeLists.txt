cmake_minimum_required(VERSION 3.20)
project(MyProject VERSION 1.0 LANGUAGES CXX)

# -------------------------------
# Set C++ standard
# -------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # for clang-tidy, cppcheck

# -------------------------------
# Enable testing
# -------------------------------
enable_testing()

# -------------------------------
# vcpkg integration
# -------------------------------
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
   set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

endif()

# -------------------------------
# Source files
# -------------------------------
file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp)
file(GLOB_RECURSE PROJECT_HEADERS include/*.h include/*.hpp)

# -------------------------------
# Create main executable
# -------------------------------
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE include)

# -------------------------------
# Packages from vcpkg
# -------------------------------
find_package(spdlog REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

find_package(GTest REQUIRED)
if(TEST_SOURCES)
    file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)
    add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES} ${PROJECT_HEADERS})
    target_include_directories(${PROJECT_NAME}_tests PRIVATE include)
    target_link_libraries(${PROJECT_NAME}_tests PRIVATE GTest::gtest_main spdlog::spdlog)
    add_test(NAME RunTests COMMAND ${PROJECT_NAME}_tests)
endif()

# -------------------------------
# Doxygen
# -------------------------------
# -------------------------------
# Doxygen
# -------------------------------
find_package(Doxygen)
if(DOXYGEN_FOUND)
    # Output folder for Doxygen docs
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/docs)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)

    add_custom_target(doc_doxygen
        COMMAND ${CMAKE_COMMAND} -E make_directory ${DOXYGEN_OUT}  # ensure folder exists
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen in ${DOXYGEN_OUT}"
        VERBATIM)
endif()

# -------------------------------
# Cppcheck static analysis
# -------------------------------
find_program(CPPCHECK cppcheck)
if(CPPCHECK)
    # Folder to save Cppcheck reports
    set(CPPCHECK_REPORT_DIR ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_reports)

    # Create folder and run cppcheck
    add_custom_target(static_analysis
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CPPCHECK_REPORT_DIR}
        COMMAND cppcheck --enable=all --inconclusive --std=c++17 --force --quiet
                --xml --xml-version=2
                ${PROJECT_SOURCES} ${PROJECT_HEADERS} 2> ${CPPCHECK_REPORT_DIR}/cppcheck_report.xml
        COMMENT "Running cppcheck static analysis (XML saved in cppcheck_reports folder)"
        VERBATIM)
endif()
