# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.13.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.13.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/thomasgeorge/desktop/NES-Emulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/thomasgeorge/desktop/NES-Emulator

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.13.4/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.13.4/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/thomasgeorge/desktop/NES-Emulator/CMakeFiles /Users/thomasgeorge/desktop/NES-Emulator/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/thomasgeorge/desktop/NES-Emulator/CMakeFiles 0
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
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named nes

# Build rule for target.
nes: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 nes
.PHONY : nes

# fast build rule for target.
nes/fast:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/build
.PHONY : nes/fast

src/6502.o: src/6502.c.o

.PHONY : src/6502.o

# target to build an object file
src/6502.c.o:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/6502.c.o
.PHONY : src/6502.c.o

src/6502.i: src/6502.c.i

.PHONY : src/6502.i

# target to preprocess a source file
src/6502.c.i:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/6502.c.i
.PHONY : src/6502.c.i

src/6502.s: src/6502.c.s

.PHONY : src/6502.s

# target to generate assembly for a file
src/6502.c.s:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/6502.c.s
.PHONY : src/6502.c.s

src/apu.o: src/apu.c.o

.PHONY : src/apu.o

# target to build an object file
src/apu.c.o:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/apu.c.o
.PHONY : src/apu.c.o

src/apu.i: src/apu.c.i

.PHONY : src/apu.i

# target to preprocess a source file
src/apu.c.i:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/apu.c.i
.PHONY : src/apu.c.i

src/apu.s: src/apu.c.s

.PHONY : src/apu.s

# target to generate assembly for a file
src/apu.c.s:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/apu.c.s
.PHONY : src/apu.c.s

src/instructions.o: src/instructions.c.o

.PHONY : src/instructions.o

# target to build an object file
src/instructions.c.o:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/instructions.c.o
.PHONY : src/instructions.c.o

src/instructions.i: src/instructions.c.i

.PHONY : src/instructions.i

# target to preprocess a source file
src/instructions.c.i:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/instructions.c.i
.PHONY : src/instructions.c.i

src/instructions.s: src/instructions.c.s

.PHONY : src/instructions.s

# target to generate assembly for a file
src/instructions.c.s:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/instructions.c.s
.PHONY : src/instructions.c.s

src/ppu.o: src/ppu.c.o

.PHONY : src/ppu.o

# target to build an object file
src/ppu.c.o:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/ppu.c.o
.PHONY : src/ppu.c.o

src/ppu.i: src/ppu.c.i

.PHONY : src/ppu.i

# target to preprocess a source file
src/ppu.c.i:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/ppu.c.i
.PHONY : src/ppu.c.i

src/ppu.s: src/ppu.c.s

.PHONY : src/ppu.s

# target to generate assembly for a file
src/ppu.c.s:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/ppu.c.s
.PHONY : src/ppu.c.s

src/sysmem.o: src/sysmem.c.o

.PHONY : src/sysmem.o

# target to build an object file
src/sysmem.c.o:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/sysmem.c.o
.PHONY : src/sysmem.c.o

src/sysmem.i: src/sysmem.c.i

.PHONY : src/sysmem.i

# target to preprocess a source file
src/sysmem.c.i:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/sysmem.c.i
.PHONY : src/sysmem.c.i

src/sysmem.s: src/sysmem.c.s

.PHONY : src/sysmem.s

# target to generate assembly for a file
src/sysmem.c.s:
	$(MAKE) -f CMakeFiles/nes.dir/build.make CMakeFiles/nes.dir/src/sysmem.c.s
.PHONY : src/sysmem.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... nes"
	@echo "... src/6502.o"
	@echo "... src/6502.i"
	@echo "... src/6502.s"
	@echo "... src/apu.o"
	@echo "... src/apu.i"
	@echo "... src/apu.s"
	@echo "... src/instructions.o"
	@echo "... src/instructions.i"
	@echo "... src/instructions.s"
	@echo "... src/ppu.o"
	@echo "... src/ppu.i"
	@echo "... src/ppu.s"
	@echo "... src/sysmem.o"
	@echo "... src/sysmem.i"
	@echo "... src/sysmem.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
