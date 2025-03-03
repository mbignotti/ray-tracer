-- premake5.lua
workspace "ray-tracer"
   configurations { "Debug", "Release", "Dist" }
   startproject "ray-tracer"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "ray-tracer"
include "walnut"