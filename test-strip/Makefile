# Core "test"
SparkID=53ff71065075535160331387

# Terrible; if *.h isn't first, then the version of Spark_NeoPixel.h on the server is used instead of ours.
SOURCES=*.h *.cpp *.ino

.PHONY: all
all: compile
	
.PHONY: compile
compile:
	spark compile $(SOURCES)

.PHONY: flash
flash:
	spark flash $(SparkID) $(SOURCES)
	