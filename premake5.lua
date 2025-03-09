-- premake5.lua
workspace "RayTracer"
   configurations { "Debug", "Release", "Dist" }
   architecture "x86_64"
   
   outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

   include "vendor/imgui"
   include "vendor/glfw"
   include "vendor/glm"
   
   project "RayTracer"
      kind "ConsoleApp"
      language "C++"
      cppdialect "C++17"
      staticruntime "off"

      files { "**.h", "**.cpp" }

      includedirs {
         "vendor/imgui", "vendor/stb_image", "vendor/glfw/include", 
         "vendor/glm/glm", 
      }

      links { "vulkan", "ImGui", "GLFW", "glm" }

      targetdir("bin/" .. outputdir .. "/%{prj.name}")
      objdir("bin-int/" .. outputdir .. "/%{prj.name}")

      filter "system:windows"
         systemversion "latest"
         defines {"WL_PLATFORM_WINDOWS"}

      filter "system:linux"
         defines {"WL_PLATFORM_LINUX"}

      filter "configurations:Debug"
         defines {"DEBUG"}
         runtime "Debug"
         symbols "On"

      filter "configurations:Release"
         defines {"RELEASE"}
         runtime "Release"
         optimize "On"
         symbols "On"

      filter "configurations:Dist"
         kind "WindowedApp"
         defines {"DIST"}
         runtime "Release"
         optimize "On"
         symbols "Off"
