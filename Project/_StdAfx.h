#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )

#ifdef _DEBUG
#pragma comment(linker,"/entry:wWinMainCRTStartup /subsystem:console")
#endif

#include <iostream>
using namespace std;

#include "Utils.h"
#include "Texture.h"

#include "Input.h"

#include "IGameObject.h"
#include "GameObject.h"

#include "AnimationObject.h"

#include "SceneObject.h"
#include "SceneManager.h"

#include "SceneIntro.h"

#include "D3DApp.h"
#include "Game.h"