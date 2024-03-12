workspace "ENG"
   configurations { "Debug", "Release" }

project "ENG"
   kind "ConsoleApp"
   language "C++"
   architecture "x86_64"
   cppdialect "C++20"

   files { "**.h", "**.cpp", "**.hpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      targetdir "bin/win_debug"
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      targetdir "bin/win_release"
      optimize "On"
