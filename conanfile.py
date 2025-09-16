from conan import ConanFile 

class GameEngineProject(ConanFile):
    generators = ("CMakeToolchain","CMakeDeps")
    settings = ("os","build_type","arch","compiler")

    def requirements(self):
        self.requires("glfw/3.4")
        self.requires("glew/2.2.0")
        self.requires("glm/1.0.1")
    
    def build_requirements(self):
        self.tool_requires("cmake/[>=3.25]")

    def layout(self):
        self.folders.generators = ""