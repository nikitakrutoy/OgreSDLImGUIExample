#include "framework.h"
#include "GameEnginesLecture1.h"

#include "OgreGraphicsFramework.h"
#include <backends/imgui_impl_sdl.h>
#include <backends/imgui_impl_opengl3.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    OgreGraphicsFramework ogreGraphicsFramework;

    while (!ogreGraphicsFramework.GetQuit()) {
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			ImGui_ImplSDL2_ProcessEvent(&event);

			switch (event.type)
			{
			case SDL_QUIT:
				ogreGraphicsFramework.Cleanup();
				exit(0);
				break;

			case SDL_MOUSEBUTTONDOWN:
				int x, y;
				SDL_GetMouseState(&x, &y);
				Ogre::LogManager::getSingleton().logMessage(Ogre::String(std::to_string(x) + " " + std::to_string(y) + "\n"));
				break;

			default:
				break;
			}

			ogreGraphicsFramework.update();
		}
    }


    return 0;
}