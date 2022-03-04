#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Components/CActionComponent.h"
#include "CBTTaskNode_Change.generated.h"

UCLASS()
class U03_GAME_API UCBTTaskNode_Change : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UCBTTaskNode_Change();
private:
	UPROPERTY(EditAnywhere)
		EActionType Type;


protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;


};
