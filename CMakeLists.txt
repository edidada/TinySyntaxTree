cmake_minimum_required(VERSION 3.16)  # Minimum CMake version for Qt support

project(compiler_lab_3 LANGUAGES CXX)  # Project name and language

# Enable automatic processing of Qt files
set(CMAKE_AUTOMOC ON)  # Auto-generate moc files for Qt classes
set(CMAKE_AUTORCC ON)  # Auto-handle resource (.qrc) files, if any
set(CMAKE_AUTOUIC ON)  # Auto-process .ui files

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)  # Use C++17 for modern Qt projects
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)  # Fallback to Qt5

# Define source files
set(PROJECT_SOURCES
        code/compiler_lab_3/scan.h
        code/compiler_lab_3/analyse.cpp
        code/compiler_lab_3/main.cpp
        code/compiler_lab_3/parse.cpp
        code/compiler_lab_3/scan.cpp
        code/compiler_lab_3/util.cpp
        code/compiler_lab_3/widget.cpp
        code/compiler_lab_3/widget.h
        code/compiler_lab_3/widget.ui
)

# Create executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Link Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)

# Set include directories (if needed)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})  # For ui_widget.h

# Platform-specific settings for Windows/MSVC
if (MSVC)
    # Ensure MSVC uses UTF-8 for source files (avoid encoding issues)
    target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
    # Set runtime library to MultiThreaded (consistent with Qt builds)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# Install target (optional, for packaging)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)