#pragma once
#include "BCE/Base/GameState.h"
#include "BCE/Base/GameStateManager.h"
#include "BCE/Graphic/Mesh.h"
#include "BCE/Graphic/Shader.h"
#include "BCE/Graphic/Camera.h"
#include "BCE/Graphic/CubeModel.h"
#include "BCE/Graphic/PlaneModel.h"
#include "BCE/Base/ShaderManager.h"
#include<vector>
class Menu : public GameState
{
private:
	Platform* platform;
	GameStateManager* manager;
	ShaderManager* shaderManager;
	Camera camera;
	CubeModel *cube;
	PlaneModel* plane;
public:
	Menu();
	~Menu();
	void Init() override;
	void Draw() override;
	bool Input(std::map<int, bool> keys) override;
	bool MouseInput(int x, int y, bool leftbutton);
	void Update() override;
	void Close() override;

};