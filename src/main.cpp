#include "walnut/application.h"

#include "walnut/image.h"
#include "walnut/timer.h"
#include "walnut/random.h"

#include "ray_tracer/renderer.h"

bool g_ApplicationRunning = true;

class ExampleLayer : public Walnut::Layer
{

public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Settings");
		ImGui::Text("Last render time: %.3fms", m_LastRenderTime);
		ImGui::End();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

		ImGui::Begin("Viewport");

		uint32_t ViewportWidth = ImGui::GetContentRegionAvail().x;
		uint32_t ViewportHeight = ImGui::GetContentRegionAvail().y;

		auto image = m_Renderer.GetFinalImage();
		if (image)
		{
			ImGui::Image(image->GetDescriptorSet(), {(float)image->GetWidth(), (float)image->GetHeight()},
						 ImVec2(0, 1), ImVec2(1, 0));
		}
		ImGui::End();
		ImGui::PopStyleVar();

		Walnut::Timer timer;

		m_Renderer.OnResize(ViewportWidth, ViewportHeight);
		m_Renderer.Render();

		m_LastRenderTime = timer.ElapsedMillis();
	}

private:
	Renderer m_Renderer = Renderer();

	float m_LastRenderTime = 0.0f;
};

Walnut::Application *Walnut::CreateApplication(int argc, char **argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Walnut Example";

	Walnut::Application *app = new Walnut::Application(spec);
	app->PushLayer<ExampleLayer>();
	app->SetMenubarCallback([app]()
							{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		} });
	return app;
}

int main(int argc, char **argv)
{
	while (g_ApplicationRunning)
	{
		Walnut::Application *app = Walnut::CreateApplication(argc, argv);
		app->Run();
		delete app;
	}

	return 0;
}