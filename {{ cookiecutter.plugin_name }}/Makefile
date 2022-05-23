default: setup
	cmake -G Ninja -Bbuild .
	ninja -Cbuild

setup:
	cd $(CURDIR)/conan-recipes/juce && conan create . {{ cookiecutter.conan_name }}/testing
	mkdir build && cd build && conan install ..

clean:
	rm -rf build/
