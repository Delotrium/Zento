workspace "Zento"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Zento"
	location "Zento"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
   		{
			"ZNT_PLATFORM_WINDOWS",
                	"ZNT_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	filter "configurations:Debug"
		defines "ZNT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZNT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZNT_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "%/{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Zento/vendor/spdlog/include",
		"Zento/src"
	}

	links
	{
	 "Zento"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
   		{
			"ZNT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ZNT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZNT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZNT_DIST"
		optimize "On"