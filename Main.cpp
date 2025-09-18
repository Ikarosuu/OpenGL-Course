#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{
	// Inicializa o GLFW
	glfwInit();

	// Diz pro GLFW qual versão do OpenGL vamos usar
	// Neste caso o OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Diz pro GLFW que vamos usar o perfil CORE
	// Significa que teremos apenas as funções modernas
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Criado a janela com 800x800 pixels com o nome de "OpenGL Course"
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Course", NULL, NULL);
	if (window == NULL)	// Caso falhe em exibir a janela ele retorna um erro
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);	// Introduz a janela para o contexto atual

	gladLoadGL();	// Carrega o GLAD para configurar o OpenGL

	// Especifica o campo de visão da janela
	// Neste caso vai de x =0, y = 0, para x = 800, y = 800
	glViewport(0, 0, 800, 800);

	// Especifica a cor do fundo
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Limpa o back buffer e coloca uma nova cor nela
	glClear(GL_COLOR_BUFFER_BIT);
	// Troca o back buffer com o front buffer
	glfwSwapBuffers(window);

	// Condição para fazer a janela aparecer até a gente quiser fechar
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents(); // Cuida de todos os Eventos do GLFW
	}

	glfwDestroyWindow(window);	// Destroi a janela antes de encerrar o programa
	glfwTerminate();	// Termina o GLFW antes do encerrar o programa
	return 0;
}