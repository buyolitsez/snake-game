# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/152/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/152/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/buyolitsez/CLionProjects/snake-game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/buyolitsez/CLionProjects/snake-game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/snake_game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/snake_game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/snake_game.dir/flags.make

CMakeFiles/snake_game.dir/main.cpp.o: CMakeFiles/snake_game.dir/flags.make
CMakeFiles/snake_game.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/buyolitsez/CLionProjects/snake-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/snake_game.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snake_game.dir/main.cpp.o -c /home/buyolitsez/CLionProjects/snake-game/main.cpp

CMakeFiles/snake_game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake_game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/buyolitsez/CLionProjects/snake-game/main.cpp > CMakeFiles/snake_game.dir/main.cpp.i

CMakeFiles/snake_game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake_game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/buyolitsez/CLionProjects/snake-game/main.cpp -o CMakeFiles/snake_game.dir/main.cpp.s

CMakeFiles/snake_game.dir/map.cpp.o: CMakeFiles/snake_game.dir/flags.make
CMakeFiles/snake_game.dir/map.cpp.o: ../map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/buyolitsez/CLionProjects/snake-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/snake_game.dir/map.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snake_game.dir/map.cpp.o -c /home/buyolitsez/CLionProjects/snake-game/map.cpp

CMakeFiles/snake_game.dir/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake_game.dir/map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/buyolitsez/CLionProjects/snake-game/map.cpp > CMakeFiles/snake_game.dir/map.cpp.i

CMakeFiles/snake_game.dir/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake_game.dir/map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/buyolitsez/CLionProjects/snake-game/map.cpp -o CMakeFiles/snake_game.dir/map.cpp.s

# Object files for target snake_game
snake_game_OBJECTS = \
"CMakeFiles/snake_game.dir/main.cpp.o" \
"CMakeFiles/snake_game.dir/map.cpp.o"

# External object files for target snake_game
snake_game_EXTERNAL_OBJECTS =

snake_game: CMakeFiles/snake_game.dir/main.cpp.o
snake_game: CMakeFiles/snake_game.dir/map.cpp.o
snake_game: CMakeFiles/snake_game.dir/build.make
snake_game: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
snake_game: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.5.1
snake_game: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
snake_game: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
snake_game: CMakeFiles/snake_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/buyolitsez/CLionProjects/snake-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable snake_game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/snake_game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/snake_game.dir/build: snake_game

.PHONY : CMakeFiles/snake_game.dir/build

CMakeFiles/snake_game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/snake_game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/snake_game.dir/clean

CMakeFiles/snake_game.dir/depend:
	cd /home/buyolitsez/CLionProjects/snake-game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/buyolitsez/CLionProjects/snake-game /home/buyolitsez/CLionProjects/snake-game /home/buyolitsez/CLionProjects/snake-game/cmake-build-debug /home/buyolitsez/CLionProjects/snake-game/cmake-build-debug /home/buyolitsez/CLionProjects/snake-game/cmake-build-debug/CMakeFiles/snake_game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/snake_game.dir/depend

