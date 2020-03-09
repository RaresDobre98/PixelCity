#pragma once
#include <Component/SimpleScene.h>
#include <Component/Transform/Transform.h>
#include <Core/GPU/Mesh.h>
#include <math.h>

class Laborator9 : public SimpleScene
{
	public:
		Laborator9();
		~Laborator9();

		void Init() override;

	private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix, Texture2D* texture1 = NULL, Texture2D* texture2 = NULL);
		
		Texture2D* CreateRandomTexture(unsigned int width, unsigned int height);
		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;
		void createMap();
		std::unordered_map<std::string, Texture2D*> mapTextures;
		GLuint randomTextureID;


		int inaltime = 4 + (rand() % 9);
		int inaltime2 = 4 + (rand() % 9);
		int road[100][100];
		int ocupat[100][100];
		int ocupat_blocuri[100][100];
		int ocupat_birouri[100][100];
;

		int raritate_birouri ;
		int aparitie_blocuri;

		int zgarie_nori = 5 + (rand() % 12);

		int cladire_birouri = 4 + (rand() % 8);
		int zgarie_nori2 = 5 + (rand() % 12);


		glm::vec3 lightPosition;
		unsigned int materialShininess;
		float materialKd;
		float materialKs;

		int tip_cladire;

		
};
