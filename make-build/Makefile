CXX      := g++
CXX_FLAGS := -std=c++17

TARGET   := main
SRC_DIR := ../src
BUILD_DIR := ./build
INCLUDE_DIR := ../include
LIB_DIR := ../lib

LD_FLAGS  := -L $(LIB_DIR) -l sfml-audio -l sfml-graphics -l sfml-network -l sfml-system -l sfml-window
INCLUDE  := -I $(INCLUDE_DIR)

SRC := $(shell find $(SRC_DIR) -type f -name *.cpp)

OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))
DEPENDENCIES := $(OBJECTS:.o=.d)

all: build $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) $(INCLUDE) -c $< -MMD -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) -o $@ $^ $(LD_FLAGS)

-include $(DEPENDENCIES)

.PHONY: all build clean debug release

debug: CXX_FLAGS += -g3
debug: all

release: CXX_FLAGS += -O2
release: all

clean:
	-@rm -r $(BUILD_DIR)
	-@rm $(TARGET)


