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
CMAKE_SOURCE_DIR = /home/zachary/Projects/chessEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zachary/Projects/chessEngine/build

# Include any dependencies generated for this target.
include CMakeFiles/chessEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chessEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chessEngine.dir/flags.make

CMakeFiles/chessEngine.dir/src/bitboards.cpp.o: CMakeFiles/chessEngine.dir/flags.make
CMakeFiles/chessEngine.dir/src/bitboards.cpp.o: ../src/bitboards.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chessEngine.dir/src/bitboards.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chessEngine.dir/src/bitboards.cpp.o -c /home/zachary/Projects/chessEngine/src/bitboards.cpp

CMakeFiles/chessEngine.dir/src/bitboards.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessEngine.dir/src/bitboards.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/Projects/chessEngine/src/bitboards.cpp > CMakeFiles/chessEngine.dir/src/bitboards.cpp.i

CMakeFiles/chessEngine.dir/src/bitboards.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessEngine.dir/src/bitboards.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/Projects/chessEngine/src/bitboards.cpp -o CMakeFiles/chessEngine.dir/src/bitboards.cpp.s

CMakeFiles/chessEngine.dir/src/board.cpp.o: CMakeFiles/chessEngine.dir/flags.make
CMakeFiles/chessEngine.dir/src/board.cpp.o: ../src/board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chessEngine.dir/src/board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chessEngine.dir/src/board.cpp.o -c /home/zachary/Projects/chessEngine/src/board.cpp

CMakeFiles/chessEngine.dir/src/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessEngine.dir/src/board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/Projects/chessEngine/src/board.cpp > CMakeFiles/chessEngine.dir/src/board.cpp.i

CMakeFiles/chessEngine.dir/src/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessEngine.dir/src/board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/Projects/chessEngine/src/board.cpp -o CMakeFiles/chessEngine.dir/src/board.cpp.s

CMakeFiles/chessEngine.dir/src/evaluate.cpp.o: CMakeFiles/chessEngine.dir/flags.make
CMakeFiles/chessEngine.dir/src/evaluate.cpp.o: ../src/evaluate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chessEngine.dir/src/evaluate.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chessEngine.dir/src/evaluate.cpp.o -c /home/zachary/Projects/chessEngine/src/evaluate.cpp

CMakeFiles/chessEngine.dir/src/evaluate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessEngine.dir/src/evaluate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/Projects/chessEngine/src/evaluate.cpp > CMakeFiles/chessEngine.dir/src/evaluate.cpp.i

CMakeFiles/chessEngine.dir/src/evaluate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessEngine.dir/src/evaluate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/Projects/chessEngine/src/evaluate.cpp -o CMakeFiles/chessEngine.dir/src/evaluate.cpp.s

CMakeFiles/chessEngine.dir/src/helpers.cpp.o: CMakeFiles/chessEngine.dir/flags.make
CMakeFiles/chessEngine.dir/src/helpers.cpp.o: ../src/helpers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chessEngine.dir/src/helpers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chessEngine.dir/src/helpers.cpp.o -c /home/zachary/Projects/chessEngine/src/helpers.cpp

CMakeFiles/chessEngine.dir/src/helpers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessEngine.dir/src/helpers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/Projects/chessEngine/src/helpers.cpp > CMakeFiles/chessEngine.dir/src/helpers.cpp.i

CMakeFiles/chessEngine.dir/src/helpers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessEngine.dir/src/helpers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/Projects/chessEngine/src/helpers.cpp -o CMakeFiles/chessEngine.dir/src/helpers.cpp.s

CMakeFiles/chessEngine.dir/src/init.cpp.o: CMakeFiles/chessEngine.dir/flags.make
CMakeFiles/chessEngine.dir/src/init.cpp.o: ../src/init.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/chessEngine.dir/src/init.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chessEngine.dir/src/init.cpp.o -c /home/zachary/Projects/chessEngine/src/init.cpp

CMakeFiles/chessEngine.dir/src/init.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessEngine.dir/src/init.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/Projects/chessEngine/src/init.cpp > CMakeFiles/chessEngine.dir/src/init.cpp.i

CMakeFiles/chessEngine.dir/src/init.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessEngine.dir/src/init.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/Projects/chessEngine/src/init.cpp -o CMakeFiles/chessEngine.dir/src/init.cpp.s

CMakeFiles/chessEngine.dir/src/main.cpp.o: CMakeFiles/chessEngine.dir/flags.make
CMakeFiles/chessEngine.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/chessEngine.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chessEngine.dir/src/main.cpp.o -c /home/zachary/Projects/chessEngine/src/main.cpp

