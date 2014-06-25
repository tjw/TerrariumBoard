SparkID=48ff6a065067555014372387

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
	