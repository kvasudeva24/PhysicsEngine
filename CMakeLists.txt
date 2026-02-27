cmake_minimum_required(VERSION 3.14)
project(KineticPhysics VERSION 1.0 LANGUAGES CXX)

# Force C++17 for threading and modern features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------------------------------------------------------
# 1. Main Library (The Physics Engine Core)
# ---------------------------------------------------------------------------
add_library(PhysicsEngine
    src/Vector2.cpp
    include/Vector2.hpp
)

# Tell the library where its own headers are
target_include_directories(PhysicsEngine PUBLIC include)

# Ensure threading is linked (Required for Phase 4 of your project)
find_package(Threads REQUIRED)
target_link_libraries(PhysicsEngine PRIVATE Threads::Threads)

# ---------------------------------------------------------------------------
# 2. Main Executable (The actual "Billiards" app)
# ---------------------------------------------------------------------------
add_executable(BilliardsApp src/main.cpp)
target_link_libraries(BilliardsApp PRIVATE PhysicsEngine)

# ---------------------------------------------------------------------------
# 3. Test Suite (Catch2 Integration)
# ---------------------------------------------------------------------------
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # Or the latest stable version
)

FetchContent_MakeAvailable(Catch2)

# Create the test executable
add_executable(PhysicsTests tests/test_vector.cpp)

# Link against Catch2 and your Physics Library
# Note: Catch2::Catch2WithMain provides a default main() for tests
target_link_libraries(PhysicsTests PRIVATE Catch2::Catch2WithMain PhysicsEngine)

# Enable CTest (allows you to run 'ctest' from the build folder)
include(CTest)
add_test(NAME AllPhysicsTests COMMAND PhysicsTests)