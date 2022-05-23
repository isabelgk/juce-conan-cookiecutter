# {{ cookiecutter.project_name }}

## Requirements
- [cmake](https://cmake.org/install/): build system generator
- Python 3
    - Recommended to install via [pyenv](https://github.com/pyenv/pyenv), but not required
- [conan](https://docs.conan.io/en/latest/installation.html): package manager
    - Recommended to install via `pip install conan`

## Building

```shell
# Get the repository
git clone <this repository>

# Add JUCE to your local Conan cache since it doesn't exist on conan center
cd carve/conan-recipes/juce
conan create . {{ cookiecutter.conan_name }}/testing

# Install all required conan packages from conanfile.txt
cd ../.. && mkdir build && cd build
conan install ..
cmake -G Ninja ..

# Build
cmake --build .
```
