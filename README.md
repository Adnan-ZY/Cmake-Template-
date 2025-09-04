# MyProject

**Description:**  
MyProject is a C++ application built using **CMake**, **vcpkg**, and **MSVC**.  
It uses **spdlog** for logging, **GTest** for unit testing, and supports **Doxygen** documentation.

---

## Features
- Logging with spdlog
- Unit testing with Google Test
- Doxygen documentation generation
- Static analysis with cppcheck

---

## Prerequisites
- **CMake >= 3.20**
- **Visual Studio 2022** (with C++ workload)
- **vcpkg** for dependency management
- **Doxygen** for documentation (optional)
- **Cppcheck** for static analysis (optional)

---

## Setup & Build

1. Open PowerShell in the project directory.
2. Install dependencies via vcpkg:

```powershell
vcpkg install spdlog gtest
