# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chengu/git/cs424/as/as1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chengu/git/cs424/as/as1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/as1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/as1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/as1.dir/flags.make

CMakeFiles/as1.dir/dummy.c.o: CMakeFiles/as1.dir/flags.make
CMakeFiles/as1.dir/dummy.c.o: ../dummy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chengu/git/cs424/as/as1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/as1.dir/dummy.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/as1.dir/dummy.c.o   -c /Users/chengu/git/cs424/as/as1/dummy.c

CMakeFiles/as1.dir/dummy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/as1.dir/dummy.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/chengu/git/cs424/as/as1/dummy.c > CMakeFiles/as1.dir/dummy.c.i

CMakeFiles/as1.dir/dummy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/as1.dir/dummy.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/chengu/git/cs424/as/as1/dummy.c -o CMakeFiles/as1.dir/dummy.c.s

CMakeFiles/as1.dir/dummy.c.o.requires:

.PHONY : CMakeFiles/as1.dir/dummy.c.o.requires

CMakeFiles/as1.dir/dummy.c.o.provides: CMakeFiles/as1.dir/dummy.c.o.requires
	$(MAKE) -f CMakeFiles/as1.dir/build.make CMakeFiles/as1.dir/dummy.c.o.provides.build
.PHONY : CMakeFiles/as1.dir/dummy.c.o.provides

CMakeFiles/as1.dir/dummy.c.o.provides.build: CMakeFiles/as1.dir/dummy.c.o


CMakeFiles/as1.dir/ex1.c.o: CMakeFiles/as1.dir/flags.make
CMakeFiles/as1.dir/ex1.c.o: ../ex1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chengu/git/cs424/as/as1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/as1.dir/ex1.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/as1.dir/ex1.c.o   -c /Users/chengu/git/cs424/as/as1/ex1.c

CMakeFiles/as1.dir/ex1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/as1.dir/ex1.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/chengu/git/cs424/as/as1/ex1.c > CMakeFiles/as1.dir/ex1.c.i

CMakeFiles/as1.dir/ex1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/as1.dir/ex1.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/chengu/git/cs424/as/as1/ex1.c -o CMakeFiles/as1.dir/ex1.c.s

CMakeFiles/as1.dir/ex1.c.o.requires:

.PHONY : CMakeFiles/as1.dir/ex1.c.o.requires

CMakeFiles/as1.dir/ex1.c.o.provides: CMakeFiles/as1.dir/ex1.c.o.requires
	$(MAKE) -f CMakeFiles/as1.dir/build.make CMakeFiles/as1.dir/ex1.c.o.provides.build
.PHONY : CMakeFiles/as1.dir/ex1.c.o.provides

CMakeFiles/as1.dir/ex1.c.o.provides.build: CMakeFiles/as1.dir/ex1.c.o


CMakeFiles/as1.dir/ex2.c.o: CMakeFiles/as1.dir/flags.make
CMakeFiles/as1.dir/ex2.c.o: ../ex2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chengu/git/cs424/as/as1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/as1.dir/ex2.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/as1.dir/ex2.c.o   -c /Users/chengu/git/cs424/as/as1/ex2.c

CMakeFiles/as1.dir/ex2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/as1.dir/ex2.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/chengu/git/cs424/as/as1/ex2.c > CMakeFiles/as1.dir/ex2.c.i

CMakeFiles/as1.dir/ex2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/as1.dir/ex2.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/chengu/git/cs424/as/as1/ex2.c -o CMakeFiles/as1.dir/ex2.c.s

CMakeFiles/as1.dir/ex2.c.o.requires:

.PHONY : CMakeFiles/as1.dir/ex2.c.o.requires

CMakeFiles/as1.dir/ex2.c.o.provides: CMakeFiles/as1.dir/ex2.c.o.requires
	$(MAKE) -f CMakeFiles/as1.dir/build.make CMakeFiles/as1.dir/ex2.c.o.provides.build
.PHONY : CMakeFiles/as1.dir/ex2.c.o.provides

CMakeFiles/as1.dir/ex2.c.o.provides.build: CMakeFiles/as1.dir/ex2.c.o


CMakeFiles/as1.dir/timing.c.o: CMakeFiles/as1.dir/flags.make
CMakeFiles/as1.dir/timing.c.o: ../timing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chengu/git/cs424/as/as1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/as1.dir/timing.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/as1.dir/timing.c.o   -c /Users/chengu/git/cs424/as/as1/timing.c

CMakeFiles/as1.dir/timing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/as1.dir/timing.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/chengu/git/cs424/as/as1/timing.c > CMakeFiles/as1.dir/timing.c.i

CMakeFiles/as1.dir/timing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/as1.dir/timing.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/chengu/git/cs424/as/as1/timing.c -o CMakeFiles/as1.dir/timing.c.s

CMakeFiles/as1.dir/timing.c.o.requires:

.PHONY : CMakeFiles/as1.dir/timing.c.o.requires

CMakeFiles/as1.dir/timing.c.o.provides: CMakeFiles/as1.dir/timing.c.o.requires
	$(MAKE) -f CMakeFiles/as1.dir/build.make CMakeFiles/as1.dir/timing.c.o.provides.build
.PHONY : CMakeFiles/as1.dir/timing.c.o.provides

CMakeFiles/as1.dir/timing.c.o.provides.build: CMakeFiles/as1.dir/timing.c.o


# Object files for target as1
as1_OBJECTS = \
"CMakeFiles/as1.dir/dummy.c.o" \
"CMakeFiles/as1.dir/ex1.c.o" \
"CMakeFiles/as1.dir/ex2.c.o" \
"CMakeFiles/as1.dir/timing.c.o"

# External object files for target as1
as1_EXTERNAL_OBJECTS =

as1: CMakeFiles/as1.dir/dummy.c.o
as1: CMakeFiles/as1.dir/ex1.c.o
as1: CMakeFiles/as1.dir/ex2.c.o
as1: CMakeFiles/as1.dir/timing.c.o
as1: CMakeFiles/as1.dir/build.make
as1: CMakeFiles/as1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chengu/git/cs424/as/as1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable as1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/as1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/as1.dir/build: as1

.PHONY : CMakeFiles/as1.dir/build

CMakeFiles/as1.dir/requires: CMakeFiles/as1.dir/dummy.c.o.requires
CMakeFiles/as1.dir/requires: CMakeFiles/as1.dir/ex1.c.o.requires
CMakeFiles/as1.dir/requires: CMakeFiles/as1.dir/ex2.c.o.requires
CMakeFiles/as1.dir/requires: CMakeFiles/as1.dir/timing.c.o.requires

.PHONY : CMakeFiles/as1.dir/requires

CMakeFiles/as1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/as1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/as1.dir/clean

CMakeFiles/as1.dir/depend:
	cd /Users/chengu/git/cs424/as/as1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chengu/git/cs424/as/as1 /Users/chengu/git/cs424/as/as1 /Users/chengu/git/cs424/as/as1/cmake-build-debug /Users/chengu/git/cs424/as/as1/cmake-build-debug /Users/chengu/git/cs424/as/as1/cmake-build-debug/CMakeFiles/as1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/as1.dir/depend

