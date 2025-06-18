.PHONY: all build install clean

all: build

build:
	python3 make.py build_ext --inplace

install:
	python3 make.py install --user

clean:
	rm -rf build *.egg-info *.so __pycache__
