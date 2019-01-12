solution "richman"
location ("../build")

configurations {'Debug','Release'}

project "richman-sim"
kind "ConsoleApp"
language "C++"
files {"cpp/*.H",{"cpp/**.cpp"}, {"cpp/**.C"}}
buildoptions { "-std=c++14", "-Wall" }
links("pthread")

configuration "Debug"
defines { "DEBUG" }
flags { "Symbols" }
targetdir "../install"

configuration "Release"
defines { "NDEBUG" }
flags { "Optimize" }
targetdir "../install"


project "richman-gtest"
kind "ConsoleApp"
language "C++"
files {"cpp/*.H",{"cpp/**.cpp"}, {"cpp/**.C"}, {"test/**.C"},{"test/**.H"}}
includedirs {"cpp"}
excludes {"cpp/main.cpp"}
buildoptions { "-std=c++14", "-Wall" }
links("pthread")
links("gtest")
links("gmock")


configuration "Debug"
defines { "DEBUG" }
flags { "Symbols" }
targetdir "../install"
