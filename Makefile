#
## MY_PROJECT, 2025
## Makefile
## PASSWD_MANAGER
## Author: Enam KODJOH-KPAKPASSOU
## Email: eakodjoh-kpakpassou@st.ug.edu.gh
## File description:
#

# Qt Application Makefile

# Compiler and flags
CXX = g++
CXXFLAGS = -fPIC -O3 -I./include -I/usr/include/mysql $(shell pkg-config --cflags Qt6Core Qt6Widgets Qt6Gui Qt6Qml)
LDFLAGS = -lmysqlclient $(shell pkg-config --libs Qt6Core Qt6Widgets Qt6Gui Qt6Qml)

# Directories
SRC_DIR = src
CUSTOM_DIR = custom_objects/src
CUSTOM_HEADER = custom_objects/header
INCLUDE_DIR = include
BUILD_DIR = build
TARGET_DIR = .

# Create build directory if it doesn't exist
$(shell mkdir -p $(BUILD_DIR))

# Find all source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(CUSTOM_DIR)/*.cpp)

# Generate object file names (prefix src_ or custom_)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/src_%.o,$(filter $(SRC_DIR)/%.cpp,$(SOURCES))) \
          $(patsubst $(CUSTOM_DIR)/%.cpp,$(BUILD_DIR)/custom_%.o,$(filter $(CUSTOM_DIR)/%.cpp,$(SOURCES)))

# Name of the executable
TARGET = $(TARGET_DIR)/my_stock

# MOC processing for Qt - Use Qt6 MOC explicitly
MOC = /usr/lib/qt6/moc
# Only process headers that contain Q_OBJECT macro
MOC_HEADERS = $(shell grep -l "Q_OBJECT" $(INCLUDE_DIR)/*.h $(CUSTOM_HEADER)/*.h 2>/dev/null || true)
MOC_SOURCES = $(patsubst $(INCLUDE_DIR)/%.h,$(BUILD_DIR)/moc_%.cpp,$(filter $(INCLUDE_DIR)/%.h,$(MOC_HEADERS))) \
              $(patsubst $(CUSTOM_HEADER)/%.h,$(BUILD_DIR)/moc_custom_%.cpp,$(filter $(CUSTOM_HEADER)/%.h,$(MOC_HEADERS)))
MOC_OBJECTS = $(patsubst $(BUILD_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(MOC_SOURCES))

# Main target
all: $(TARGET)

# Linking the application
$(TARGET): $(OBJECTS) $(MOC_OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile source files
$(BUILD_DIR)/src_%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Generate MOC source files with Qt6 MOC
$(BUILD_DIR)/moc_%.cpp: $(INCLUDE_DIR)/%.h
	$(MOC) $< -o $@
$(BUILD_DIR)/moc_custom_%.cpp: $(CUSTOM_HEADER)/%.h
	$(MOC) $< -o $@

# Compile MOC sources
$(BUILD_DIR)/moc_%.o: $(BUILD_DIR)/moc_%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile custom source files
$(BUILD_DIR)/custom_%.o: $(CUSTOM_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target (removes only intermediate files)
clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/moc_*.cpp
	rmdir $(BUILD_DIR) 2>/dev/null || true

# Full clean (removes everything including executable)
fclean: clean
	rm -f $(TARGET)

# Rebuild everything
re: fclean all

# PHONY targets
.PHONY: all clean fclean re
