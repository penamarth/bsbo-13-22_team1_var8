BUILD_DIR := build
SRC_DIR := src
BUILD_UML_DIR := ${BUILD_DIR}/plantuml
ASSETS_DIR := assets
ASSETS_UML_DIR := ${ASSETS_DIR}/plantuml

CXX := g++
CXXFLAGS := -Wall -Wextra -I$(SRC_DIR)
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
EXE := $(BUILD_DIR)/main

MD := $(shell grep -rl --include "*.md" --exclude-dir "build" '```plantuml')
UML_MD := $(patsubst %,$(BUILD_UML_DIR)/%,$(notdir $(MD)))
UML_IMG := $(patsubst %,$(ASSETS_UML_DIR)/%,$(notdir $(MD)))

$(EXE): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

umlgen $(UML_IMG): $(UML_MD) | $(ASSETS_UML_DIR)
	plantuml -svg -o $(CURDIR)/$(ASSETS_UML_DIR) $(UML_MD)

$(UML_MD): $(MD) | $(BUILD_UML_DIR)
	sed 's/\\>/>/g' $(filter %$(@F), $(MD)) > $@

$(BUILD_DIR) $(BUILD_UML_DIR) $(ASSETS_UML_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

clean_all: clean
	rm -rf $(ASSETS_UML_DIR)/*
