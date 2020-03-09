#include "Laborator9.h"
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

Laborator9::Laborator9()
{
}

Laborator9::~Laborator9()
{
}

void Laborator9::Init()
{
	tip_cladire = rand() % 4;
	{
		lightPosition = glm::vec3(0, 1, 1);
		materialShininess = 30;
		materialKd = 0.5;
		materialKs = 0.5;
	}

	int raritate_birouri = rand() % 20;
	int aparitie_blocuri = rand() % 20;
	const string textureLoc = "Source/Laboratoare/Laborator9/Textures/";

	for (int i = 0; i < 75; i++)
	{
		for (int j = 0; j < 75; j++)
		{
			road[i][j] = 0;
		}
	}

	for (int i = 0; i < 75; i++)
	{
		for (int j = 0; j < 75; j++)
		{
			inaltime = 5 + (rand() % 10);
		}
	}

	



	
			int dimensions = 75; // width and height of the map
			int	maxTunnels = 300; // max number of tunnels possible
			int	maxLength = 35; // max length each tunnel can have
			int currentRow = rand() % 75; // our current row - start at a random spot
			int	currentColumn = rand() % 75; // our current column - start at a random spot
			std::vector<glm::vec2> directions = { glm::vec2(-1, 0),
												glm::vec2(1,0),
												glm::vec2(0,-1),
												glm::vec2(0,1) };// array to get a random direction from (left,right,up,down)
			glm::vec2 lastDirection; // save the last direction we went
			glm::vec2 randomDirection; // next turn/direction - holds a value from directions

		  // lets create some tunnels - while maxTunnels, dimentions, and maxLength  is greater than 0.
		while (maxTunnels) {

			do {
				randomDirection = directions[rand() % directions.size()];
			} while ((randomDirection == -lastDirection));

			int	randomLength = rand() % maxLength; //length the next tunnel will be (max of maxLength)
			int	tunnelLength = 0; //current length of tunnel being created

				// lets loop until our tunnel is long enough or until we hit an edge
			while (tunnelLength < randomLength) {

				//break the loop if it is going out of the map
				if (((currentRow == 0) && (randomDirection.x == -1)) ||
					((currentColumn == 0) && (randomDirection.y == -1)) ||
					((currentRow == dimensions - 1) && (randomDirection.x == 1)) ||
					((currentColumn == dimensions - 1) && (randomDirection.y == 1))) {
					break;
				}
				else {
					road[currentRow][currentColumn] = 1; //set the value of the index in map to 0 (a tunnel, making it one longer)
					currentRow += randomDirection.x; //add the value from randomDirection to row and col (-1, 0, or 1) to update our location
					currentColumn += randomDirection.y;
					tunnelLength++; //the tunnel is now one longer, so lets increment that variable
				}
			}

			if (tunnelLength) { // update our variables unless our last loop broke before we made any part of a tunnel
				lastDirection = randomDirection; //set lastDirection, so we can remember what way we went
				maxTunnels--; // we created a whole tunnel so lets decrement how many we have left to create
			}
		}
		

		for (int i = 0; i < 75;i++)
		{
			for (int j = 0; j < 75; j++)
			{
				if (road[i][j] == 0)
				{
					if (tip_cladire == 0)
					{
						road[i][j] = 5;
					}

					else if (tip_cladire == 1)
					{
						road[i][j] = 6;
					}

					else if (tip_cladire == 2)
					{
						road[i][j] = 7;
					}

					else {
						road[i][j] = 8;
					}
				}
				tip_cladire = rand() % 4;
			}
		}

	
	// Load textures
	
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "crate.jpg").c_str(), GL_REPEAT);
		mapTextures["crate"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "altacladire.png").c_str(), GL_REPEAT);
		mapTextures["altacladire"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "cladire2.png").c_str(), GL_REPEAT);
		mapTextures["cladire2"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "grass.png").c_str(), GL_REPEAT);
		mapTextures["iarbaverde"] = texture;
	}



	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "street2.png").c_str(), GL_REPEAT);
		mapTextures["street2"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "Diffuse_2K.png").c_str(), GL_REPEAT);
		mapTextures["moon"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "ferestre.png").c_str(), GL_REPEAT);
		mapTextures["cladiri"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "modern.png").c_str(), GL_REPEAT);
		mapTextures["cladirimoderne"] = texture;
	}


	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "drumroman.jpg").c_str(), GL_REPEAT);
		mapTextures["alee"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "grass_bilboard.png").c_str(), GL_REPEAT);
		mapTextures["grass"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "COPAC.png").c_str(), GL_REPEAT);
		mapTextures["COPAC"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "business.png").c_str(), GL_REPEAT);
		mapTextures["birouri"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Resources/Models/Vegetation/Bamboo/bamboo.png", GL_REPEAT);
		mapTextures["bamboo"] = texture;
	}

	// Load meshes
	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("acoperit");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "pyramid.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("magazin");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "house_01.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}


	{
		Mesh* mesh = new Mesh("cilindru");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "cylinder.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("sphere");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("moon");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "Moon_2K.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("sphere");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("copacime");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Vegetation/Bamboo", "Tree.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}


	{
		Mesh* mesh = new Mesh("bamboo");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Vegetation/Bamboo/", "bamboo.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	// Create a simple quad
	{
		vector<glm::vec3> vertices
		{
			glm::vec3(1,   0, 1),	// Top Right
			glm::vec3(1,  0, 0),	// Bottom Right
			glm::vec3(-1, 0, 0),	// Bottom Left
			glm::vec3(-1,  0, 1),	// Top Left
		};

		vector<glm::vec3> normals
		{
			glm::vec3(0, 1, 1),
			glm::vec3(1, 0, 1),
			glm::vec3(1, 0, 0),
			glm::vec3(0, 1, 0)
		};

		// TODO : Complete texture coordinates for the square
		vector<glm::vec2> textureCoords
		{	
			glm::vec2(1.0f, 0.0f),
			glm::vec2(1.0f, 1.0f),
			glm::vec2(0.0f, 1.0f),
			glm::vec2(0.0f, 0.0f)
		};

		vector<unsigned short> indices =
		{
			0, 1, 3,
			1, 2, 3
		};

		Mesh* mesh = new Mesh("square");
		mesh->InitFromData(vertices, normals, textureCoords, indices);
		meshes[mesh->GetMeshID()] = mesh;
	}



	// Create a shader program for drawing face polygon with the color of the normal
	{
		Shader *shader = new Shader("ShaderLab9");
		shader->AddShader("Source/Laboratoare/Laborator9/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Laboratoare/Laborator9/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
}

void Laborator9::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);	
}