CMakeFiles/chessEngine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessEngine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/Projects/chessEngine/src/main.cpp > CMakeFiles/chessEngine.dir/src/main.cpp.i

CMakeFiles/chessEngine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessEngine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/Projects/chessEngine/src/main.cpp -o CMakeFiles/chessEngine.dir/src/main.cpp.s

CMakeFiles/chessEngine.dir/src/movegen.cpp.o: CMakeFiles/chessEngine.dir/flags.make
CMakeFiles/chessEngine.dir/src/movegen.cpp.o: ../src/movegen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/chessEngine.dir/src/movegen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chessEngine.dir/src/movegen.cpp.o -c /home/zachary/Projects/chessEngine/src/movegen.cpp

CMakeFiles/chessEngine.dir/src/movegen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessEngine.dir/src/movegen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/Projects/chessEngine/src/movegen.cpp > CMakeFiles/chessEngine.dir/src/movegen.cpp.i

CMakeFiles/chessEngine.dir/src/movegen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessEngine.dir/src/movegen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/Projects/chessEngine/src/movegen.cpp -o CMakeFiles/chessEngine.dir/src/movegen.cpp.s

CMakeFiles/chessEngine.dir/src/perfit.cpp.o: CMakeFiles/chessEngine.dir/flags.make
CMakeFiles/chessEngine.dir/src/perfit.cpp.o: ../src/perfit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/chessEngine.dir/src/perfit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chessEngine.dir/src/perfit.cpp.o -c /home/zachary/Projects/chessEngine/src/perfit.cpp

CMakeFiles/chessEngine.dir/src/perfit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessEngine.dir/src/perfit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/Projects/chessEngine/src/perfit.cpp > CMakeFiles/chessEngine.dir/src/perfit.cpp.i

CMakeFiles/chessEngine.dir/src/perfit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessEngine.dir/src/perfit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/Projects/chessEngine/src/perfit.cpp -o CMakeFiles/chessEngine.dir/src/perfit.cpp.s

CMakeFiles/chessEngine.dir/src/polybook.cpp.o: CMakeFiles/chessEngine.dir/flags.make
CMakeFiles/chessEngine.dir/src/polybook.cpp.o: ../src/polybook.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/chessEngine.dir/src/polybook.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chessEngine.dir/src/polybook.cpp.o -c /home/zachary/Projects/chessEngine/src/polybook.cpp

CMakeFiles/chessEngine.dir/src/polybook.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessEngine.dir/src/polybook.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/Projects/chessEngine/src/polybook.cpp > CMakeFiles/chessEngine.dir/src/polybook.cpp.i

CMakeFiles/chessEngine.dir/src/polybook.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessEngine.dir/src/polybook.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/Projects/chessEngine/src/polybook.cpp -o CMakeFiles/chessEngine.dir/src/polybook.cpp.s

CMakeFiles/chessEngine.dir/src/search.cpp.o: CMakeFiles/chessEngine.dir/flags.make
CMakeFiles/chessEngine.dir/src/search.cpp.o: ../src/search.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/chessEngine.dir/src/search.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chessEngine.dir/src/search.cpp.o -c /home/zachary/Projects/chessEngine/src/search.cpp

CMakeFiles/chessEngine.dir/src/search.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessEngine.dir/src/search.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/Projects/chessEngine/src/search.cpp > CMakeFiles/chessEngine.dir/src/search.cpp.i

CMakeFiles/chessEngine.dir/src/search.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessEngine.dir/src/search.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/Projects/chessEngine/src/search.cpp -o CMakeFiles/chessEngine.dir/src/search.cpp.s

CMakeFiles/chessEngine.dir/src/tt.cpp.o: CMakeFiles/chessEngine.dir/flags.make
CMakeFiles/chessEngine.dir/src/tt.cpp.o: ../src/tt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/chessEngine.dir/src/tt.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chessEngine.dir/src/tt.cpp.o -c /home/zachary/Projects/chessEngine/src/tt.cpp

CMakeFiles/chessEngine.dir/src/tt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessEngine.dir/src/tt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/Projects/chessEngine/src/tt.cpp > CMakeFiles/chessEngine.dir/src/tt.cpp.i

CMakeFiles/chessEngine.dir/src/tt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessEngine.dir/src/tt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/Projects/chessEngine/src/tt.cpp -o CMakeFiles/chessEngine.dir/src/tt.cpp.s

