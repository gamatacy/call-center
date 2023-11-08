
install_conan:
	conan install . --output-folder=build --build=missing

build_toolchain:
	cmake . -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release

build: install_conan build_toolchain
	cmake --build .

soft_clean:
	rm -rf CMakeCache.txt
	rm -rf CMakePresets.json
	rm -rf CMakeUserPresets.json
	rm -rf CMakeFiles

clean: soft_clean
	rm -rf build
	rm -rf *.cmake
	rm -rf Makefile