void Laborator9::Update(float deltaTimeSeconds)
{
	/*
	{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(x, 0, z));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["street2"]);

	}*/


	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 1, 0));
		RenderSimpleMesh(meshes["sphere"], shaders["ShaderLab7"], modelMatrix);
	}

	{
		for (int i = 0; i < 75; i++)
		{
			for (int j = 0; j < 75; j++)
			{
				if (road[i][j] != 0  && road[i][j] != 5 && road[i][j] != 6 && road[i][j] != 7 && road[i][j] != 8)
				{
					glm::mat4 modelMatrix = glm::mat4(1);
					modelMatrix = glm::translate(modelMatrix, glm::vec3(i - 25, 0, j - 25));
					
					RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, 0, mapTextures["street2"]);
				}

			}
		}


		
		
		//
		for (int i = 0; i < 75;i++)
		{
			for (int j = 0; j < 75; j++)
			{
				if (road[i][j] == 5 )
				{
					for (int k = 0; k < inaltime / 2; k += 1)
					{
						{
							glm::mat4 modelMatrix = glm::mat4(1);
							modelMatrix = glm::translate(modelMatrix, glm::vec3(i - 24.5, 0.5f + 0.22*k, j - 24.5));
							//modelMatrix = glm::rotate(modelMatrix, RADIANS(60.0f), glm::vec3(1, 0, 0));
							modelMatrix = glm::scale(modelMatrix, glm::vec3(1 - 0.2*k));
							RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, 0, mapTextures["cladiri"]);
							
						}
					}
					
				}

				else if (road[i][j] == 6 && i%4 == 0)
				{
					for (int k = 0; k < zgarie_nori2 / 2; k += 1)
					{
						{
							glm::mat4 modelMatrix = glm::mat4(1);
							modelMatrix = glm::translate(modelMatrix, glm::vec3(i - 24.5, 0.5f + k, j - 24.5));
							//modelMatrix = glm::rotate(modelMatrix, RADIANS(60.0f), glm::vec3(1, 0, 0));
							modelMatrix = glm::scale(modelMatrix, glm::vec3(1));
							RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, 0, mapTextures["cladire2"]);

						}
					}
				}

				else if (road[i][j] == 7)
				{
					for (int k = 0; k < zgarie_nori / 2; k += 1)
					{
						{
							glm::mat4 modelMatrix = glm::mat4(1);
							modelMatrix = glm::translate(modelMatrix, glm::vec3(i - 24.5, 0.5f + k * 0.2, j - 24.5));
							modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
							modelMatrix = glm::scale(modelMatrix, glm::vec3(0.15 - k*0.005));
							RenderSimpleMesh(meshes["cilindru"], shaders["ShaderLab9"], modelMatrix, 0, mapTextures["birouri"]);

						}
					}
				}

				else if (road[i][j] == 8 && j % 6 == 0 )
				{
					for (int k = 0; k < inaltime /2; k += 1)
					{
						{
							glm::mat4 modelMatrix = glm::mat4(1);
							modelMatrix = glm::translate(modelMatrix, glm::vec3(i - 24.5, 0.5f + k, j - 24.5));
							//modelMatrix = glm::rotate(modelMatrix, RADIANS(60.0f), glm::vec3(1, 0, 0));
							modelMatrix = glm::scale(modelMatrix, glm::vec3(1));
							RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, 0, mapTextures["altacladire"]);

						}
					}
				}

				else if (road[i][j] == 8 && j % 6 != 0)
				{
					for (int k = 0; k < inaltime2 / 2; k += 1)
					{
						{
							glm::mat4 modelMatrix = glm::mat4(1);
							modelMatrix = glm::translate(modelMatrix, glm::vec3(i - 24.5, 0.5f + k*0.5, j - 24.5));
							modelMatrix = glm::rotate(modelMatrix, RADIANS(25*k), glm::vec3(0, 1, 0));
							modelMatrix = glm::scale(modelMatrix, glm::vec3(0.65 - k*0.005));
							RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, 0, mapTextures["cladirimoderne"]);

						}
					}
				}
			}
		}
		
		for (int i = 0; i < 75; i++)
		{
			for (int j = 0; j < 75; j++)
			{
				if (road[i][j] == 8 || road[i][j] == 7 || (road[i][j] == 6 && i % 4 != 0))
				{
					glm::mat4 modelMatrix = glm::mat4(1);
					modelMatrix = glm::translate(modelMatrix, glm::vec3(i - 25, 0.05, j - 25));

					RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, 0, mapTextures["iarbaverde"]);
				}

				{
		
				glm::mat4 modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3(i - 25, 0.025, j - 25));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(0.2f));
				RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, 0, mapTextures["alee"]);
				}

			}
		}


		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(-30, 30, 0));
			//modelMatrix = glm::rotate(modelMatrix, RADIANS(60.0f), glm::vec3(1, 0, 0));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(1));
			RenderSimpleMesh(meshes["moon"], shaders["ShaderLab9"], modelMatrix, 0, mapTextures["moon"]);
		}

		
	}

}

