# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\cmake-3.26.0-rc5-windows-x86_64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\cmake-3.26.0-rc5-windows-x86_64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\project-practice\learn_C++\CPlusPlus_projects\Computer-Room-Reservation-System

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\project-practice\learn_C++\CPlusPlus_projects\Computer-Room-Reservation-System\build

# Include any dependencies generated for this target.
include CMakeFiles/computer-system.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/computer-system.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/computer-system.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/computer-system.dir/flags.make

CMakeFiles/computer-system.dir/main.cpp.obj: CMakeFiles/computer-system.dir/flags.make
CMakeFiles/computer-system.dir/main.cpp.obj: CMakeFiles/computer-system.dir/includes_CXX.rsp
CMakeFiles/computer-system.dir/main.cpp.obj: D:/project-practice/learn_C++/CPlusPlus_projects/Computer-Room-Reservation-System/main.cpp
CMakeFiles/computer-system.dir/main.cpp.obj: CMakeFiles/computer-system.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\project-practice\learn_C++\CPlusPlus_projects\Computer-Room-Reservation-System\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/computer-system.dir/main.cpp.obj"
	D:\Dev-Cpp\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/computer-system.dir/main.cpp.obj -MF CMakeFiles\computer-system.dir\main.cpp.obj.d -o CMakeFiles\computer-system.dir\main.cpp.obj -c D:\project-practice\learn_C++\CPlusPlus_projects\Computer-Room-Reservation-System\main.cpp

CMakeFiles/computer-system.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/computer-system.dir/main.cpp.i"
	D:\Dev-Cpp\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\project-practice\learn_C++\CPlusPlus_projects\Computer-Room-Reservation-System\main.cpp > CMakeFiles\computer-system.dir\main.cpp.i

CMakeFiles/computer-system.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/computer-system.dir/main.cpp.s"
	D:\Dev-Cpp\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\project-practice\learn_C++\CPlusPlus_projects\Computer-Room-Reservation-System\main.cpp -o CMakeFiles\computer-system.dir\main.cpp.s

# Object files for target computer-system
computer__system_OBJECTS = \
"CMakeFiles/computer-system.dir/main.cpp.obj"

# External object files for target computer-system
computer__system_EXTERNAL_OBJECTS =

computer-system.exe: CMakeFiles/computer-system.dir/main.cpp.obj
computer-system.exe: CMakeFiles/computer-system.dir/build.make
computer-system.exe: CMakeFiles/computer-system.dir/linkLibs.rsp
computer-system.exe: CMakeFiles/computer-system.dir/objects1.rsp
computer-system.exe: CMakeFiles/computer-system.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\project-practice\learn_C++\CPlusPlus_projects\Computer-Room-Reservation-System\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable computer-system.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\computer-system.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/computer-system.dir/build: computer-system.exe
.PHONY : CMakeFiles/computer-system.dir/build

CMakeFiles/computer-system.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\computer-system.dir\cmake_clean.cmake
.PHONY : CMakeFiles/computer-system.dir/clean

CMakeFiles/computer-system.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\project-practice\learn_C++\CPlusPlus_projects\Computer-Room-Reservation-System D:\project-practice\learn_C++\CPlusPlus_projects\Computer-Room-Reservation-System D:\project-practice\learn_C++\CPlusPlus_projects\Computer-Room-Reservation-System\build D:\project-practice\learn_C++\CPlusPlus_projects\Computer-Room-Reservation-System\build D:\project-practice\learn_C++\CPlusPlus_projects\Computer-Room-Reservation-System\build\CMakeFiles\computer-system.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/computer-system.dir/depend
