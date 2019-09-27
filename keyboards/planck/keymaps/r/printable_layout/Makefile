PROJECT_DIR := $(shell pwd)

DOCKER ?= podman
TECTONIC_IMAGE := docker.io/dxjoke/tectonic-docker
DATA_MOUNT := -v $(PROJECT_DIR):/data
CACHE_MOUNT := -v $(PROJECT_DIR)/.cache:/root/.cache/Tectonic
FONTS_MOUNT := $(if $(FONTS),-v $(FONTS):/usr/share/fonts:ro,)
RUN_FLAGS := -it --rm --name tectonic-build -w /data $(DATA_MOUNT) $(CACHE_MOUNT) $(FONTS_MOUNT) $(TECTONIC_IMAGE)

.cache:
	# copy out the prefilled cache
	@[ ! -d $@ ] \
	    && $(DOCKER) create --name=src $(TECTONIC_IMAGE) \
	    && $(DOCKER) cp src:/root/.cache/Tectonic $@ \
	    && $(DOCKER) rm src


main.pdf: build
build: main.tex .cache
	$(DOCKER) run $(RUN_FLAGS) tectonic $<

clean: main.pdf
	$(RM) $<
	$(RM) $(PROJECT_DIR)/.cache

shell:
	$(DOCKER) $(RUN_FLAGS) bash

all: clean build

.PHONY: \
    build \
    clean \
    shell
