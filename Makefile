# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jdss/ir-controller_ws/IR-Controller/CMakeFiles /home/jdss/ir-controller_ws/IR-Controller/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jdss/ir-controller_ws/IR-Controller/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named IR_Controller-Utils

# Build rule for target.
IR_Controller-Utils: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 IR_Controller-Utils
.PHONY : IR_Controller-Utils

# fast build rule for target.
IR_Controller-Utils/fast:
	$(MAKE) -f CMakeFiles/IR_Controller-Utils.dir/build.make CMakeFiles/IR_Controller-Utils.dir/build
.PHONY : IR_Controller-Utils/fast

#=============================================================================
# Target rules for targets named IR_Controller.out

# Build rule for target.
IR_Controller.out: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 IR_Controller.out
.PHONY : IR_Controller.out

# fast build rule for target.
IR_Controller.out/fast:
	$(MAKE) -f CMakeFiles/IR_Controller.out.dir/build.make CMakeFiles/IR_Controller.out.dir/build
.PHONY : IR_Controller.out/fast

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/IR_Controller.out.dir/build.make CMakeFiles/IR_Controller.out.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/IR_Controller.out.dir/build.make CMakeFiles/IR_Controller.out.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/IR_Controller.out.dir/build.make CMakeFiles/IR_Controller.out.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/utils/utils.o: src/utils/utils.cpp.o

.PHONY : src/utils/utils.o

# target to build an object file
src/utils/utils.cpp.o:
	$(MAKE) -f CMakeFiles/IR_Controller-Utils.dir/build.make CMakeFiles/IR_Controller-Utils.dir/src/utils/utils.cpp.o
.PHONY : src/utils/utils.cpp.o

src/utils/utils.i: src/utils/utils.cpp.i

.PHONY : src/utils/utils.i

# target to preprocess a source file
src/utils/utils.cpp.i:
	$(MAKE) -f CMakeFiles/IR_Controller-Utils.dir/build.make CMakeFiles/IR_Controller-Utils.dir/src/utils/utils.cpp.i
.PHONY : src/utils/utils.cpp.i

src/utils/utils.s: src/utils/utils.cpp.s

.PHONY : src/utils/utils.s

# target to generate assembly for a file
src/utils/utils.cpp.s:
	$(MAKE) -f CMakeFiles/IR_Controller-Utils.dir/build.make CMakeFiles/IR_Controller-Utils.dir/src/utils/utils.cpp.s
.PHONY : src/utils/utils.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... IR_Controller-Utils"
	@echo "... rebuild_cache"
	@echo "... IR_Controller.out"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/utils/utils.o"
	@echo "... src/utils/utils.i"
	@echo "... src/utils/utils.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
