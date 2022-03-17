#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CFeetComponent.generated.h"

USTRUCT(BlueprintType)
struct FFeetData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FVector LeftDistance;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FVector RightDistance;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FVector PelvisDistance;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FRotator LeftRotation;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FRotator RightRotation;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class U03_GAME_API UCFeetComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "InverseKinemetics")
		FName LeftSocket = "Foot_L";
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "InverseKinemetics")
		FName RightSocket = "Foot_R";
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "InverseKinemetics")
		float TraceDistance = 55.0f;

public:
	FORCEINLINE const FFeetData& GetData() { return Data; }
public:	
	UCFeetComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void Trace(FName InSocket, float& OutDistance);

private:
	FFeetData Data;

	class ACharacter* OwnerCharacter;
	float CapsuleHalfHeight;
};
