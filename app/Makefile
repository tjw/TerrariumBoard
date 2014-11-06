SparkID=48ff6a065067555014372387

# Terrible; if *.h isn't first, then the version of Spark_NeoPixel.h on the server is used instead of ours.
SOURCE_DIR=$(shell pwd)
SOURCES=$(SOURCE_DIR)/*.h $(SOURCE_DIR)/*.cpp $(SOURCE_DIR)/*.ino

.PHONY: all
all: app.bin

app.bin: $(SOURCES)
	spark compile $(SOURCES) --saveTo app.bin

.PHONY: clean
clean:
	rm app.bin

.PHONY: flash
flash: app.bin
	spark flash $(SparkID) --usb app.bin
