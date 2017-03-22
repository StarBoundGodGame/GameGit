#pragma once

#ifdef _DEBUG
#pragma comment(linker,"/entry:wWinMainCRTStartup /subsystem:console")
#endif

#include <iostream>
using namespace std;

#include <d3d9.h>
#include <d3dx9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )

#include "Input.h"
#include "Utils.h"
#include "Texture.h"

#include "IGameObject.h"
#include "GameObject.h"

#include "SceneObject.h"
#include "SceneManager.h"

#include "D3DApp.h"
#include "Game.h"
