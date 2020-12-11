#pragma once

#ifdef ZNT_PLATFORM_WINDOWS

extern Zento::Application* Zento::CreateApplication();

int main(int argc, char** argv)
{
	printf("Zento CAD\n");
	auto app = Zento::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Windows Support only, currently

#endif