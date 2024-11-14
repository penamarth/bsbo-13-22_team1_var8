BUILD_DIR := build
BUILD_UML_DIR := ${BUILD_DIR}/plantuml
ASSETS_DIR := assets
ASSETS_UML_DIR := ${ASSETS_DIR}/plantuml

MD := $(shell grep -rl --include "*.md" --exclude-dir "build" '```plantuml')
UML_MD := $(patsubst %,$(BUILD_UML_DIR)/%,$(notdir $(MD)))
UML_IMG := $(patsubst %,$(ASSETS_UML_DIR)/%,$(notdir $(MD)))

umlgen $(UML_IMG): $(UML_MD) | $(ASSETS_UML_DIR)
	plantuml -svg -o $(CURDIR)/$(ASSETS_UML_DIR) $(UML_MD)

$(UML_MD): $(MD) | $(BUILD_UML_DIR)
	sed 's/\\>/>/g' $(filter %$(@F), $(MD)) > $@

$(BUILD_UML_DIR) $(ASSETS_UML_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(ASSETS_UML_DIR)/*
