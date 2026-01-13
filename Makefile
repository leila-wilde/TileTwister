# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++14 -Wall -Wextra -Isrc $(shell sdl2-config --cflags) -I/opt/homebrew/include/SDL2
LDFLAGS = $(shell sdl2-config --libs) -L/opt/homebrew/lib -lSDL2_ttf

# Project name
TARGET = TileTwister

# Source directories
SRC_DIR = src
GAME_DIR = $(SRC_DIR)/game
RENDERING_DIR = $(SRC_DIR)/rendering

# Source files
SOURCES = $(SRC_DIR)/main.cpp \
          $(GAME_DIR)/Game.cpp \
          $(RENDERING_DIR)/GameObject.cpp \
          $(RENDERING_DIR)/Tile.cpp

# Object files (in build directory)
BUILD_DIR = build
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(BUILD_DIR) $(TARGET)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/game $(BUILD_DIR)/rendering

# Build target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

# Rebuild (clean then build)
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Tests
TEST_TARGET = test_game
TEST_SOURCE = tests/test_game_init.cpp

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_SOURCE) $(GAME_DIR)/Game.cpp
	$(CXX) $(CXXFLAGS) -Isrc $(TEST_SOURCE) $(GAME_DIR)/Game.cpp -o $(TEST_TARGET)

# Phony targets (not actual files)
.PHONY: all clean rebuild run test
