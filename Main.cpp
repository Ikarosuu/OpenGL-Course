#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

// Vertex Shader código fonte
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
// Fragment Shader código 
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";


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

	// Coordenadas dos vertices
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // lower let corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,	// lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f	// upp corner
	};


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

	// Cria o objeto vertex shader e pega sua referencia
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Coloca a fonte do vertex hader no objeto vertex shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	// compila o vertex shader em código de máquina
	glCompileShader(vertexShader);

	// Cria o objeto fragment shader e pega sua referência
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// Coloca a fonte do fragment shader no objeto fragment shader
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	// Compila o vertex hader em código de máquina
	glCompileShader(fragmentShader);

	// Cria o objeto shader program e pega sua referência
	GLuint shaderProgram = glCreateProgram();
	// Coloca o vertex e fragment shaders no shader program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	// Wrap-ip/Link conecta os shaders juntos no shader program
	glLinkProgram(shaderProgram);

	// deleta os objetos vertex e fragment shader
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// Cria a referência dos containers dos objetos vertex arry e vertex buffer
	GLuint VAO, VBO;

	// Gera o VAO e VBO com apenas 1 objeto cada
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	// Faz o VAO o atual vertex Array Object
	glBindVertexArray(VAO);

	// Bind o VBO especificando como GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// introduz os vertices para o VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// configura o atributo vertex assim o opengl sabe como ler o VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// liga o atributo vertex para o opengl saber como usa-lo
	glEnableVertexAttribArray(0);

	// Bind ambos VBO e VAO para 0 para ele não modificar por acidente
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	// Especifica a cor do fundo
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Limpa o back buffer e coloca uma nova cor nela
	glClear(GL_COLOR_BUFFER_BIT);
	// Troca o back buffer com o front buffer
	glfwSwapBuffers(window);

	// Condição para fazer a janela aparecer até a gente quiser fechar
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// diz para o opengl qual shader program queremos usar
		glUseProgram(shaderProgram);
		// bind o VAO assim o opengl sabe como usa-lo
		glBindVertexArray(VAO);
		//Desenha o triangulo usando GL_TRIANGLES primitivo
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);

		glfwPollEvents(); // Cuida de todos os Eventos do GLFW
	}

	// Deleta todos os objetos que criamos
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	glfwDestroyWindow(window);	// Destroi a janela antes de encerrar o programa
	glfwTerminate();	// Termina o GLFW antes do encerrar o programa
	return 0;
}