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
CMAKE_BINARY_DIR = /home/bmalecki/Projects/So2/Projekt/build-zad3_v2-Desktop-Default

# Include any dependencies generated for this target.
include CMakeFiles/so2_zad3-lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/so2_zad3-lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/so2_zad3-lib.dir/flags.make

CMakeFiles/so2_zad3-lib.dir/source/Building.cpp.o: CMakeFiles/so2_zad3-lib.dir/flags.make
CMakeFiles/so2_zad3-lib.dir/source/Building.cpp.o: /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Building.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bmalecki/Projects/So2/Projekt/build-zad3_v2-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/so2_zad3-lib.dir/source/Building.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/so2_zad3-lib.dir/source/Building.cpp.o -c /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Building.cpp

CMakeFiles/so2_zad3-lib.dir/source/Building.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/so2_zad3-lib.dir/source/Building.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Building.cpp > CMakeFiles/so2_zad3-lib.dir/source/Building.cpp.i

CMakeFiles/so2_zad3-lib.dir/source/Building.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/so2_zad3-lib.dir/source/Building.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Building.cpp -o CMakeFiles/so2_zad3-lib.dir/source/Building.cpp.s

CMakeFiles/so2_zad3-lib.dir/source/Person.cpp.o: CMakeFiles/so2_zad3-lib.dir/flags.make
CMakeFiles/so2_zad3-lib.dir/source/Person.cpp.o: /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Person.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bmalecki/Projects/So2/Projekt/build-zad3_v2-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/so2_zad3-lib.dir/source/Person.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/so2_zad3-lib.dir/source/Person.cpp.o -c /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Person.cpp

CMakeFiles/so2_zad3-lib.dir/source/Person.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/so2_zad3-lib.dir/source/Person.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Person.cpp > CMakeFiles/so2_zad3-lib.dir/source/Person.cpp.i

CMakeFiles/so2_zad3-lib.dir/source/Person.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/so2_zad3-lib.dir/source/Person.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Person.cpp -o CMakeFiles/so2_zad3-lib.dir/source/Person.cpp.s

CMakeFiles/so2_zad3-lib.dir/source/Queue.cpp.o: CMakeFiles/so2_zad3-lib.dir/flags.make
CMakeFiles/so2_zad3-lib.dir/source/Queue.cpp.o: /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Queue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bmalecki/Projects/So2/Projekt/build-zad3_v2-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/so2_zad3-lib.dir/source/Queue.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/so2_zad3-lib.dir/source/Queue.cpp.o -c /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Queue.cpp

CMakeFiles/so2_zad3-lib.dir/source/Queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/so2_zad3-lib.dir/source/Queue.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Queue.cpp > CMakeFiles/so2_zad3-lib.dir/source/Queue.cpp.i

CMakeFiles/so2_zad3-lib.dir/source/Queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/so2_zad3-lib.dir/source/Queue.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Queue.cpp -o CMakeFiles/so2_zad3-lib.dir/source/Queue.cpp.s

CMakeFiles/so2_zad3-lib.dir/source/Elevator.cpp.o: CMakeFiles/so2_zad3-lib.dir/flags.make
CMakeFiles/so2_zad3-lib.dir/source/Elevator.cpp.o: /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Elevator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bmalecki/Projects/So2/Projekt/build-zad3_v2-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/so2_zad3-lib.dir/source/Elevator.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/so2_zad3-lib.dir/source/Elevator.cpp.o -c /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Elevator.cpp

CMakeFiles/so2_zad3-lib.dir/source/Elevator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/so2_zad3-lib.dir/source/Elevator.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Elevator.cpp > CMakeFiles/so2_zad3-lib.dir/source/Elevator.cpp.i

CMakeFiles/so2_zad3-lib.dir/source/Elevator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/so2_zad3-lib.dir/source/Elevator.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bmalecki/Projects/So2/Projekt/zad3_v2/source/Elevator.cpp -o CMakeFiles/so2_zad3-lib.dir/source/Elevator.cpp.s

# Object files for target so2_zad3-lib
so2_zad3__lib_OBJECTS = \
"CMakeFiles/so2_zad3-lib.dir/source/Building.cpp.o" \
"CMakeFiles/so2_zad3-lib.dir/source/Person.cpp.o" \
"CMakeFiles/so2_zad3-lib.dir/source/Queue.cpp.o" \
"CMakeFiles/so2_zad3-lib.dir/source/Elevator.cpp.o"

# External object files for target so2_zad3-lib
so2_zad3__lib_EXTERNAL_OBJECTS =

libso2_zad3-lib.a: CMakeFiles/so2_zad3-lib.dir/source/Building.cpp.o
libso2_zad3-lib.a: CMakeFiles/so2_zad3-lib.dir/source/Person.cpp.o
libso2_zad3-lib.a: CMakeFiles/so2_zad3-lib.dir/source/Queue.cpp.o
libso2_zad3-lib.a: CMakeFiles/so2_zad3-lib.dir/source/Elevator.cpp.o
libso2_zad3-lib.a: CMakeFiles/so2_zad3-lib.dir/build.make
libso2_zad3-lib.a: CMakeFiles/so2_zad3-lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bmalecki/Projects/So2/Projekt/build-zad3_v2-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libso2_zad3-lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/so2_zad3-lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/so2_zad3-lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/so2_zad3-lib.dir/build: libso2_zad3-lib.a

.PHONY : CMakeFiles/so2_zad3-lib.dir/build

CMakeFiles/so2_zad3-lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/so2_zad3-lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/so2_zad3-lib.dir/clean

CMakeFiles/so2_zad3-lib.dir/depend:
	cd /home/bmalecki/Projects/So2/Projekt/build-zad3_v2-Desktop-Default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bmalecki/Projects/So2/Projekt/zad3_v2 /home/bmalecki/Projects/So2/Projekt/zad3_v2 /home/bmalecki/Projects/So2/Projekt/build-zad3_v2-Desktop-Default /home/bmalecki/Projects/So2/Projekt/build-zad3_v2-Desktop-Default /home/bmalecki/Projects/So2/Projekt/build-zad3_v2-Desktop-Default/CMakeFiles/so2_zad3-lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/so2_zad3-lib.dir/depend

