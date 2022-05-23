from conans import ConanFile, CMake, tools


class ConanJuce(ConanFile):
    name = "juce"
    homepage = "https://juce.com/"
    license = "GPL-v3"
    version = "6.1.6"

    generators = "cmake"
    no_copy_source = True

    def source(self):
        tools.get(**self.conan_data["sources"][self.version], strip_root=True)

    def package(self):
        self.copy("CMakeLists.txt")
        self.copy("extras/**")
        self.copy("modules/**")
