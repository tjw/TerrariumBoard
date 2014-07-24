SparkID=48ff6a065067555014372387

# Terrible; if *.h isn't first, then the version of Spark_NeoPixel.h on the server is used instead of ours.
SOURCE_DIR=$(shell pwd)
SOURCES=$(SOURCE_DIR)/*.h $(SOURCE_DIR)/*.cpp $(SOURCE_DIR)/*.ino

.PHONY: all
all: compile
	
.PHONY: compile
compile:
	mkdir -p build
	(cd build; spark compile $(SOURCES))

.PHONY: clean
clean:
	rm -rf build

.PHONY: flash
flash:
	spark flash $(SparkID) $(SOURCES)
	