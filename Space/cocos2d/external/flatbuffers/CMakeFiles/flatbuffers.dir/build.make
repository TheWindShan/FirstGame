# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/nego/Documentos/FirstGame/Space

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nego/Documentos/FirstGame/Space

# Include any dependencies generated for this target.
include cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/depend.make

# Include the progress variables for this target.
include cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/progress.make

# Include the compile flags for this target's objects.
include cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flags.make

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.o: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flags.make
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.o: cocos2d/external/flatbuffers/flatc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nego/Documentos/FirstGame/Space/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.o"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flatbuffers.dir/flatc.cpp.o -c /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/flatc.cpp

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flatbuffers.dir/flatc.cpp.i"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/flatc.cpp > CMakeFiles/flatbuffers.dir/flatc.cpp.i

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flatbuffers.dir/flatc.cpp.s"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/flatc.cpp -o CMakeFiles/flatbuffers.dir/flatc.cpp.s

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.o.requires:
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.o.requires

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.o.provides: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.o.requires
	$(MAKE) -f cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/build.make cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.o.provides.build
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.o.provides

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.o.provides.build: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.o

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flags.make
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o: cocos2d/external/flatbuffers/idl_gen_cpp.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nego/Documentos/FirstGame/Space/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o -c /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_cpp.cpp

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.i"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_cpp.cpp > CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.i

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.s"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_cpp.cpp -o CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.s

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o.requires:
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o.requires

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o.provides: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o.requires
	$(MAKE) -f cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/build.make cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o.provides.build
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o.provides

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o.provides.build: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flags.make
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o: cocos2d/external/flatbuffers/idl_gen_fbs.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nego/Documentos/FirstGame/Space/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o -c /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_fbs.cpp

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.i"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_fbs.cpp > CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.i

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.s"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_fbs.cpp -o CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.s

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o.requires:
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o.requires

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o.provides: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o.requires
	$(MAKE) -f cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/build.make cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o.provides.build
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o.provides

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o.provides.build: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flags.make
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o: cocos2d/external/flatbuffers/idl_gen_general.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nego/Documentos/FirstGame/Space/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o -c /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_general.cpp

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.i"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_general.cpp > CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.i

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.s"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_general.cpp -o CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.s

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o.requires:
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o.requires

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o.provides: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o.requires
	$(MAKE) -f cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/build.make cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o.provides.build
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o.provides

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o.provides.build: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flags.make
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o: cocos2d/external/flatbuffers/idl_gen_go.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nego/Documentos/FirstGame/Space/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o -c /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_go.cpp

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.i"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_go.cpp > CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.i

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.s"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_go.cpp -o CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.s

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o.requires:
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o.requires

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o.provides: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o.requires
	$(MAKE) -f cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/build.make cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o.provides.build
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o.provides

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o.provides.build: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flags.make
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o: cocos2d/external/flatbuffers/idl_gen_text.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nego/Documentos/FirstGame/Space/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o -c /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_text.cpp

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.i"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_text.cpp > CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.i

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.s"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_gen_text.cpp -o CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.s

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o.requires:
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o.requires

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o.provides: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o.requires
	$(MAKE) -f cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/build.make cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o.provides.build
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o.provides

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o.provides.build: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.o: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flags.make
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.o: cocos2d/external/flatbuffers/idl_parser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nego/Documentos/FirstGame/Space/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.o"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flatbuffers.dir/idl_parser.cpp.o -c /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_parser.cpp

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flatbuffers.dir/idl_parser.cpp.i"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_parser.cpp > CMakeFiles/flatbuffers.dir/idl_parser.cpp.i

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flatbuffers.dir/idl_parser.cpp.s"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/idl_parser.cpp -o CMakeFiles/flatbuffers.dir/idl_parser.cpp.s

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.o.requires:
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.o.requires

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.o.provides: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.o.requires
	$(MAKE) -f cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/build.make cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.o.provides.build
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.o.provides

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.o.provides.build: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.o

# Object files for target flatbuffers
flatbuffers_OBJECTS = \
"CMakeFiles/flatbuffers.dir/flatc.cpp.o" \
"CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o" \
"CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o" \
"CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o" \
"CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o" \
"CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o" \
"CMakeFiles/flatbuffers.dir/idl_parser.cpp.o"

# External object files for target flatbuffers
flatbuffers_EXTERNAL_OBJECTS =

lib/libflatbuffers.a: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.o
lib/libflatbuffers.a: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o
lib/libflatbuffers.a: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o
lib/libflatbuffers.a: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o
lib/libflatbuffers.a: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o
lib/libflatbuffers.a: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o
lib/libflatbuffers.a: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.o
lib/libflatbuffers.a: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/build.make
lib/libflatbuffers.a: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../../../lib/libflatbuffers.a"
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && $(CMAKE_COMMAND) -P CMakeFiles/flatbuffers.dir/cmake_clean_target.cmake
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flatbuffers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/build: lib/libflatbuffers.a
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/build

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/requires: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/flatc.cpp.o.requires
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/requires: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_cpp.cpp.o.requires
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/requires: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_fbs.cpp.o.requires
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/requires: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_general.cpp.o.requires
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/requires: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_go.cpp.o.requires
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/requires: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_gen_text.cpp.o.requires
cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/requires: cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/idl_parser.cpp.o.requires
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/requires

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/clean:
	cd /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers && $(CMAKE_COMMAND) -P CMakeFiles/flatbuffers.dir/cmake_clean.cmake
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/clean

cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/depend:
	cd /home/nego/Documentos/FirstGame/Space && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nego/Documentos/FirstGame/Space /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers /home/nego/Documentos/FirstGame/Space /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers /home/nego/Documentos/FirstGame/Space/cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/depend

