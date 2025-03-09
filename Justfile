setup:
    premake5 gmake
    cp imgui.ini.sample imgui.ini

build-debug:
    premake5 gmake
    make

build-release:
    premake5 gmake
    make config=release

build-dist:
    premake5 gmake
    make config=dist

run: build-debug
    ./bin/Debug-linux-x86_64/RayTracer/RayTracer

run-release: build-release
    ./bin/Release-linux-x86_64/RayTracer/RayTracer

run-dist: build-dist
    ./bin/Dist-linux-x86_64/RayTracer/RayTracer