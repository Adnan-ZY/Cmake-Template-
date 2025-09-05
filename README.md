# Template For Cmake Projects ( EBRYX )

# 🛠️ CMake Project Template


A modern **C++ project template** with **CMake presets** and **vcpkg integration** for dependency management.  
This template is designed to be **cross-platform** (Windows, Linux, macOS) and easy to extend.

---

## 📂 Project Structure
```
Cmake-Template/
│── CMakeLists.txt        # Main CMake build script
│── CMakePresets.json     # Configure, build & test presets
│── vcpkg.json            # Dependencies (manifest mode)
│── src/                  # Source files
│── include/              # Header files
│── tests/                # Unit tests
│── out/                  # Build output (generated)
│── README.md             # Project documentation
```

---

## 🚀 Getting Started

### 🔹 Prerequisites
Make sure you have:
- [CMake ≥ 3.21](https://cmake.org/download/)  
- A C++ compiler (MSVC, GCC, or Clang)  
- [vcpkg](https://github.com/microsoft/vcpkg) (Manifest mode is used)  

Optional (Windows only):
- Visual Studio 2022 with **x64 Native Tools Command Prompt**  
- [Ninja Build](https://ninja-build.org/) for faster builds  

---

### 🔹 Clone the Repository
```sh
git clone https://github.com/Adnan-ZY/Cmake-Template-.git
cd Cmake-Template-
```

---

### 🔹 Configure & Build

#### Windows
```sh
cmake --preset default-debug
cmake --build --preset default-debug
```

#### Linux / macOS
```sh
cmake --preset linux-debug
cmake --build --preset linux-debug
```

#### Release Build
```sh
cmake --preset default-release
cmake --build --preset default-release
```

---

### 🔹 Running Tests
```sh
ctest --preset default-debug
```

---

## 📦 Dependency Management (vcpkg)

This project uses **vcpkg manifest mode** (`vcpkg.json`) to automatically fetch dependencies.  
No manual install required — CMake + vcpkg will handle everything.

Example `vcpkg.json`:
```json
{
  "name": "cmake-template",
  "version": "1.0.0",
  "dependencies": [
    "fmt",
    "spdlog"
  ],
  "builtin-baseline": "HEAD"
}
```

- `dependencies`: List of libraries to fetch.  
- `builtin-baseline`: Ensures reproducible builds (locks versions).  

---

## ⚙️ CMake Presets

This project provides ready-to-use **CMakePresets.json** for common workflows:

```json
{
  "version": 3,
  "cmakeMinimumRequired": { "major": 3, "minor": 21, "patch": 0 },
  "configurePresets": [
    {
      "name": "default-debug",
      "generator": "Ninja",
      "binaryDir": "out/build/default-debug",
      "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Debug",
        "CMAKE_TOOLCHAIN_FILE": "C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
      }
    },
    {
      "name": "linux-debug",
      "generator": "Ninja",
      "binaryDir": "out/build/linux-debug",
      "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Debug"
      }
    }
  ]
}
```

✅ No need to type long commands — just use `--preset`.

---

## 📝 Updating README & Pushing Changes

1. Modify files  
2. Update `README.md`  
3. Commit & push:
```sh
git add .
git commit -m "Updated build system + README"
git push origin main
```

---

## ✨ Features
- ✅ Cross-platform (Windows, Linux, macOS)  
- ✅ Uses **CMake presets** for easy builds  
- ✅ Integrated with **vcpkg (manifest mode)**  
- ✅ Unit testing support (`tests/`)  
- ✅ Clean, extensible project structure  

---

## 📜 License
This project is licensed under the **MIT License** – feel free to use and modify it.