void Laborator9::FrameEnd()
{
	//DrawCoordinatSystem();
}


void Laborator9::RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 & modelMatrix, Texture2D* texture1, Texture2D* texture2)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	int lp = glGetUniformLocation(shader->program, "light_position");
	glUniform3fv(lp, 1, glm::value_ptr(lightPosition));

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	// Bind model matrix
	GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
	glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// Bind view matrix
	glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
	int loc_view_matrix = glGetUniformLocation(shader->program, "View");
	glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// Bind projection matrix
	glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
	int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
	glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	if (texture1)
	{
		//TODO : activate texture location 0
		//TODO : Bind the texture1 ID
		//TODO : Send texture uniform value
		glUniform1i(glGetUniformLocation(shader->program, "textures"), 0);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1->GetTextureID());
		glUniform1i(glGetUniformLocation(shader->program, "texture_1"), 0);
	}

	if (texture2)
	{
		//TODO : activate texture location 1
		//TODO : Bind the texture2 ID
		//TODO : Send texture uniform value
		
		glUniform1i(glGetUniformLocation(shader->program, "textures"), 1);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2->GetTextureID());
		glUniform1i(glGetUniformLocation(shader->program, "texture_2"), 1);
	}

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}

Texture2D* Laborator9::CreateRandomTexture(unsigned int width, unsigned int height)
{
	GLuint textureID = 0;
	unsigned int channels = 3;
	unsigned int size = width * height * channels;
	unsigned char* data = new unsigned char[size];

	for (int i = 0; i < size; i++) {
		data[i] = rand();
	}

	glGenTextures(1, &textureID);
	// TODO: generate random texture data

	glBindTexture(GL_TEXTURE_2D, textureID);
	// Generate and bind the new texture ID

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // modul de wrapping pe orizontala
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // modul de wrapping pe verticala

	// TODO: Set the texture parameters (MIN_FILTER, MAG_FILTER and WRAPPING MODE) using glTexParameteri
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4);

	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	CheckOpenGLError();

	// TODO: Use glTextImage2D to set the texture data
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	// TODO: Generate texture mip-maps
	glGenerateMipmap(GL_TEXTURE_2D);

	CheckOpenGLError();

	// Save the texture into a wrapper Texture2D class for using easier later during rendering phase
	Texture2D* texture = new Texture2D();
	texture->Init(textureID, width, height, channels);

	SAFE_FREE_ARRAY(data);
	return texture;
}

// Documentation for the input functions can be found in: "/Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Laborator9::OnInputUpdate(float deltaTime, int mods)
{
	float speed = 2;

	if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		glm::vec3 up = glm::vec3(0, 1, 0);
		glm::vec3 right = GetSceneCamera()->transform->GetLocalOXVector();
		glm::vec3 forward = GetSceneCamera()->transform->GetLocalOZVector();
		forward = glm::normalize(glm::vec3(forward.x, 0, forward.z));
	}
}

void Laborator9::OnKeyPress(int key, int mods)
{
	// add key press event
}

void Laborator9::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Laborator9::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Laborator9::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Laborator9::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator9::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Laborator9::OnWindowResize(int width, int height)
{
}
