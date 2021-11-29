#pragma once

#include "Ogre.h"
#include "OgreRoot.h"
#include "OgreWindow.h"
#include "OgreItem.h"
#include "OgreMeshManager2.h"
#include "OgreMesh2.h"

#include "Compositor/OgreCompositorManager2.h"

#include "OgreHlms.h"
#include "Hlms/Unlit/OgreHlmsUnlit.h"
#include "Hlms/Pbs/OgreHlmsPbs.h"

#include "SDL.h"

#include "RenderSystems/Direct3D11/OgreD3D11Plugin.h"
#include "RenderSystems/GL3Plus/OgreGL3PlusPlugin.h"

class OgreGraphicsFramework
{
public:
	OgreGraphicsFramework();
	~OgreGraphicsFramework();

	void update();

	void InitSDL();

	bool SetOgreConfig();

	bool GetQuit() { return m_bQuit; }
	void SetQuit(bool bQuit) { m_bQuit = bQuit; }
	void Cleanup();

private:
	Ogre::Root* m_pRoot;
	Ogre::Window* m_pRenderWindow;
	Ogre::SceneManager* m_pSceneManager;
	Ogre::Camera* m_pCamera;
	Ogre::CompositorWorkspace* m_pWorkspace;
	Ogre::D3D11Plugin* m_pD3D11Plugin;
	Ogre::GL3PlusPlugin* m_pGL3PlusPlugin;
	SDL_Window* m_SDL_Window;
	SDL_GLContext m_GL_Context;

	bool m_bQuit;
};

