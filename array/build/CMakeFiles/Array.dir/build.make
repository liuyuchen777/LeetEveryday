# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/Local_Lab/leetcode/array

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Local_Lab/leetcode/array/build

# Include any dependencies generated for this target.
include CMakeFiles/Array.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Array.dir/flags.make

CMakeFiles/Array.dir/array.cpp.o: CMakeFiles/Array.dir/flags.make
CMakeFiles/Array.dir/array.cpp.o: ../array.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Local_Lab/leetcode/array/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Array.dir/array.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Array.dir/array.cpp.o -c /mnt/d/Local_Lab/leetcode/array/array.cpp

CMakeFiles/Array.dir/array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Array.dir/array.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Local_Lab/leetcode/array/array.cpp > CMakeFiles/Array.dir/array.cpp.i

CMakeFiles/Array.dir/array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Array.dir/array.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Local_Lab/leetcode/array/array.cpp -o CMakeFiles/Array.dir/array.cpp.s

# Object files for target Array
Array_OBJECTS = \
"CMakeFiles/Array.dir/array.cpp.o"

# External object files for target Array
Array_EXTERNAL_OBJECTS =

Array: CMakeFiles/Array.dir/array.cpp.o
Array: CMakeFiles/Array.dir/build.make
Array: /usr/local/lib/libgtest.a
Array: /usr/local/lib/libgtest_main.a
Array: CMakeFiles/Array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Local_Lab/leetcode/array/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Array"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Array.dir/build: Array

.PHONY : CMakeFiles/Array.dir/build

CMakeFiles/Array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Array.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Array.dir/clean

CMakeFiles/Array.dir/depend:
	cd /mnt/d/Local_Lab/leetcode/array/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Local_Lab/leetcode/array /mnt/d/Local_Lab/leetcode/array /mnt/d/Local_Lab/leetcode/array/build /mnt/d/Local_Lab/leetcode/array/build /mnt/d/Local_Lab/leetcode/array/build/CMakeFiles/Array.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Array.dir/depend
