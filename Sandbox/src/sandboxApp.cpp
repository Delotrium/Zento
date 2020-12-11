#include <Zento.h>

class Sandbox : public Zento::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Zento::Application* Zento::CreateApplication()
{
	return new Sandbox();
}