#pragma once

#ifdef ZNT_PLATFORM_WINDOWS

extern Zento::Application* Zento::CreateApplication();

int main(int argc, char** argv)
{
	Zento::Log::Init();
	ZNT_CORE_INFO("Initialised Log...");
	ZNT_INFO("Initialised Client...");
	auto app = Zento::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Windows Support only, currently

#endif