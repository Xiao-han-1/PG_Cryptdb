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
include Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/compiler_depend.make

# Include the progress variables for this target.
include Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/flags.make

Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/ret0.cxx.o: Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/flags.make
Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/ret0.cxx.o: Tests/CMakeLib/PseudoMemcheck/ret0.cxx
Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/ret0.cxx.o: Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/pakages/copy/cryptdb/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/ret0.cxx.o"
	cd /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/CMakeLib/PseudoMemcheck && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/ret0.cxx.o -MF CMakeFiles/pseudo_valgrind.dir/ret0.cxx.o.d -o CMakeFiles/pseudo_valgrind.dir/ret0.cxx.o -c /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/CMakeLib/PseudoMemcheck/ret0.cxx

Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/ret0.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pseudo_valgrind.dir/ret0.cxx.i"
	cd /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/CMakeLib/PseudoMemcheck && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/CMakeLib/PseudoMemcheck/ret0.cxx > CMakeFiles/pseudo_valgrind.dir/ret0.cxx.i

Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/ret0.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pseudo_valgrind.dir/ret0.cxx.s"
	cd /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/CMakeLib/PseudoMemcheck && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/CMakeLib/PseudoMemcheck/ret0.cxx -o CMakeFiles/pseudo_valgrind.dir/ret0.cxx.s

# Object files for target pseudo_valgrind
pseudo_valgrind_OBJECTS = \
"CMakeFiles/pseudo_valgrind.dir/ret0.cxx.o"

# External object files for target pseudo_valgrind
pseudo_valgrind_EXTERNAL_OBJECTS =

Tests/CMakeLib/PseudoMemcheck/valgrind: Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/ret0.cxx.o
Tests/CMakeLib/PseudoMemcheck/valgrind: Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/build.make
Tests/CMakeLib/PseudoMemcheck/valgrind: Source/libCMakeLib.a
Tests/CMakeLib/PseudoMemcheck/valgrind: Source/kwsys/libcmsys.a
Tests/CMakeLib/PseudoMemcheck/valgrind: Utilities/std/libcmstd.a
Tests/CMakeLib/PseudoMemcheck/valgrind: Utilities/cmexpat/libcmexpat.a
Tests/CMakeLib/PseudoMemcheck/valgrind: Utilities/cmlibarchive/libarchive/libcmlibarchive.a
Tests/CMakeLib/PseudoMemcheck/valgrind: Utilities/cmliblzma/libcmliblzma.a
Tests/CMakeLib/PseudoMemcheck/valgrind: Utilities/cmzstd/libcmzstd.a
Tests/CMakeLib/PseudoMemcheck/valgrind: Utilities/cmbzip2/libcmbzip2.a
Tests/CMakeLib/PseudoMemcheck/valgrind: Utilities/cmcurl/lib/libcmcurl.a
Tests/CMakeLib/PseudoMemcheck/valgrind: Utilities/cmzlib/libcmzlib.a
Tests/CMakeLib/PseudoMemcheck/valgrind: /usr/lib/x86_64-linux-gnu/libssl.so
Tests/CMakeLib/PseudoMemcheck/valgrind: /usr/lib/x86_64-linux-gnu/libcrypto.so
Tests/CMakeLib/PseudoMemcheck/valgrind: Utilities/cmnghttp2/libcmnghttp2.a
Tests/CMakeLib/PseudoMemcheck/valgrind: Utilities/cmjsoncpp/libcmjsoncpp.a
Tests/CMakeLib/PseudoMemcheck/valgrind: Utilities/cmlibuv/libcmlibuv.a
Tests/CMakeLib/PseudoMemcheck/valgrind: Utilities/cmlibrhash/libcmlibrhash.a
Tests/CMakeLib/PseudoMemcheck/valgrind: Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/pakages/copy/cryptdb/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable valgrind"
	cd /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/CMakeLib/PseudoMemcheck && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pseudo_valgrind.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/build: Tests/CMakeLib/PseudoMemcheck/valgrind
.PHONY : Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/build

Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/clean:
	cd /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/CMakeLib/PseudoMemcheck && $(CMAKE_COMMAND) -P CMakeFiles/pseudo_valgrind.dir/cmake_clean.cmake
.PHONY : Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/clean

Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/depend:
	cd /root/pakages/copy/cryptdb/cmake-3.24.2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/pakages/copy/cryptdb/cmake-3.24.2 /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/CMakeLib/PseudoMemcheck /root/pakages/copy/cryptdb/cmake-3.24.2 /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/CMakeLib/PseudoMemcheck /root/pakages/copy/cryptdb/cmake-3.24.2/Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/CMakeLib/PseudoMemcheck/CMakeFiles/pseudo_valgrind.dir/depend
