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
CMAKE_COMMAND = /snap/clion/27/bin/cmake/bin/cmake

# The command to remove a file.
RM = /snap/clion/27/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jonathan/ProyectoPOO/RTSGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jonathan/ProyectoPOO/RTSGame/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RTSGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RTSGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RTSGame.dir/flags.make

CMakeFiles/RTSGame.dir/Source/main.cpp.o: CMakeFiles/RTSGame.dir/flags.make
CMakeFiles/RTSGame.dir/Source/main.cpp.o: ../Source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jonathan/ProyectoPOO/RTSGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RTSGame.dir/Source/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RTSGame.dir/Source/main.cpp.o -c /home/jonathan/ProyectoPOO/RTSGame/Source/main.cpp

CMakeFiles/RTSGame.dir/Source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTSGame.dir/Source/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jonathan/ProyectoPOO/RTSGame/Source/main.cpp > CMakeFiles/RTSGame.dir/Source/main.cpp.i

CMakeFiles/RTSGame.dir/Source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTSGame.dir/Source/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jonathan/ProyectoPOO/RTSGame/Source/main.cpp -o CMakeFiles/RTSGame.dir/Source/main.cpp.s

CMakeFiles/RTSGame.dir/Source/main.cpp.o.requires:

.PHONY : CMakeFiles/RTSGame.dir/Source/main.cpp.o.requires

CMakeFiles/RTSGame.dir/Source/main.cpp.o.provides: CMakeFiles/RTSGame.dir/Source/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/RTSGame.dir/build.make CMakeFiles/RTSGame.dir/Source/main.cpp.o.provides.build
.PHONY : CMakeFiles/RTSGame.dir/Source/main.cpp.o.provides

CMakeFiles/RTSGame.dir/Source/main.cpp.o.provides.build: CMakeFiles/RTSGame.dir/Source/main.cpp.o


CMakeFiles/RTSGame.dir/Source/Game.cpp.o: CMakeFiles/RTSGame.dir/flags.make
CMakeFiles/RTSGame.dir/Source/Game.cpp.o: ../Source/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jonathan/ProyectoPOO/RTSGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RTSGame.dir/Source/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RTSGame.dir/Source/Game.cpp.o -c /home/jonathan/ProyectoPOO/RTSGame/Source/Game.cpp

CMakeFiles/RTSGame.dir/Source/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTSGame.dir/Source/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jonathan/ProyectoPOO/RTSGame/Source/Game.cpp > CMakeFiles/RTSGame.dir/Source/Game.cpp.i

CMakeFiles/RTSGame.dir/Source/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTSGame.dir/Source/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jonathan/ProyectoPOO/RTSGame/Source/Game.cpp -o CMakeFiles/RTSGame.dir/Source/Game.cpp.s

CMakeFiles/RTSGame.dir/Source/Game.cpp.o.requires:

.PHONY : CMakeFiles/RTSGame.dir/Source/Game.cpp.o.requires

CMakeFiles/RTSGame.dir/Source/Game.cpp.o.provides: CMakeFiles/RTSGame.dir/Source/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/RTSGame.dir/build.make CMakeFiles/RTSGame.dir/Source/Game.cpp.o.provides.build
.PHONY : CMakeFiles/RTSGame.dir/Source/Game.cpp.o.provides

CMakeFiles/RTSGame.dir/Source/Game.cpp.o.provides.build: CMakeFiles/RTSGame.dir/Source/Game.cpp.o


CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o: CMakeFiles/RTSGame.dir/flags.make
CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o: ../Source/Unidad.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jonathan/ProyectoPOO/RTSGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o -c /home/jonathan/ProyectoPOO/RTSGame/Source/Unidad.cpp

CMakeFiles/RTSGame.dir/Source/Unidad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTSGame.dir/Source/Unidad.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jonathan/ProyectoPOO/RTSGame/Source/Unidad.cpp > CMakeFiles/RTSGame.dir/Source/Unidad.cpp.i

