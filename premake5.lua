workspace "TitanPulse"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "TitanPulse/vendor/GLFW/include"
IncludeDir["Glad"] = "TitanPulse/vendor/Glad/include"
IncludeDir["Imgui"] = "TitanPulse/vendor/imgui/include"

include "TitanPulse/vendor/GLFW"
include "TitanPulse/vendor/Glad"
include "TitanPulse/vendor/imgui"

project "TitanPulse"
    location "TitanPulse"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/".. outputdir .."/%{prj.name}")
    objdir ("bin/int/".. outputdir .."/%{prj.name}")

    pchheader "tppch.h"
    pchsource "TitanPulse/src/tppch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs{
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.Imgui}"
    }

    links{
        "GLFW",
        "Glad",
        "Imgui",
        "opengl32.lib"
    
    }

    filter "system:windows"
        cppdialect "C++23"
        staticruntime "On"
        systemversion "latest"

        defines{
            "TP_PLATFORM_WINDOWS",
            "TP_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        } 

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .."/Sandbox")
        }

    filter "configurations:Debug"
        defines "TP_DEBUG"
        buildoptions "/MDd"
        buildoptions "/utf-8"
        symbols "On"

    filter "configurations:Release"
        defines "TP_RELEASE"
        buildoptions "/MD"
        buildoptions "/utf-8"
        symbols "On"

    filter "configurations:Dist"
        defines "TP_DIST"
        buildoptions "/MD"
        buildoptions "/utf-8"
        symbols "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/".. outputdir .."/%{prj.name}")
    objdir ("bin/int/".. outputdir .."/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs{
        "TitanPulse/vendor/spdlog/include",
        "TitanPulse/src"
    }

    links {
        "TitanPulse"
    }

    filter "system:windows"
        cppdialect "C++23"
        staticruntime "On"
        systemversion "latest"

        defines{
            "TP_PLATFORM_WINDOWS"
        } 

    filter "configurations:Debug"
        defines "TP_DEBUG"
        buildoptions "/MDd"
        buildoptions "/utf-8"
        symbols "On"

    filter "configurations:Release"
        defines "TP_RELEASE"
        buildoptions "/MD"
        buildoptions "/utf-8"
        symbols "On"

    filter "configurations:Dist"
        defines "TP_DIST"
        buildoptions "/MD"
        buildoptions "/utf-8"
        symbols "On"
