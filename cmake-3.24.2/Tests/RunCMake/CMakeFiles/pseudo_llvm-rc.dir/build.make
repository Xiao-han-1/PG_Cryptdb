# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /root/pakages/copy/cryptdb/cmake-3.24.2/Bootstrap.cmk/cmake

# The command to remove a file.
RM = /root/pakages/copy/cryptdb/cmake-3.24.2/Bootstrap.cmk/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/pakages/copy/cryptdb/cmake-3.24.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/pakages/copy/cryptdb/cmake-3.24.2

# Include any dependencies generated for this target.
include Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/compiler_depend.make

# Include the progress variables for this target.
include Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/flags.make

Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.o: Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/flags.make
Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.o: Tests/RunCMake/pseudo_llvm-rc.c
Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.o: Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/pakages/copy/cryptdb/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.o"
	cd /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/RunCMake && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.o -MF CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.o.d -o CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.o -c /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/RunCMake/pseudo_llvm-rc.c

Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.i"
	cd /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/RunCMake && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/RunCMake/pseudo_llvm-rc.c > CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.i

Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.s"
	cd /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/RunCMake && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/RunCMake/pseudo_llvm-rc.c -o CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.s

# Object files for target pseudo_llvm-rc
pseudo_llvm__rc_OBJECTS = \
"CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.o"

# External object files for target pseudo_llvm-rc
pseudo_llvm__rc_EXTERNAL_OBJECTS =

Tests/RunCMake/pseudo_llvm-rc: Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/pseudo_llvm-rc.c.o
Tests/RunCMake/pseudo_llvm-rc: Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/build.make
Tests/RunCMake/pseudo_llvm-rc: Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/pakages/copy/cryptdb/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pseudo_llvm-rc"
	cd /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/RunCMake && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pseudo_llvm-rc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/build: Tests/RunCMake/pseudo_llvm-rc
.PHONY : Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/build

Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/clean:
	cd /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/RunCMake && $(CMAKE_COMMAND) -P CMakeFiles/pseudo_llvm-rc.dir/cmake_clean.cmake
.PHONY : Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/clean

Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/depend:
	cd /root/pakages/copy/cryptdb/cmake-3.24.2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/pakages/copy/cryptdb/cmake-3.24.2 /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/RunCMake /root/pakages/copy/cryptdb/cmake-3.24.2 /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/RunCMake /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/RunCMake/CMakeFiles/pseudo_llvm-rc.dir/depend