CMakeFiles/RTSGame.dir/Source/Unidad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTSGame.dir/Source/Unidad.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jonathan/ProyectoPOO/RTSGame/Source/Unidad.cpp -o CMakeFiles/RTSGame.dir/Source/Unidad.cpp.s

CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o.requires:

.PHONY : CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o.requires

CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o.provides: CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o.requires
	$(MAKE) -f CMakeFiles/RTSGame.dir/build.make CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o.provides.build
.PHONY : CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o.provides

CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o.provides.build: CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o


CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o: CMakeFiles/RTSGame.dir/flags.make
CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o: ../Source/Controlador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jonathan/ProyectoPOO/RTSGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o -c /home/jonathan/ProyectoPOO/RTSGame/Source/Controlador.cpp

CMakeFiles/RTSGame.dir/Source/Controlador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTSGame.dir/Source/Controlador.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jonathan/ProyectoPOO/RTSGame/Source/Controlador.cpp > CMakeFiles/RTSGame.dir/Source/Controlador.cpp.i

CMakeFiles/RTSGame.dir/Source/Controlador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTSGame.dir/Source/Controlador.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jonathan/ProyectoPOO/RTSGame/Source/Controlador.cpp -o CMakeFiles/RTSGame.dir/Source/Controlador.cpp.s

CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o.requires:

.PHONY : CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o.requires

CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o.provides: CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o.requires
	$(MAKE) -f CMakeFiles/RTSGame.dir/build.make CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o.provides.build
.PHONY : CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o.provides

CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o.provides.build: CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o


CMakeFiles/RTSGame.dir/Source/Choza.cpp.o: CMakeFiles/RTSGame.dir/flags.make
CMakeFiles/RTSGame.dir/Source/Choza.cpp.o: ../Source/Choza.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jonathan/ProyectoPOO/RTSGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RTSGame.dir/Source/Choza.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RTSGame.dir/Source/Choza.cpp.o -c /home/jonathan/ProyectoPOO/RTSGame/Source/Choza.cpp

CMakeFiles/RTSGame.dir/Source/Choza.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTSGame.dir/Source/Choza.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jonathan/ProyectoPOO/RTSGame/Source/Choza.cpp > CMakeFiles/RTSGame.dir/Source/Choza.cpp.i

CMakeFiles/RTSGame.dir/Source/Choza.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTSGame.dir/Source/Choza.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jonathan/ProyectoPOO/RTSGame/Source/Choza.cpp -o CMakeFiles/RTSGame.dir/Source/Choza.cpp.s

CMakeFiles/RTSGame.dir/Source/Choza.cpp.o.requires:

.PHONY : CMakeFiles/RTSGame.dir/Source/Choza.cpp.o.requires

CMakeFiles/RTSGame.dir/Source/Choza.cpp.o.provides: CMakeFiles/RTSGame.dir/Source/Choza.cpp.o.requires
	$(MAKE) -f CMakeFiles/RTSGame.dir/build.make CMakeFiles/RTSGame.dir/Source/Choza.cpp.o.provides.build
.PHONY : CMakeFiles/RTSGame.dir/Source/Choza.cpp.o.provides

CMakeFiles/RTSGame.dir/Source/Choza.cpp.o.provides.build: CMakeFiles/RTSGame.dir/Source/Choza.cpp.o


CMakeFiles/RTSGame.dir/Source/Map.cpp.o: CMakeFiles/RTSGame.dir/flags.make
CMakeFiles/RTSGame.dir/Source/Map.cpp.o: ../Source/Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jonathan/ProyectoPOO/RTSGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/RTSGame.dir/Source/Map.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RTSGame.dir/Source/Map.cpp.o -c /home/jonathan/ProyectoPOO/RTSGame/Source/Map.cpp

CMakeFiles/RTSGame.dir/Source/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTSGame.dir/Source/Map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jonathan/ProyectoPOO/RTSGame/Source/Map.cpp > CMakeFiles/RTSGame.dir/Source/Map.cpp.i

