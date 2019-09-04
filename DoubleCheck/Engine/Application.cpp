#include "Application.hpp"
#include <iostream>
#include "vector2.hpp"
#include "Input.h"
#include <sstream>
#include "ObjectManager.h"


Application* Application::application = nullptr;


namespace
{
    void    key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void    cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    void    mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    void    scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	//void	framebuffer_size_callback(GLFWwindow* window, int width, int height);
	bool    is_full = false;
}


void Application::Init()
{
    if (!glfwInit())
    {
        glfwTerminate();
        return;
    }


    GLenum glew_err_check;

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RED_BITS, 8);
    glfwWindowHint(GLFW_GREEN_BITS, 8);
    glfwWindowHint(GLFW_BLUE_BITS, 8);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);

    window = glfwCreateWindow(1280, 720, "sangministhebest", nullptr, nullptr);

    glfwMakeContextCurrent(window);
	/*glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwGetFramebufferSize(window, &width, &height);*/
    if (!window)
    {
        glfwTerminate();
        return;
    }
    glew_err_check = glewInit();

    if (glew_err_check != GLEW_NO_ERROR)
    {
        glfwTerminate();
        return;
    }

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    GLFWmonitor*       monitor = glfwGetPrimaryMonitor();
    glfwSetWindowMonitor(window, nullptr,
        200,
        200,
        static_cast<int>(1280),
        static_cast<int>(720), 0);

    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSwapInterval(true);
}
//void Application::framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}

void Application::Imgui_Init()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    const char* glsl_version = "#version 130";
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void Application::Update(float dt)
{
    input.Triggered_Reset();

    glfwSwapBuffers(window);
    glfwPollEvents();

    int w, h;
    glfwGetWindowSize(window, &w, &h);
    window_size.width = (float)w;
    window_size.height = (float)h;

	if (input.Is_Key_Triggered(GLFW_KEY_F))
	{
		Toggle_Fullscreen();
	}
	if (input.Is_Key_Triggered(GLFW_KEY_K))
	{
		Save();

	}
	if (input.Is_Key_Triggered(GLFW_KEY_R))
	{
		Clear();
		
		Engine re_start;
		re_start.Test();
	}

	save_dt += dt;
	if (save_dt >= 1.0f)
	{
		std::stringstream title;
		title <<"sangministhebest" << " " << " [" << FPS_frame << " FPS]";
		glfwSetWindowTitle(window, title.str().c_str());
		FPS_frame = 0;
		save_dt = 0;
	}
	FPS_frame++;

	if (input.Is_Key_Triggered(GLFW_KEY_ESCAPE))
	{
		exit(0);
	}
    if(input.Is_Mouse_Double_Clicked(GLFW_MOUSE_BUTTON_LEFT))
    {
        std::cout << "aaa" << std::endl;
    }
	
	/*std::cout << FPS_frame << " "<<std::endl;
	std::cout << dt << " ";*/
}

void Application::Imgui_Update()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    static vector2 origin_mouse_pos;
    if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);
    ImGui::Begin("salmin gui");

    for(int i = 0; i < ObjectManager::GetObjectManager()->GetObjectManagerContainer().size(); i++)
    {
        
        Object* this_obj = ObjectManager::GetObjectManager()->GetObjectManagerContainer_Value()[i].get();
        
        if(ImGui::TreeNode(this_obj->Get_Name().c_str()))
        {
            ImGui::TextWrapped("Salmin UI");
            ImGui::SliderFloat("translation_x", &this_obj->GetTransform().GetTranslation_Reference().x, -1.0f, 1.0f);
            ImGui::SliderFloat("translation_y", &this_obj->GetTransform().GetTranslation_Reference().y, -1.0f, 1.0f);
            ImGui::SliderFloat("scale_x", &this_obj->GetTransform().GetScale_Reference().x, -2.0f, 2.0f);
            ImGui::SliderFloat("scale_y", &this_obj->GetTransform().GetScale_Reference().y, -2.0f, 2.0f);

            if(ImGui::InputText("name", this_obj->name_buf, 64, ImGuiInputTextFlags_EnterReturnsTrue))
            {
                this_obj->Set_Name(this_obj->name_buf);
            }

            ImGui::Checkbox("select", &this_obj->Get_Is_Selected());

            if(this_obj->Get_Is_Selected())
            {
                if (input.Is_Mouse_Triggered(GLFW_MOUSE_BUTTON_LEFT))
                {
                    origin_mouse_pos = input.Get_Mouse_Pos();
                }
                else if (input.Is_Mouse_Pressed(GLFW_MOUSE_BUTTON_LEFT))
                {
                    if (origin_mouse_pos != input.Get_Mouse_Pos())
                    {
                        vector2 following_mouse;
                        following_mouse.x = input.Get_Mouse_Pos().x - origin_mouse_pos.x;//origin_mouse_pos.x - input.Get_Mouse_Pos().x;
                        following_mouse.y = input.Get_Mouse_Pos().y - origin_mouse_pos.y;//origin_mouse_pos.y - input.Get_Mouse_Pos().y;

                        following_mouse = normalize(following_mouse);

                        this_obj->GetTransform().SetTranslation(following_mouse);
                    }


                }
                else if(input.Is_Mouse_Released(GLFW_MOUSE_BUTTON_LEFT))
                {
                    this_obj->GetTransform().SetTranslation({ 0.0f, 0.0f });
                }
            }
            ImGui::TreePop();
        }
    }

    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Application::Delete()
{
	
}

void Application::Save()
{
	//Transform a;
	//Transform::Transform().Get_Save_Translation();
	//std::cout<< Transform::Transform().Get_Save_Translation().x;
}

void Application::Clear()
{
	ObjectManager::GetObjectManager()->Init();
	StateManager::GetStateManager()->Init();
	Graphic::GetGraphic()->Init();
}
bool Application::IsFullScreen()
{
	return glfwGetWindowMonitor(window);
}

void Application::TurnOnMonitorVerticalSynchronization(bool enable)
{
	get_vsync = enable;
	glfwSwapInterval(enable);
}

void Application::Toggle_Fullscreen()
{
	if (!IsFullScreen())
	{
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		GLFWmonitor*       monitor = glfwGetPrimaryMonitor();
		glfwGetWindowPos(window, &x_pos, &y_pos);
		glfwGetWindowSize(window, &width, &height);
		glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
		glViewport(0, 0, mode->width, mode->height);
		TurnOnMonitorVerticalSynchronization(get_vsync);
	}
	else
	{
		glfwSetWindowMonitor(window, nullptr, x_pos, y_pos, width, height, 0);
		glViewport(0, 0, width, height);
	}
	glfwSwapBuffers(window);
	glfwSwapInterval(true);
}

Application* Application::Get_Application()
{
    if (application == nullptr)
        application = new Application;

    return application;
}

namespace
{
    void mouse_button_callback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
    {
        input.Set_Mouse_Input(button, action);
    }
    void cursor_position_callback(GLFWwindow* /*window*/, double xpos, double ypos)
    {
        input.Set_Mouse_Position(xpos, ypos);
    }
    void key_callback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
    {
        input.Set_Keyboard_Input(key, action);
    }
    void scroll_callback(GLFWwindow* /*window*/, double xoffset, double yoffset)
    {
        input.Set_Mouse_Wheel(xoffset, yoffset);
    }
	/*void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}*/
}
