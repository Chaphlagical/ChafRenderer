#include "app.h"
#include <imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Renderer/command.h>
#include <Renderer/camera.h>
#include <Renderer/Renderer2D.h>

#include <Scene/scene_layer.h>

#include <Editor/editor_layer.h>
#include <Editor/menu.h>
#include <Editor/FileDialog/ImGuiFileDialog.h>

#include <iostream>


namespace Chaf
{
    AppLayer::AppLayer()
        : Layer("AppLayer")//, m_CameraController(23.0f, 16.0f / 9.0f, CameraType::Perspective)
    {
        
    }

    void AppLayer::OnAttach()
    {
       /*Ref<TriMesh> m_Mesh = CreateRef<TriMesh>();
        m_Mesh->Create("assets/mesh/cyborg/cyborg.obj");
        //m_Mesh->Create(MeshType::Sphere);
        m_Mesh->SetTexture("assets/mesh/cyborg/cyborg_diffuse.png", 0);
        m_Mesh->AddTexture("assets/mesh/planet/mars.png");
        SceneLayer::GetInstance()->PushMesh(m_Mesh);

        Ref<TriMesh> m_Mesh1 = CreateRef<TriMesh>();
        m_Mesh1->Create("assets/mesh/planet/planet.obj");
        //m_Mesh->Create(MeshType::Sphere);
        m_Mesh1->SetTexture("assets/mesh/planet/mars.png", 0);
        m_Mesh1->SetPosition(0.0f, 15.0f, 0.0f);
        SceneLayer::GetInstance()->PushMesh(m_Mesh1);*/


    }

    void AppLayer::OnDetach()
    {
        
    }

    void AppLayer::OnUpdate(Timestep timestep)
    {
        
    }

    void AppLayer::OnImGuiRender()
    {
        //EditorLayer::ShowHierarchy();
        //EditorLayer::ShowInspector();
        //Hierarchy::ShowHierachy();
       // Component::ShowComponent();
        //Menu::ShowMainMenu();
        /*ImGui::Begin("File");
        if (ImGui::Button("Open File Dialog"))
            igfd::ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".cpp,.h,.hpp", ".");

        // display
        if (igfd::ImGuiFileDialog::Instance()->FileDialog("ChooseFileDlgKey"))
        {
            // action if OK
            if (igfd::ImGuiFileDialog::Instance()->IsOk == true)
            {
                std::string filePathName = igfd::ImGuiFileDialog::Instance()->GetFilepathName();
                std::string filePath = igfd::ImGuiFileDialog::Instance()->GetCurrentPath();
                // action
            }
            // close
            igfd::ImGuiFileDialog::Instance()->CloseDialog("ChooseFileDlgKey");
        }
        ImGui::End();*/
    }

    void AppLayer::OnEvent(Event& event)
    {

    }
}