CMakeFiles/chessEngine.dir/src/uci.cpp.o: CMakeFiles/chessEngine.dir/flags.make
CMakeFiles/chessEngine.dir/src/uci.cpp.o: ../src/uci.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/chessEngine.dir/src/uci.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chessEngine.dir/src/uci.cpp.o -c /home/zachary/Projects/chessEngine/src/uci.cpp

CMakeFiles/chessEngine.dir/src/uci.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessEngine.dir/src/uci.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/Projects/chessEngine/src/uci.cpp > CMakeFiles/chessEngine.dir/src/uci.cpp.i

CMakeFiles/chessEngine.dir/src/uci.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessEngine.dir/src/uci.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/Projects/chessEngine/src/uci.cpp -o CMakeFiles/chessEngine.dir/src/uci.cpp.s

CMakeFiles/chessEngine.dir/src/zobrist.cpp.o: CMakeFiles/chessEngine.dir/flags.make
CMakeFiles/chessEngine.dir/src/zobrist.cpp.o: ../src/zobrist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/chessEngine.dir/src/zobrist.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chessEngine.dir/src/zobrist.cpp.o -c /home/zachary/Projects/chessEngine/src/zobrist.cpp

CMakeFiles/chessEngine.dir/src/zobrist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessEngine.dir/src/zobrist.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/Projects/chessEngine/src/zobrist.cpp > CMakeFiles/chessEngine.dir/src/zobrist.cpp.i

CMakeFiles/chessEngine.dir/src/zobrist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessEngine.dir/src/zobrist.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/Projects/chessEngine/src/zobrist.cpp -o CMakeFiles/chessEngine.dir/src/zobrist.cpp.s

# Object files for target chessEngine
chessEngine_OBJECTS = \
"CMakeFiles/chessEngine.dir/src/bitboards.cpp.o" \
"CMakeFiles/chessEngine.dir/src/board.cpp.o" \
"CMakeFiles/chessEngine.dir/src/evaluate.cpp.o" \
"CMakeFiles/chessEngine.dir/src/helpers.cpp.o" \
"CMakeFiles/chessEngine.dir/src/init.cpp.o" \
"CMakeFiles/chessEngine.dir/src/main.cpp.o" \
"CMakeFiles/chessEngine.dir/src/movegen.cpp.o" \
"CMakeFiles/chessEngine.dir/src/perfit.cpp.o" \
"CMakeFiles/chessEngine.dir/src/polybook.cpp.o" \
"CMakeFiles/chessEngine.dir/src/search.cpp.o" \
"CMakeFiles/chessEngine.dir/src/tt.cpp.o" \
"CMakeFiles/chessEngine.dir/src/uci.cpp.o" \
"CMakeFiles/chessEngine.dir/src/zobrist.cpp.o"

# External object files for target chessEngine
chessEngine_EXTERNAL_OBJECTS =

chessEngine: CMakeFiles/chessEngine.dir/src/bitboards.cpp.o
chessEngine: CMakeFiles/chessEngine.dir/src/board.cpp.o
chessEngine: CMakeFiles/chessEngine.dir/src/evaluate.cpp.o
chessEngine: CMakeFiles/chessEngine.dir/src/helpers.cpp.o
chessEngine: CMakeFiles/chessEngine.dir/src/init.cpp.o
chessEngine: CMakeFiles/chessEngine.dir/src/main.cpp.o
chessEngine: CMakeFiles/chessEngine.dir/src/movegen.cpp.o
chessEngine: CMakeFiles/chessEngine.dir/src/perfit.cpp.o
chessEngine: CMakeFiles/chessEngine.dir/src/polybook.cpp.o
chessEngine: CMakeFiles/chessEngine.dir/src/search.cpp.o
chessEngine: CMakeFiles/chessEngine.dir/src/tt.cpp.o
chessEngine: CMakeFiles/chessEngine.dir/src/uci.cpp.o
chessEngine: CMakeFiles/chessEngine.dir/src/zobrist.cpp.o
chessEngine: CMakeFiles/chessEngine.dir/build.make
chessEngine: CMakeFiles/chessEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zachary/Projects/chessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable chessEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chessEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chessEngine.dir/build: chessEngine

.PHONY : CMakeFiles/chessEngine.dir/build

CMakeFiles/chessEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chessEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chessEngine.dir/clean

CMakeFiles/chessEngine.dir/depend:
	cd /home/zachary/Projects/chessEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zachary/Projects/chessEngine /home/zachary/Projects/chessEngine /home/zachary/Projects/chessEngine/build /home/zachary/Projects/chessEngine/build /home/zachary/Projects/chessEngine/build/CMakeFiles/chessEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chessEngine.dir/depend
