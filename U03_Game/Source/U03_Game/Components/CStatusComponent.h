#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatusComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class U03_GAME_API UCStatusComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category = "Speed")
		float SneakSpeed = 200.0f;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float WlakSpeed = 400.0f;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float SprintSpeed = 600.0f;

public:
	FORCEINLINE float GetSneakSpeed() { return SneakSpeed; }
	FORCEINLINE float GetWlakSpeed() { return WlakSpeed; }
	FORCEINLINE float GetSprintSpeed() { return SprintSpeed; }
	FORCEINLINE bool CanMove() { return bCanMove; }

public:
	UCStatusComponent();

	void SetMove();
	void SetStop();

protected:
	virtual void BeginPlay() override;

private:
	bool bCanMove = true;
		
};
