#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatusComponent.generated.h"

UENUM(BlueprintType)
enum class ECharacterSpeed: uint8
{
	Sneak, Walk, Sprint, Max
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class U03_GAME_API UCStatusComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Health")
		float MaxHealth = 100.f;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float Speed[(int)ECharacterSpeed::Max] = { 200.f, 400.0f, 600.0f };


public:
	FORCEINLINE float GetMaxHealth() { return MaxHealth; }
	FORCEINLINE float GetHealth() { return Health; }

	FORCEINLINE float GetSneakSpeed() { return Speed[(int)ECharacterSpeed::Sneak]; }
	FORCEINLINE float GetWalkSpeed() { return Speed[(int)ECharacterSpeed::Walk]; }
	FORCEINLINE float GetSprintSpeed() { return Speed[(int)ECharacterSpeed::Sprint]; }

	FORCEINLINE bool CanMove() { return bCanMove; }

public:	
	UCStatusComponent();

	void AddHealth(float InAmount);
	void SubHealth(float InAmount);

	void SetSpeed(ECharacterSpeed InSpeed);

	void SetMove();
	void SetStop();

protected:
	virtual void BeginPlay() override;


private:
	float Health;

	bool bCanMove = true;
		
};
