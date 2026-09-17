#include "LoadingGameInstance.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Slate.h"
#include "MoviePlayer.h"

void ULoadingGameInstance::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &ULoadingGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &ULoadingGameInstance::EndLoadingScreen);
}

void ULoadingGameInstance::BeginLoadingScreen(const FString& InMapName)
{
	
	if (!GetMoviePlayer()->IsMovieCurrentlyPlaying())
	{
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;

		UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenWidget);
		LoadingScreen.WidgetLoadingScreen = Widget->TakeWidget();

		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}
	
	
}

void ULoadingGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{

}