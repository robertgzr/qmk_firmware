
.PHONY: all
all: build flash

.PHONY: build
build:
	cd ../../../../ && ./util/docker_build.sh planck/ez/glow:r

.PHONY: flash
flash:
	cd ../../../../ && wally-cli-bin ./planck_ez_glow_r.bin
