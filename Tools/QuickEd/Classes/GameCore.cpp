#include "GameCore.h"

#include "FileSystem/FileSystem.h"
#include "UI/UIControlSystem.h"

#include "Grid/GridVisualizer.h"

//#include "ScreenManager.h"
#include "Helpers/ResourcesManageHelper.h"
#include "FileSystem/ResourceArchive.h"
#include "Version.h"

#ifdef __DAVAENGINE_AUTOTESTING__
#include "Autotesting/AutotestingSystem.h"
#endif

#include "UI/Layouts/UILayoutSystem.h"

#include <QString>

using namespace DAVA;

GameCore::GameCore()
{
    new GridVisualizer();

#ifdef __DAVAENGINE_AUTOTESTING__
    new AutotestingSystem();
#endif

    // Unpack the help data, if needed.
    UnpackHelp();

    //Initialize internal resources of application
    ResourcesManageHelper::InitInternalResources();
    UIControlSystem::Instance()->GetLayoutSystem()->SetAutoupdatesEnabled(false);
}

GameCore::~GameCore()
{
    GridVisualizer::Instance()->Release();

#ifdef __DAVAENGINE_AUTOTESTING__
    AutotestingSystem::Instance()->Release();
#endif
}

void GameCore::OnAppStarted()
{
    Renderer::SetDesiredFPS(60);
}

void GameCore::OnAppFinished()
{
}

void GameCore::OnSuspend()
{
    ApplicationCore::OnSuspend();
}

void GameCore::OnResume()
{
    ApplicationCore::OnResume();
}

void GameCore::OnBackground()
{
}

void GameCore::BeginFrame()
{
    ApplicationCore::BeginFrame();
}

void GameCore::Update(float32 timeElapsed)
{
    ApplicationCore::Update(timeElapsed);
}

void GameCore::Draw()
{
    ApplicationCore::Draw();
}

void GameCore::UnpackHelp()
{
    //Unpack Help to Documents.
    FilePath docsPath = FilePath(ResourcesManageHelper::GetDocumentationPath().toStdString());
    if (!FileSystem::Instance()->Exists(docsPath))
    {
        try
        {
            ResourceArchive helpRA("~res:/Help.docs");

            FileSystem::Instance()->DeleteDirectory(docsPath);
            FileSystem::Instance()->CreateDirectory(docsPath, true);

            helpRA.UnpackToFolder(docsPath);
        }
        catch (std::exception& ex)
        {
            Logger::Error("%s", ex.what());
            DVASSERT(false && "can't unpack help docs to documents dir");
        }
    }
}
