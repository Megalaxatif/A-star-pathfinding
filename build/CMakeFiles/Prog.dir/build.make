# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = C:/MinGW/mingw64/bin/cmake.exe

# The command to remove a file.
RM = C:/MinGW/mingw64/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:/Ethan/Projets/Code/A star pathfinding"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:/Ethan/Projets/Code/A star pathfinding/build"

# Include any dependencies generated for this target.
include CMakeFiles/Prog.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Prog.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Prog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Prog.dir/flags.make

CMakeFiles/Prog.dir/main.cpp.obj: CMakeFiles/Prog.dir/flags.make
CMakeFiles/Prog.dir/main.cpp.obj: D:/Ethan/Projets/Code/A\ star\ pathfinding/main.cpp
CMakeFiles/Prog.dir/main.cpp.obj: CMakeFiles/Prog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:/Ethan/Projets/Code/A star pathfinding/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Prog.dir/main.cpp.obj"
	C:/MinGW/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Prog.dir/main.cpp.obj -MF CMakeFiles/Prog.dir/main.cpp.obj.d -o CMakeFiles/Prog.dir/main.cpp.obj -c "D:/Ethan/Projets/Code/A star pathfinding/main.cpp"

CMakeFiles/Prog.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Prog.dir/main.cpp.i"
	C:/MinGW/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:/Ethan/Projets/Code/A star pathfinding/main.cpp" > CMakeFiles/Prog.dir/main.cpp.i

CMakeFiles/Prog.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Prog.dir/main.cpp.s"
	C:/MinGW/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:/Ethan/Projets/Code/A star pathfinding/main.cpp" -o CMakeFiles/Prog.dir/main.cpp.s

CMakeFiles/Prog.dir/func.cpp.obj: CMakeFiles/Prog.dir/flags.make
CMakeFiles/Prog.dir/func.cpp.obj: D:/Ethan/Projets/Code/A\ star\ pathfinding/func.cpp
CMakeFiles/Prog.dir/func.cpp.obj: CMakeFiles/Prog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:/Ethan/Projets/Code/A star pathfinding/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Prog.dir/func.cpp.obj"
	C:/MinGW/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Prog.dir/func.cpp.obj -MF CMakeFiles/Prog.dir/func.cpp.obj.d -o CMakeFiles/Prog.dir/func.cpp.obj -c "D:/Ethan/Projets/Code/A star pathfinding/func.cpp"

CMakeFiles/Prog.dir/func.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Prog.dir/func.cpp.i"
	C:/MinGW/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:/Ethan/Projets/Code/A star pathfinding/func.cpp" > CMakeFiles/Prog.dir/func.cpp.i

CMakeFiles/Prog.dir/func.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Prog.dir/func.cpp.s"
	C:/MinGW/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:/Ethan/Projets/Code/A star pathfinding/func.cpp" -o CMakeFiles/Prog.dir/func.cpp.s

CMakeFiles/Prog.dir/cell.cpp.obj: CMakeFiles/Prog.dir/flags.make
CMakeFiles/Prog.dir/cell.cpp.obj: D:/Ethan/Projets/Code/A\ star\ pathfinding/cell.cpp
CMakeFiles/Prog.dir/cell.cpp.obj: CMakeFiles/Prog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:/Ethan/Projets/Code/A star pathfinding/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Prog.dir/cell.cpp.obj"
	C:/MinGW/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Prog.dir/cell.cpp.obj -MF CMakeFiles/Prog.dir/cell.cpp.obj.d -o CMakeFiles/Prog.dir/cell.cpp.obj -c "D:/Ethan/Projets/Code/A star pathfinding/cell.cpp"

CMakeFiles/Prog.dir/cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Prog.dir/cell.cpp.i"
	C:/MinGW/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:/Ethan/Projets/Code/A star pathfinding/cell.cpp" > CMakeFiles/Prog.dir/cell.cpp.i

CMakeFiles/Prog.dir/cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Prog.dir/cell.cpp.s"
	C:/MinGW/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:/Ethan/Projets/Code/A star pathfinding/cell.cpp" -o CMakeFiles/Prog.dir/cell.cpp.s

# Object files for target Prog
Prog_OBJECTS = \
"CMakeFiles/Prog.dir/main.cpp.obj" \
"CMakeFiles/Prog.dir/func.cpp.obj" \
"CMakeFiles/Prog.dir/cell.cpp.obj"

# External object files for target Prog
Prog_EXTERNAL_OBJECTS =

Prog.exe: CMakeFiles/Prog.dir/main.cpp.obj
Prog.exe: CMakeFiles/Prog.dir/func.cpp.obj
Prog.exe: CMakeFiles/Prog.dir/cell.cpp.obj
Prog.exe: CMakeFiles/Prog.dir/build.make
Prog.exe: CMakeFiles/Prog.dir/linkLibs.rsp
Prog.exe: CMakeFiles/Prog.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="D:/Ethan/Projets/Code/A star pathfinding/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Prog.exe"
	C:/MinGW/mingw64/bin/cmake.exe -E rm -f CMakeFiles/Prog.dir/objects.a
	C:/MinGW/mingw64/bin/ar.exe qc CMakeFiles/Prog.dir/objects.a @CMakeFiles/Prog.dir/objects1.rsp
	C:/MinGW/mingw64/bin/c++.exe -Wl,--whole-archive CMakeFiles/Prog.dir/objects.a -Wl,--no-whole-archive -o Prog.exe -Wl,--out-implib,libProg.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/Prog.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/Prog.dir/build: Prog.exe
.PHONY : CMakeFiles/Prog.dir/build

CMakeFiles/Prog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Prog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Prog.dir/clean

CMakeFiles/Prog.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "D:/Ethan/Projets/Code/A star pathfinding" "D:/Ethan/Projets/Code/A star pathfinding" "D:/Ethan/Projets/Code/A star pathfinding/build" "D:/Ethan/Projets/Code/A star pathfinding/build" "D:/Ethan/Projets/Code/A star pathfinding/build/CMakeFiles/Prog.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Prog.dir/depend

