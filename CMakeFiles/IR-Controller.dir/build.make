# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/jdss/ir-controller_ws/IR-Controller

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jdss/ir-controller_ws/IR-Controller

# Include any dependencies generated for this target.
include CMakeFiles/IR-Controller.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IR-Controller.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IR-Controller.dir/flags.make

CMakeFiles/IR-Controller.dir/src/main.cpp.o: CMakeFiles/IR-Controller.dir/flags.make
CMakeFiles/IR-Controller.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jdss/ir-controller_ws/IR-Controller/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IR-Controller.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IR-Controller.dir/src/main.cpp.o -c /home/jdss/ir-controller_ws/IR-Controller/src/main.cpp

CMakeFiles/IR-Controller.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IR-Controller.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jdss/ir-controller_ws/IR-Controller/src/main.cpp > CMakeFiles/IR-Controller.dir/src/main.cpp.i

CMakeFiles/IR-Controller.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IR-Controller.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jdss/ir-controller_ws/IR-Controller/src/main.cpp -o CMakeFiles/IR-Controller.dir/src/main.cpp.s

CMakeFiles/IR-Controller.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/IR-Controller.dir/src/main.cpp.o.requires

CMakeFiles/IR-Controller.dir/src/main.cpp.o.provides: CMakeFiles/IR-Controller.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/IR-Controller.dir/build.make CMakeFiles/IR-Controller.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/IR-Controller.dir/src/main.cpp.o.provides

CMakeFiles/IR-Controller.dir/src/main.cpp.o.provides.build: CMakeFiles/IR-Controller.dir/src/main.cpp.o


# Object files for target IR-Controller
IR__Controller_OBJECTS = \
"CMakeFiles/IR-Controller.dir/src/main.cpp.o"

# External object files for target IR-Controller
IR__Controller_EXTERNAL_OBJECTS =

IR-Controller: CMakeFiles/IR-Controller.dir/src/main.cpp.o
IR-Controller: CMakeFiles/IR-Controller.dir/build.make
IR-Controller: libIR-Controller-Utils.a
IR-Controller: CMakeFiles/IR-Controller.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jdss/ir-controller_ws/IR-Controller/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable IR-Controller"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IR-Controller.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IR-Controller.dir/build: IR-Controller

.PHONY : CMakeFiles/IR-Controller.dir/build

CMakeFiles/IR-Controller.dir/requires: CMakeFiles/IR-Controller.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/IR-Controller.dir/requires

CMakeFiles/IR-Controller.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IR-Controller.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IR-Controller.dir/clean

CMakeFiles/IR-Controller.dir/depend:
	cd /home/jdss/ir-controller_ws/IR-Controller && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jdss/ir-controller_ws/IR-Controller /home/jdss/ir-controller_ws/IR-Controller /home/jdss/ir-controller_ws/IR-Controller /home/jdss/ir-controller_ws/IR-Controller /home/jdss/ir-controller_ws/IR-Controller/CMakeFiles/IR-Controller.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IR-Controller.dir/depend
