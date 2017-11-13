deps:
	git submodule update --init --recursive
	mkdir -p out

build:
	cd out && cmake -DBUILD_TESTING=OFF ../ && make -j8

package: deps build

clean:
	rm -rf out/*
