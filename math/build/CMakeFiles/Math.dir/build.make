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
CMAKE_SOURCE_DIR = /mnt/d/Local_Lab/LeetEveryday/math

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Local_Lab/LeetEveryday/math/build

# Include any dependencies generated for this target.
include CMakeFiles/Math.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Math.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Math.dir/flags.make

CMakeFiles/Math.dir/test.cpp.o: CMakeFiles/Math.dir/flags.make
CMakeFiles/Math.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Local_Lab/LeetEveryday/math/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Math.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Math.dir/test.cpp.o -c /mnt/d/Local_Lab/LeetEveryday/math/test.cpp

CMakeFiles/Math.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Math.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Local_Lab/LeetEveryday/math/test.cpp > CMakeFiles/Math.dir/test.cpp.i

CMakeFiles/Math.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Math.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Local_Lab/LeetEveryday/math/test.cpp -o CMakeFiles/Math.dir/test.cpp.s

# Object files for target Math
Math_OBJECTS = \
"CMakeFiles/Math.dir/test.cpp.o"

# External object files for target Math
Math_EXTERNAL_OBJECTS =

Math: CMakeFiles/Math.dir/test.cpp.o
Math: CMakeFiles/Math.dir/build.make
Math: /usr/local/lib/libgtest.a
Math: /usr/local/lib/libgtest_main.a
Math: CMakeFiles/Math.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Local_Lab/LeetEveryday/math/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Math"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Math.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Math.dir/build: Math

.PHONY : CMakeFiles/Math.dir/build

CMakeFiles/Math.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Math.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Math.dir/clean

CMakeFiles/Math.dir/depend:
	cd /mnt/d/Local_Lab/LeetEveryday/math/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Local_Lab/LeetEveryday/math /mnt/d/Local_Lab/LeetEveryday/math /mnt/d/Local_Lab/LeetEveryday/math/build /mnt/d/Local_Lab/LeetEveryday/math/build /mnt/d/Local_Lab/LeetEveryday/math/build/CMakeFiles/Math.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Math.dir/depend

