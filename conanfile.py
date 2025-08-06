from conan import ConanFile
from conan.tools.env import VirtualRunEnv, VirtualBuildEnv
from conan.tools.cmake import CMakeDeps, CMakeToolchain, CMake
from conan.tools.build import check_min_cppstd

class QTodoCalenConan(ConanFile):
    name = "QTodoCalen"
    version = "0.1"
    license = "MIT"
    # author = "your_name <your_email@example.com>"
    # url = "https://github.com/your/repo"
    description = "Open Source Todo Calen App"
    topics = ("qt", "todo", "calendar")
    settings = "os", "compiler", "build_type", "arch"
    options = {}
    default_options = {}

    # generators = "CMakeDeps", "CMakeToolchain"

    exports_sources = "CMakeLists.txt", "src/*"

    @property
    def _min_cppstd(self):
        return 17

    def requirements(self):
        # self.requires("qt/6.8.3")
        pass

    def validate(self):
        check_min_cppstd(self, self._min_cppstd)
    
    def configure(self):
        if not self.settings.compiler.cppstd:
            self.settings.compiler.cppstd = "17"


    def layout(self):
        # 让CMakeToolchain等自动识别源码和构建目录
        self.folders.source = "."
        self.folders.build = "build"

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()
        VirtualBuildEnv(self).generate()
        VirtualRunEnv(self).generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["QTodoCalen"]