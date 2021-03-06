#include <Scene/maincamera_layer.h>
#include <imgui.h>
#include <iostream>
namespace Chaf
{
	MainCameraLayer* MainCameraLayer::s_Instance = nullptr;

	MainCameraLayer::MainCameraLayer()
		:Layer("WindowCamera"), m_CameraController(23.0f, 16.0f / 9.0f, CameraType::Perspective)
	{
		s_Instance = this;
	}

	void MainCameraLayer::OnImGuiRender()
	{
		if (m_WindowHandle)
		{
			ImGui::Begin("Camera Setting", &m_WindowHandle);
			ImGui::Text("Attribute");

			int type = static_cast<int>(m_CameraController.GetCamera().GetCameraType()) - 1;
			ImGui::Combo("type", (int*)&type, "Orthographic\0Perspective");
			m_CameraController.GetCamera().SetCameraType(static_cast<CameraType>(type + 1));

			float nearPlane = m_CameraController.GetCamera().GetNearPlane();
			ImGui::DragFloat("near", (float*)&nearPlane, 0.1f);
			nearPlane = nearPlane < 0 ? 0 : nearPlane;
			m_CameraController.GetCamera().SetNearPlane(nearPlane);
			float farPlane = m_CameraController.GetCamera().GetFarPlane();
			ImGui::DragFloat("far", (float*)&farPlane, 0.1f);
			farPlane = farPlane < nearPlane ? nearPlane + 0.1f : farPlane;
			m_CameraController.GetCamera().SetFarPlane(farPlane);

			float fov = m_CameraController.GetCamera().GetFov();
			ImGui::SliderFloat("fov", &fov, 0.1f, 45.0f, "%.1f");
			m_CameraController.GetCamera().SetFov(fov);

			float sensitivity = m_CameraController.GetSensitivity();
			ImGui::SliderFloat("sensitivity", &sensitivity, 0.01f, 1.00f, "%.2f");
			m_CameraController.SetSensitivity(sensitivity);

			float speed = m_CameraController.GetSpeed();
			ImGui::SliderFloat("speed", &speed, 0.1f, 30.0f, "%.1f");
			m_CameraController.SetSpeed(speed);

			ImGui::Separator();

			glm::vec3 position = m_CameraController.GetCamera().GetPosition();
			ImGui::DragFloat3("Position", (float*)&position, 0.1f);
			m_CameraController.GetCamera().SetPosition(position);

			ImGui::Separator();

			ImGui::Text("Rotation");
			float pitch = m_CameraController.GetCamera().GetPitch();
			ImGui::DragFloat("Pitch", &pitch, 1.0f);
			m_CameraController.GetCamera().SetPitch(pitch);
			float yaw = m_CameraController.GetCamera().GetYaw();
			ImGui::DragFloat("Yaw", &yaw, 1.0f);
			m_CameraController.GetCamera().SetYaw(yaw);

			ImGui::End();
		}
	}

}