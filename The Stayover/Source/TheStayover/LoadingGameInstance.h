#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LoadingGameInstance.generated.h"


UCLASS()
class THESTAYOVER_API ULoadingGameInstance : public UGameInstance
{
		GENERATED_BODY()

public:
	virtual void Init() override;

	UFUNCTION()
	virtual void BeginLoadingScreen(const FString& MapName);

	UFUNCTION()
	virtual void EndLoadingScreen(UWorld* InLoadedWorld);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loading Screen")
	TSubclassOf<class UUserWidget> LoadingScreenWidget;
};
