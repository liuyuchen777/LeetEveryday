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
CMAKE_SOURCE_DIR = /mnt/d/Users/Local_Lab/LeetEveryday/swordOffer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Users/Local_Lab/LeetEveryday/swordOffer/build

# Include any dependencies generated for this target.
include CMakeFiles/Offer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Offer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Offer.dir/flags.make

CMakeFiles/Offer.dir/test.cpp.o: CMakeFiles/Offer.dir/flags.make
CMakeFiles/Offer.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Users/Local_Lab/LeetEveryday/swordOffer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Offer.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Offer.dir/test.cpp.o -c /mnt/d/Users/Local_Lab/LeetEveryday/swordOffer/test.cpp

CMakeFiles/Offer.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Offer.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Users/Local_Lab/LeetEveryday/swordOffer/test.cpp > CMakeFiles/Offer.dir/test.cpp.i

CMakeFiles/Offer.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Offer.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Users/Local_Lab/LeetEveryday/swordOffer/test.cpp -o CMakeFiles/Offer.dir/test.cpp.s

# Object files for target Offer
Offer_OBJECTS = \
"CMakeFiles/Offer.dir/test.cpp.o"

# External object files for target Offer
Offer_EXTERNAL_OBJECTS =

Offer: CMakeFiles/Offer.dir/test.cpp.o
Offer: CMakeFiles/Offer.dir/build.make
Offer: /usr/local/lib/libgtest.a
Offer: /usr/local/lib/libgtest_main.a
Offer: CMakeFiles/Offer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Users/Local_Lab/LeetEveryday/swordOffer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Offer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Offer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Offer.dir/build: Offer

.PHONY : CMakeFiles/Offer.dir/build

CMakeFiles/Offer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Offer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Offer.dir/clean

CMakeFiles/Offer.dir/depend:
	cd /mnt/d/Users/Local_Lab/LeetEveryday/swordOffer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Users/Local_Lab/LeetEveryday/swordOffer /mnt/d/Users/Local_Lab/LeetEveryday/swordOffer /mnt/d/Users/Local_Lab/LeetEveryday/swordOffer/build /mnt/d/Users/Local_Lab/LeetEveryday/swordOffer/build /mnt/d/Users/Local_Lab/LeetEveryday/swordOffer/build/CMakeFiles/Offer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Offer.dir/depend
