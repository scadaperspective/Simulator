# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Ron/Tactics/Simulator_pi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Ron/Tactics/Simulator_pi/build

# Utility rule file for create-pkg.

# Include the progress variables for this target.
include CMakeFiles/create-pkg.dir/progress.make

CMakeFiles/create-pkg: Simulator-Plugin.pkg
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/Ron/Tactics/Simulator_pi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "create-pkg: Done."

Simulator-Plugin.pkg: libSimulator_pi.dylib
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/Ron/Tactics/Simulator_pi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "create-pkg [Simulator_pi]: Generating pkg file."
	/usr/local/bin/packagesbuild -F /Users/Ron/Tactics/Simulator_pi/build /Users/Ron/Tactics/Simulator_pi/build/Simulator.pkgproj

create-pkg: CMakeFiles/create-pkg
create-pkg: Simulator-Plugin.pkg
create-pkg: CMakeFiles/create-pkg.dir/build.make

.PHONY : create-pkg

# Rule to build all files generated by this target.
CMakeFiles/create-pkg.dir/build: create-pkg

.PHONY : CMakeFiles/create-pkg.dir/build

CMakeFiles/create-pkg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/create-pkg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/create-pkg.dir/clean

CMakeFiles/create-pkg.dir/depend:
	cd /Users/Ron/Tactics/Simulator_pi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Ron/Tactics/Simulator_pi /Users/Ron/Tactics/Simulator_pi /Users/Ron/Tactics/Simulator_pi/build /Users/Ron/Tactics/Simulator_pi/build /Users/Ron/Tactics/Simulator_pi/build/CMakeFiles/create-pkg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/create-pkg.dir/depend

