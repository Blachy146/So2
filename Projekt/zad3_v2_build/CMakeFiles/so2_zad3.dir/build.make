# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /home/bmalecki/Projects/So2/Projekt/zad3_v2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bmalecki/Projects/So2/Projekt/zad3_v2_build

# Include any dependencies generated for this target.
include CMakeFiles/so2_zad3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/so2_zad3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/so2_zad3.dir/flags.make

CMakeFiles/so2_zad3.dir/source/main.cpp.o: CMakeFiles/so2_zad3.dir/flags.make
CMakeFiles/so2_zad3.dir/source/main.cpp.o: /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bmalecki/Projects/So2/Projekt/zad3_v2_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/so2_zad3.dir/source/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/so2_zad3.dir/source/main.cpp.o -c /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/main.cpp

CMakeFiles/so2_zad3.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/so2_zad3.dir/source/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/main.cpp > CMakeFiles/so2_zad3.dir/source/main.cpp.i

CMakeFiles/so2_zad3.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/so2_zad3.dir/source/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/main.cpp -o CMakeFiles/so2_zad3.dir/source/main.cpp.s

# Object files for target so2_zad3
so2_zad3_OBJECTS = \
"CMakeFiles/so2_zad3.dir/source/main.cpp.o"

# External object files for target so2_zad3
so2_zad3_EXTERNAL_OBJECTS =

so2_zad3: CMakeFiles/so2_zad3.dir/source/main.cpp.o
so2_zad3: CMakeFiles/so2_zad3.dir/build.make
so2_zad3: libso2_zad3-lib.a
so2_zad3: CMakeFiles/so2_zad3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bmalecki/Projects/So2/Projekt/zad3_v2_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable so2_zad3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/so2_zad3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/so2_zad3.dir/build: so2_zad3

.PHONY : CMakeFiles/so2_zad3.dir/build

CMakeFiles/so2_zad3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/so2_zad3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/so2_zad3.dir/clean

CMakeFiles/so2_zad3.dir/depend:
	cd /home/bmalecki/Projects/So2/Projekt/zad3_v2_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bmalecki/Projects/So2/Projekt/zad3_v2 /home/bmalecki/Projects/So2/Projekt/zad3_v2 /home/bmalecki/Projects/So2/Projekt/zad3_v2_build /home/bmalecki/Projects/So2/Projekt/zad3_v2_build /home/bmalecki/Projects/So2/Projekt/zad3_v2_build/CMakeFiles/so2_zad3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/so2_zad3.dir/depend

