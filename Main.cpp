#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Course", NULL, NULL);	// Criando a janela
	if (window == NULL)	// Caso falhe em exibir a janela ele retorna um erro
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);	// Como usar a janela

	while (!glfwWindowShouldClose(window)) // Condição para fazer a janela aparecer até a gente quiser fechar
	{
		glfwPollEvents(); // fazer ele processar todos os eventos poll
	}

	glfwDestroyWindow(window);	// destruindo a janela
	glfwTerminate();
	return 0;
}