CMakeFiles/RTSGame.dir/Source/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTSGame.dir/Source/Map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jonathan/ProyectoPOO/RTSGame/Source/Map.cpp -o CMakeFiles/RTSGame.dir/Source/Map.cpp.s

CMakeFiles/RTSGame.dir/Source/Map.cpp.o.requires:

.PHONY : CMakeFiles/RTSGame.dir/Source/Map.cpp.o.requires

CMakeFiles/RTSGame.dir/Source/Map.cpp.o.provides: CMakeFiles/RTSGame.dir/Source/Map.cpp.o.requires
	$(MAKE) -f CMakeFiles/RTSGame.dir/build.make CMakeFiles/RTSGame.dir/Source/Map.cpp.o.provides.build
.PHONY : CMakeFiles/RTSGame.dir/Source/Map.cpp.o.provides

CMakeFiles/RTSGame.dir/Source/Map.cpp.o.provides.build: CMakeFiles/RTSGame.dir/Source/Map.cpp.o


# Object files for target RTSGame
RTSGame_OBJECTS = \
"CMakeFiles/RTSGame.dir/Source/main.cpp.o" \
"CMakeFiles/RTSGame.dir/Source/Game.cpp.o" \
"CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o" \
"CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o" \
"CMakeFiles/RTSGame.dir/Source/Choza.cpp.o" \
"CMakeFiles/RTSGame.dir/Source/Map.cpp.o"

# External object files for target RTSGame
RTSGame_EXTERNAL_OBJECTS =

RTSGame: CMakeFiles/RTSGame.dir/Source/main.cpp.o
RTSGame: CMakeFiles/RTSGame.dir/Source/Game.cpp.o
RTSGame: CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o
RTSGame: CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o
RTSGame: CMakeFiles/RTSGame.dir/Source/Choza.cpp.o
RTSGame: CMakeFiles/RTSGame.dir/Source/Map.cpp.o
RTSGame: CMakeFiles/RTSGame.dir/build.make
RTSGame: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
RTSGame: /usr/lib/x86_64-linux-gnu/libsfml-network.so
RTSGame: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
RTSGame: /usr/lib/x86_64-linux-gnu/libsfml-window.so
RTSGame: /usr/lib/x86_64-linux-gnu/libsfml-system.so
RTSGame: CMakeFiles/RTSGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jonathan/ProyectoPOO/RTSGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable RTSGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RTSGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RTSGame.dir/build: RTSGame

.PHONY : CMakeFiles/RTSGame.dir/build

CMakeFiles/RTSGame.dir/requires: CMakeFiles/RTSGame.dir/Source/main.cpp.o.requires
CMakeFiles/RTSGame.dir/requires: CMakeFiles/RTSGame.dir/Source/Game.cpp.o.requires
CMakeFiles/RTSGame.dir/requires: CMakeFiles/RTSGame.dir/Source/Unidad.cpp.o.requires
CMakeFiles/RTSGame.dir/requires: CMakeFiles/RTSGame.dir/Source/Controlador.cpp.o.requires
CMakeFiles/RTSGame.dir/requires: CMakeFiles/RTSGame.dir/Source/Choza.cpp.o.requires
CMakeFiles/RTSGame.dir/requires: CMakeFiles/RTSGame.dir/Source/Map.cpp.o.requires

.PHONY : CMakeFiles/RTSGame.dir/requires

CMakeFiles/RTSGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RTSGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RTSGame.dir/clean

CMakeFiles/RTSGame.dir/depend:
	cd /home/jonathan/ProyectoPOO/RTSGame/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jonathan/ProyectoPOO/RTSGame /home/jonathan/ProyectoPOO/RTSGame /home/jonathan/ProyectoPOO/RTSGame/cmake-build-debug /home/jonathan/ProyectoPOO/RTSGame/cmake-build-debug /home/jonathan/ProyectoPOO/RTSGame/cmake-build-debug/CMakeFiles/RTSGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RTSGame.dir/depend

