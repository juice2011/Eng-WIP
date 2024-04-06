workspace "ENG"
   configurations { "Debug", "Release" }

project "ENG"
   kind "ConsoleApp"
   language "C++"
   architecture "x86_64"
   cppdialect "C++20"
   libdirs {"../Eng/libs"}

   files { "**.h", "**.cpp", "**.hpp" }
   links { "glfw3", "glew32s", "opengl32" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      targetdir "bin/win_debug"
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      targetdir "bin/win_release"
      optimize "On"

   
